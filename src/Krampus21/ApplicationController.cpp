

#include <Krampus21/ApplicationController.hpp>
#include <stdexcept>
#include <sstream>
#include <AllegroFlare/UsefulPHP.hpp>
#include <Blast/FileExistenceChecker.hpp>
#include <Krampus21/DialogFactory.hpp>
#include <stdexcept>
#include <sstream>
#include <Krampus21/DialogBoxRenderer.hpp>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>
#include <Blast/String/Trimmer.hpp>
#include <iostream>
#include <Blast/String/Trimmer.hpp>
#include <Blast/StringSplitter.hpp>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{


ApplicationController::ApplicationController(AllegroFlare::Framework* framework, AllegroFlare::Screens* screens, std::map<std::string, AllegroFlare::AudioRepositoryElement> sound_effect_elements, std::map<std::string, AllegroFlare::AudioRepositoryElement> music_track_elements)
   : AllegroFlare::Screen()
   , framework(framework)
   , screens(screens)
   , sound_effect_elements(sound_effect_elements)
   , music_track_elements(music_track_elements)
   , user_event_emitter_souce({})
   , user_event_emitter({})
   , audio_controller(&framework->get_sample_bin_ref(), sound_effect_elements, music_track_elements)
   , current_dialog(nullptr)
   , character({})
   , initialized(false)
   , script()
   , dialog_factory({})
{
}


ApplicationController::~ApplicationController()
{
}


Krampus21::DialogBoxes::Base* ApplicationController::get_current_dialog()
{
   return current_dialog;
}


void ApplicationController::initialize()
{
   if (!((!initialized)))
      {
         std::stringstream error_message;
         error_message << "ApplicationController" << "::" << "initialize" << ": error: " << "guard \"(!initialized)\" not met";
         throw std::runtime_error(error_message.str());
      }
   audio_controller.initialize();
   character.set_font_bin(obtain_font_bin());
   character.set_bitmap_bin(obtain_bitmap_bin());
   initialized = true;
   return;
}

bool ApplicationController::load_script(std::string filename)
{
   if (!Blast::FileExistenceChecker(filename).exists())
   {
      std::cout << "ApplicationController::load_script: file \"" << filename
                << "\" does not exist and could not be loaded." << std::endl;
      return false;
   }
   std::vector<std::string> script_lines = AllegroFlare::php::file_get_contents_split(filename);
   script = Krampus21::Script(script_lines);
   script.initialize();
   return true;
}

void ApplicationController::advance()
{
   script.goto_next_line();
   play_current_script_line();
   // if it's a dialog and the dialog is finished, play the next script line
   //if (current_dialog) current_dialog->
   return;
}

void ApplicationController::play_current_script_line()
{
   bool continue_directly_to_next_script_line = false;
   int continue_count = 0;

   do
   {
      std::string script_line = script.get_current_line_text();
      continue_directly_to_next_script_line = parse_and_run_line(script_line);

      if (continue_directly_to_next_script_line)
      {
         script.goto_next_line();
         continue_count++;
      }
      if (continue_count > 500)
      {
         continue_directly_to_next_script_line = false;
         std::cout << "ApplicationController::play_current_script_line: continued unstopped playing more than "
                   << "500 script lines without a stop. Assuming error and halting to avoid infinite loop.";
      }
   } while (continue_directly_to_next_script_line);
}

void ApplicationController::start_game()
{
   play_current_script_line();
   return;
}

void ApplicationController::shutdown_game()
{
   if (!(framework))
      {
         std::stringstream error_message;
         error_message << "ApplicationController" << "::" << "shutdown_game" << ": error: " << "guard \"framework\" not met";
         throw std::runtime_error(error_message.str());
      }
   framework->shutdown_program = true;
   return;
}

bool ApplicationController::dialog_is_finished()
{
   if (!current_dialog) return true;
   return current_dialog->get_finished();
}

void ApplicationController::primary_timer_func()
{
   al_clear_to_color(ALLEGRO_COLOR{0, 0, 0, 0});
   if (current_dialog) current_dialog->update();
   //if (dialog_is_finished())
   //{
   //}
   if (script.get_finished())
   {
      ALLEGRO_FONT* font = obtain_dialog_font();
      std::string script_finished_text = "GAME OVER";
      al_draw_text(
         font,
         ALLEGRO_COLOR{0.1,0.1,0.1,0.1},
         1920/2,
         1080/2-20-al_get_font_line_height(font),
         ALLEGRO_ALIGN_CENTER,
         script_finished_text.c_str()
      );
   }
   else
   {
      character.render();
      if (current_dialog)
      {
         Krampus21::DialogBoxRenderer renderer(obtain_font_bin(), current_dialog);
         renderer.render();
      }
   }
   return;
}

void ApplicationController::key_down_func(ALLEGRO_EVENT* ev)
{
   switch (ev->type)
   {
   case ALLEGRO_EVENT_KEY_DOWN:
      switch(ev->keyboard.keycode)
      {
         case ALLEGRO_KEY_ESCAPE:
            shutdown_game();
            break;
         case ALLEGRO_KEY_SPACE:
            advance();
            break;
         case ALLEGRO_KEY_UP:
         case ALLEGRO_KEY_K:
            // TODO move cursor up
            break;
         case ALLEGRO_KEY_DOWN:
         case ALLEGRO_KEY_J:
            // TODO move cursor down
            break;
         case ALLEGRO_KEY_ENTER:
            // TODO submit dialog
            break;
      }
      break;
   }
   return;
}

void ApplicationController::joy_button_down_func(ALLEGRO_EVENT* ev)
{
   switch (ev->joystick.button)
   {
   case 4:
      shutdown_game();
      break;
   case 1:
      advance();
      break;
   }
   return;
}

void ApplicationController::joy_axis_func(ALLEGRO_EVENT* ev)
{
   static float joystick_0_y_state = 0.0;
   static float joystick_1_y_state = 0.0;
   static float joystick_2_y_state = 0.0;

   switch (ev->joystick.stick)
   {
   case 0: // left most stick
      if (ev->joystick.axis == 1) // the up/down axis
      {
         float new_joystick_0_y_state = ev->joystick.pos;
         if (joystick_0_y_state < 0.5 && new_joystick_0_y_state >= 0.5)
         {
            // move cursor down
            // TODO move cursor down
            std::cout << "CURSOR DOWN" << std::endl;
         }
         else if (joystick_0_y_state > -0.5 && new_joystick_0_y_state <= -0.5)
         {
            // move cursor up
            // TODO move cursor down
            std::cout << "CURSOR UP" << std::endl;
         }
         joystick_0_y_state = new_joystick_0_y_state;
      }
      break;
   case 1:
      break;
   case 2: // the hat
      break;
   }
   return;
}

void ApplicationController::user_event_func(ALLEGRO_EVENT* ev)
{
   return;
}

AllegroFlare::FontBin* ApplicationController::obtain_font_bin()
{
   if (!(framework))
      {
         std::stringstream error_message;
         error_message << "ApplicationController" << "::" << "obtain_font_bin" << ": error: " << "guard \"framework\" not met";
         throw std::runtime_error(error_message.str());
      }
   return &framework->get_font_bin_ref();
}

AllegroFlare::BitmapBin* ApplicationController::obtain_bitmap_bin()
{
   if (!(framework))
      {
         std::stringstream error_message;
         error_message << "ApplicationController" << "::" << "obtain_bitmap_bin" << ": error: " << "guard \"framework\" not met";
         throw std::runtime_error(error_message.str());
      }
   return &framework->get_bitmap_bin_ref();
}

bool ApplicationController::parse_and_run_line(std::string script_line)
{
   std::string DIALOG = "DIALOG";
   std::string GOTO = "GOTO";
   std::string CHOICE = "CHOICE";
   std::string PLAY_MUSIC = "PLAY_MUSIC";
   std::string MARKER = "MARKER";
   std::string SET_CHARACTER_ART = "SET_CHARACTER_ART";

   bool continue_directly_to_next_script_line = false;
   Krampus21::DialogBoxes::Base* created_dialog = nullptr;
   std::pair<std::string, std::string> command_and_argument = parse_command_and_argument(script_line);
   std::string command = command_and_argument.first;
   std::string argument = command_and_argument.second;

   if (command.empty() || command == DIALOG)
   {
      if (script_line.empty())
      {
         continue_directly_to_next_script_line = true;
      }
      else
      {
         created_dialog = dialog_factory.create_basic_dialog(std::vector<std::string>{script_line});
      }
   }
   else if (command == CHOICE)
   {
      std::string choice_prompt = "[coice-prompt-text-not-extracted]";
      std::vector<std::pair<std::string, std::string>> choice_options = {};

      // tokenize
      std::vector<std::string> tokens = tokenize(argument);

      // validate
      // expect at least 3 tokens
      assert_min_token_count(tokens, 3);
      // expect an odd number of tokens
      assert_odd_token_count(tokens);

      // first token is the prompt
      choice_prompt = tokens[0];
      // next consecutive tokens are (choice_text, choice_value) pairs
      for (unsigned i=2; i<tokens.size(); i+=2)
      {
         // TODO warning if token is empty
         choice_options.push_back({ tokens[i-1], tokens[i] });
      }

      //choice_options = { { "Boobar", "boobruhh" }, { "Zoozaz", "zazzle" } };
      created_dialog = dialog_factory.create_choice_dialog(choice_prompt, choice_options);
   }
   else if (command == PLAY_MUSIC)
   {
      std::string identifier = "etherial-ambience-01.wav";
      audio_controller.play_music_track_by_identifier(identifier);
      continue_directly_to_next_script_line = true;
   }
   else if (command == SET_CHARACTER_ART)
   {
      character.set_sprite_record_identifier(argument);
      continue_directly_to_next_script_line = true;
   }
   else if (command == MARKER)
   {
      continue_directly_to_next_script_line = true;
   }
   else if (command == GOTO)
   {
      script.goto_marker(argument);
      continue_directly_to_next_script_line = true;
   }
   else
   {
      std::cout << "WARNING: Unrecognized command \"" << command << "\"" << std::endl;
      continue_directly_to_next_script_line = true;
   }

   if (created_dialog)
   {
      if (current_dialog) delete current_dialog;
      current_dialog = created_dialog;
   }

   return continue_directly_to_next_script_line;
}

std::pair<std::string, std::string> ApplicationController::parse_command_and_argument(std::string script_line)
{
   std::pair<std::string, std::string> result{"", ""};
   std::string DELIMETER = ": ";

   std::size_t pos = script_line.find(DELIMETER);

   if (pos == std::string::npos)
   {
      result.first = "DIALOG";
      result.second = Blast::String::Trimmer(script_line).trim();
   }
   else
   {
      std::string command_fragment_unsanitized = script_line.substr(0, pos);

      // TODO validate format of command (all caps, underscore, no spaces)
      // here

      result.first = Blast::String::Trimmer(command_fragment_unsanitized).trim();
      result.second = Blast::String::Trimmer(script_line.substr(pos+DELIMETER.size())).trim();
   }

   return result;
}

std::map<std::string, int> ApplicationController::build_markers_index(std::vector<std::string> script_lines)
{
   std::map<std::string, int> result;
   for (unsigned i=0; i<script_lines.size(); i++)
   {
      std::string script_line = script_lines[i];
      std::pair<std::string, std::string> command_and_argument = parse_command_and_argument(script_line);
      std::string command = command_and_argument.first;
      std::string argument = command_and_argument.second;
      int line_num = i+1;

      if (command == "MARKER")
      {
         // TODO ensure symbols don't appear multiple times
         if (result.find(argument) != result.end())
         {
            std::cout << "Krampus21/ApplicationController::build_markers_index: WARNING: the marker "
                      << "\"" << argument << "\""
                      << "is being set on line " << line_num
                      << " but was already declared earlier on line " << result[argument] << ". "
                      << "Note that the marker will be overwritten to this new line number ("
                      << line_num << ").";
         }

         result[argument] = line_num;
      }
   }
   return result;
}

std::vector<std::string> ApplicationController::tokenize(std::string str, char delim)
{
   std::vector<std::string> tokens = Blast::StringSplitter(str, delim).split();
   for (auto &token : tokens) token = Blast::String::Trimmer(token).trim();
   return tokens;
}

bool ApplicationController::assert_min_token_count(std::vector<std::string> tokens, int min)
{
   return (tokens.size() >= min);
}

bool ApplicationController::assert_odd_token_count(std::vector<std::string> tokens, int min)
{
   return (tokens.size() % 2);
}

ALLEGRO_FONT* ApplicationController::obtain_dialog_font()
{
   if (!(al_is_font_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "ApplicationController" << "::" << "obtain_dialog_font" << ": error: " << "guard \"al_is_font_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(al_is_ttf_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "ApplicationController" << "::" << "obtain_dialog_font" << ": error: " << "guard \"al_is_ttf_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   static const std::string FONT_IDENTIFIER = "Purista Medium.ttf -50";
   ALLEGRO_FONT* result_font = obtain_font_bin()->operator[](FONT_IDENTIFIER);
   return result_font;
}
} // namespace Krampus21


