

#include <Krampus21/ScreenManager.hpp>
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
#include <Blast/String/Trimmer.hpp>
#include <iostream>
#include <Blast/String/Trimmer.hpp>
#include <Blast/StringSplitter.hpp>
#include <vector>
#include <string>


namespace Krampus21
{


ScreenManager::ScreenManager(AllegroFlare::Framework* framework, AllegroFlare::Screens* screens, std::map<std::string, AllegroFlare::AudioRepositoryElement> sound_effect_elements, std::map<std::string, AllegroFlare::AudioRepositoryElement> music_track_elements)
   : AllegroFlare::Screen()
   , framework(framework)
   , screens(screens)
   , sound_effect_elements(sound_effect_elements)
   , music_track_elements(music_track_elements)
   , user_event_emitter_souce({})
   , user_event_emitter({})
   , audio_controller(&framework->get_sample_bin_ref(), sound_effect_elements, music_track_elements)
   , current_dialog(nullptr)
   , initialized(false)
   , script()
   , dialog_factory({})
{
}


ScreenManager::~ScreenManager()
{
}


void ScreenManager::initialize()
{
   if (!((!initialized)))
      {
         std::stringstream error_message;
         error_message << "ScreenManager" << "::" << "initialize" << ": error: " << "guard \"(!initialized)\" not met";
         throw std::runtime_error(error_message.str());
      }
   audio_controller.initialize();
   initialized = true;
   return;
}

bool ScreenManager::load_script(std::string filename)
{
   if (!Blast::FileExistenceChecker(filename).exists())
   {
      std::cout << "ScreenManager::load_script: file \"" << filename
                << "\" does not exist and could not be loaded." << std::endl;
      return false;
   }
   std::vector<std::string> script_lines = AllegroFlare::php::file_get_contents_split(filename);
   script = Krampus21::Script(script_lines);
   script.initialize();
   return true;
}

void ScreenManager::advance()
{
   script.goto_next_line();
   play_current_script_line();
   // if it's a dialog and the dialog is finished, play the next script line
   //if (current_dialog) current_dialog->
   return;
}

bool ScreenManager::play_current_script_line()
{
   //if (script->at_valid_line())
   std::string script_line_text = script.get_current_line_text();
   Krampus21::DialogBoxes::Base *created_dialog = parse_line_and_create_dialog(script_line_text);
   if (created_dialog)
   {
      if (current_dialog) delete current_dialog;
      current_dialog = created_dialog;
   }
   return true;
}

void ScreenManager::start_game()
{
   play_current_script_line();
   play_music_track("etherial-ambience-01.wav");
   return;
}

void ScreenManager::shutdown_game()
{
   if (!(framework))
      {
         std::stringstream error_message;
         error_message << "ScreenManager" << "::" << "shutdown_game" << ": error: " << "guard \"framework\" not met";
         throw std::runtime_error(error_message.str());
      }
   framework->shutdown_program = true;
   return;
}

void ScreenManager::update_dialog()
{
   if (current_dialog) current_dialog->update();
   return;
}

bool ScreenManager::dialog_is_finished()
{
   if (!current_dialog) return true;
   return current_dialog->get_finished();
}

void ScreenManager::primary_timer_func()
{
   al_clear_to_color(ALLEGRO_COLOR{0, 0, 0, 0});
   update_dialog();
   if (dialog_is_finished())
   {
   }
   else if (current_dialog)
   {
      Krampus21::DialogBoxRenderer renderer(obtain_font_bin(), current_dialog);
      renderer.render();
   }
   return;
}

void ScreenManager::play_music_track(std::string identifier)
{
   audio_controller.play_music_track_by_identifier(identifier);
   return;
}

void ScreenManager::key_down_func(ALLEGRO_EVENT* ev)
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

void ScreenManager::joy_button_down_func(ALLEGRO_EVENT* ev)
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

void ScreenManager::joy_axis_func(ALLEGRO_EVENT* ev)
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

void ScreenManager::user_event_func(ALLEGRO_EVENT* ev)
{
   return;
}

AllegroFlare::FontBin* ScreenManager::obtain_font_bin()
{
   if (!(framework))
      {
         std::stringstream error_message;
         error_message << "ScreenManager" << "::" << "obtain_font_bin" << ": error: " << "guard \"framework\" not met";
         throw std::runtime_error(error_message.str());
      }
   return &framework->get_font_bin_ref();
}

Krampus21::DialogBoxes::Base* ScreenManager::parse_line_and_create_dialog(std::string script_line)
{
   std::string DIALOG = "DIALOG";
   std::string CHOICE = "CHOICE";
   Krampus21::DialogBoxes::Base* created_dialog = nullptr;
   std::pair<std::string, std::string> command_and_argument = parse_command_and_argument(script_line);
   std::string command = command_and_argument.first;
   std::string argument = command_and_argument.second;

   if (command.empty() || command == DIALOG)
   {
      created_dialog = dialog_factory.create_basic_dialog(std::vector<std::string>{script_line});
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

   return created_dialog;
}

std::pair<std::string, std::string> ScreenManager::parse_command_and_argument(std::string script_line)
{
   std::pair<std::string, std::string> result{"", ""};
   std::string DELIMETER = ": ";

   std::size_t pos = script_line.find(DELIMETER);

   if (pos == std::string::npos)
   {
      result.first = "DIALOG";
      result.second = script_line;
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

std::map<std::string, int> ScreenManager::build_markers_index(std::vector<std::string> script_lines)
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
            std::cout << "Krampus21/ScreenManager::build_markers_index: WARNING: the marker "
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

std::vector<std::string> ScreenManager::tokenize(std::string str, char delim)
{
   std::vector<std::string> tokens = Blast::StringSplitter(str, delim).split();
   for (auto &token : tokens) token = Blast::String::Trimmer(token).trim();
   return tokens;
}

bool ScreenManager::assert_min_token_count(std::vector<std::string> tokens, int min)
{
   return (tokens.size() >= min);
}

bool ScreenManager::assert_odd_token_count(std::vector<std::string> tokens, int min)
{
   return (tokens.size() % 2);
}
} // namespace Krampus21


