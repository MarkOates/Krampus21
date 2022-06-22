

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
#include <Krampus21/BackgroundFactory.hpp>
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


ApplicationController::ApplicationController(AllegroFlare::Framework* framework, AllegroFlare::ScreenManager* screens, std::map<std::string, AllegroFlare::AudioRepositoryElement> sound_effect_elements, std::map<std::string, AllegroFlare::AudioRepositoryElement> music_track_elements)
   : AllegroFlare::Screen()
   , framework(framework)
   , screens(screens)
   , sound_effect_elements(sound_effect_elements)
   , music_track_elements(music_track_elements)
   , user_event_emitter_souce({})
   , user_event_emitter({})
   , audio_controller(&framework->get_sample_bin_ref(), sound_effect_elements, music_track_elements)
   , current_dialog(nullptr)
   , current_background(nullptr)
   , character({})
   , initialized(false)
   , script()
   , dialog_factory({})
   , background_color(ALLEGRO_COLOR{0.05, 0.05, 0.05, 1.0})
   , letterbox_frame_height(160)
   , letterbox_color(ALLEGRO_COLOR{0.0, 0.0, 0.0, 1.0})
   , af_inventory({})
   , flags({})
   , inventory({})
   , script_freshly_loaded_via_OPENSCRIPT(false)
   , showing_smart_phone(false)
   , smart_phone_reveal_counter(0.0f)
   , image_identifier_for_smart_phone("bestie-on-phone-01.png")
   , wait_delay_countdown_sec(0.0f)
   , on_hold_for_wait_delay(false)
{
}


ApplicationController::~ApplicationController()
{
}


void ApplicationController::set_script_freshly_loaded_via_OPENSCRIPT(bool script_freshly_loaded_via_OPENSCRIPT)
{
   this->script_freshly_loaded_via_OPENSCRIPT = script_freshly_loaded_via_OPENSCRIPT;
}


Krampus21::DialogBoxes::Base* ApplicationController::get_current_dialog()
{
   return current_dialog;
}


Krampus21::Backgrounds::Base* ApplicationController::get_current_background()
{
   return current_background;
}


bool ApplicationController::get_script_freshly_loaded_via_OPENSCRIPT()
{
   return script_freshly_loaded_via_OPENSCRIPT;
}


std::string ApplicationController::get_image_identifier_for_smart_phone()
{
   return image_identifier_for_smart_phone;
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

   inventory.set_font_bin(obtain_font_bin());
   inventory.set_bitmap_bin(obtain_bitmap_bin());
   inventory.set_af_inventory(&af_inventory);
   //af_inventory.add_item(1);
   //af_inventory.add_item(2);

   initialized = true;
   return;
}

bool ApplicationController::load_script_lines(std::vector<std::string> script_lines)
{
   script = Krampus21::Script(script_lines);
   script.initialize();
   return true;
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
   return load_script_lines(script_lines);
}

void ApplicationController::advance()
{
   if (on_hold_for_wait_delay) return; // do not allow any user input until the wait delay is lower

   // if dialog box is "choice", eval the choice, then ...
   if (current_dialog && current_dialog->is_type("Choice"))
   {
      Krampus21::DialogBoxes::Choice* choice_dialog_box =
         static_cast<Krampus21::DialogBoxes::Choice*>(current_dialog);
      std::string selected_choice_value = choice_dialog_box->get_current_selection_value();
      int script_current_line_num = script.get_current_line_num();
      delete current_dialog;
      current_dialog = nullptr;

      parse_and_run_line(selected_choice_value, script_current_line_num);
   }

   script.goto_next_line();
   if (!script.get_finished())  play_current_script_line();

   return;
}

void ApplicationController::handle_cursor_up_input()
{
   if (inventory.get_active())
   {
      inventory.move_cursor_up();
   }
   else if (current_dialog && current_dialog->is_type("Choice"))
   {
      Krampus21::DialogBoxes::Choice* choice_dialog_box =
         static_cast<Krampus21::DialogBoxes::Choice*>(current_dialog);
      choice_dialog_box->move_cursor_position_up();
   }
   return;
}

void ApplicationController::handle_cursor_down_input()
{
   if (inventory.get_active())
   {
      inventory.move_cursor_down();
   }
   else if (current_dialog && current_dialog->is_type("Choice"))
   {
      Krampus21::DialogBoxes::Choice* choice_dialog_box =
         static_cast<Krampus21::DialogBoxes::Choice*>(current_dialog);
      choice_dialog_box->move_cursor_position_down();
   }
   return;
}

void ApplicationController::handle_cursor_left_input()
{
   if (inventory.get_active())
   {
      inventory.move_cursor_left();
   }
   return;
}

void ApplicationController::handle_cursor_right_input()
{
   if (inventory.get_active())
   {
      inventory.move_cursor_right();
   }
   return;
}

void ApplicationController::handle_submit_input()
{
   if (inventory.get_active())
   {
      // do nothing
   }
   else
   {
      advance();
   }
   return;
}

void ApplicationController::handle_cancel_input()
{
   shutdown_game();
   return;
}

void ApplicationController::handle_option_input()
{
   toggle_inventory();
   return;
}

void ApplicationController::play_current_script_line()
{
   bool continue_directly_to_next_script_line = false;
   int continue_count = 0;

   do
   {
      std::string script_line = script.get_current_line_text();
      int script_current_line_num = script.get_current_line_num();
      continue_directly_to_next_script_line = parse_and_run_line(script_line, script_current_line_num);

      if (continue_directly_to_next_script_line)
      {
         if (!get_script_freshly_loaded_via_OPENSCRIPT())
         {
            script.goto_next_line();
         }
         else
         {
            set_script_freshly_loaded_via_OPENSCRIPT(false);
         }
         if (script.get_finished()) break;
         continue_count++;
      }
      if (continue_count > 500)
      {
         continue_directly_to_next_script_line = false;
         std::cout << "ApplicationController::play_current_script_line: continued unstopped playing more than "
                   << "500 script lines without a stop. Assuming error and halting to avoid infinite loop."
                   << " That line was \"" << script_line << "\" which is on line ["
                   << script_current_line_num << "]" << std::endl;
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

void ApplicationController::open_inventory()
{
   if (!inventory.get_active()) inventory.show();
   return;
}

void ApplicationController::close_inventory()
{
   if (inventory.get_active()) inventory.hide();
   return;
}

void ApplicationController::toggle_inventory()
{
   if (inventory.get_active()) close_inventory();
   else open_inventory();
   return;
}

void ApplicationController::primary_timer_func()
{
   if (on_hold_for_wait_delay)
   {
      wait_delay_countdown_sec -= (1.0/60.0f);
      if (wait_delay_countdown_sec <= 0.0)
      {
         on_hold_for_wait_delay = false;
         script.goto_next_line();
         play_current_script_line();
      }
   }

   // update
   inventory.update();
   if (current_dialog) current_dialog->update();
   update_smart_phone();
   if (current_background) current_background->managed_update();

   // draw
   if (script.get_finished())
   {
      al_clear_to_color(ALLEGRO_COLOR{0, 0, 0, 0});

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
      // clear to the background color
      al_clear_to_color(background_color);

      // render background
      if (current_background) current_background->draw();

      // render character
      character.render();

      // render smartphone
      draw_smart_phone();

      // render letterbox
      draw_letterbox();

      // render dialog
      if (current_dialog)
      {
         Krampus21::DialogBoxRenderer renderer(obtain_font_bin(), obtain_bitmap_bin(), current_dialog);
         renderer.render();
      }

      // render inventory
      inventory.render();
   }

   al_flip_display();
   return;
}

void ApplicationController::draw_letterbox()
{
   al_draw_filled_rectangle(0, 0, 1920, letterbox_frame_height, letterbox_color);
   al_draw_filled_rectangle(0, 1080-letterbox_frame_height, 1920, 1080, letterbox_color);
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
            handle_cancel_input();
            break;
         case ALLEGRO_KEY_SPACE:
         case ALLEGRO_KEY_ENTER:
            handle_submit_input();
            break;
         case ALLEGRO_KEY_UP:
         case ALLEGRO_KEY_K:
            handle_cursor_up_input();
            break;
         case ALLEGRO_KEY_DOWN:
         case ALLEGRO_KEY_J:
            handle_cursor_down_input();
            break;
         case ALLEGRO_KEY_LEFT:
         case ALLEGRO_KEY_H:
            handle_cursor_left_input();
            break;
         case ALLEGRO_KEY_RIGHT:
         case ALLEGRO_KEY_L:
            handle_cursor_right_input();
            break;
         case ALLEGRO_KEY_I:
            handle_option_input();
            break;
      }
      break;
   }
   return;
}

void ApplicationController::joy_button_down_func(ALLEGRO_EVENT* ev)
{
   std::cout << ev->joystick.button << std::endl;
   switch (ev->joystick.button)
   {
   case 3:
   case 4:
      handle_option_input();
      break;
   case 0:
   case 1:
      handle_submit_input();
      break;
   case 11:
      handle_cancel_input();
      break;
   }
   return;
}

void ApplicationController::joy_axis_func(ALLEGRO_EVENT* ev)
{
   static float joystick_0_y_state = 0.0;
   static float joystick_0_x_state = 0.0;
   static float joystick_1_y_state = 0.0;
   static float joystick_2_y_state = 0.0;

   switch (ev->joystick.stick)
   {
   case 0: // left most stick
      if (ev->joystick.axis == 0) // the right/left axis
      {
         float new_joystick_0_x_state = ev->joystick.pos;
         if (joystick_0_x_state < 0.5 && new_joystick_0_x_state >= 0.5)
         {
            std::cout << "CURSOR RIGHT" << std::endl;
            handle_cursor_right_input();
         }
         else if (joystick_0_x_state > -0.5 && new_joystick_0_x_state <= -0.5)
         {
            std::cout << "CURSOR LEFT" << std::endl;
            handle_cursor_left_input();
         }
         joystick_0_x_state = new_joystick_0_x_state;
      }
      else if (ev->joystick.axis == 1) // the up/down axis
      {
         float new_joystick_0_y_state = ev->joystick.pos;
         if (joystick_0_y_state < 0.5 && new_joystick_0_y_state >= 0.5)
         {
            std::cout << "CURSOR DOWN" << std::endl;
            handle_cursor_down_input();
         }
         else if (joystick_0_y_state > -0.5 && new_joystick_0_y_state <= -0.5)
         {
            std::cout << "CURSOR UP" << std::endl;
            handle_cursor_up_input();
         }
         joystick_0_y_state = new_joystick_0_y_state;
      }
      break;
   case 1:
      break;
   case 2: // stick 2, the hat
      // pretty sure this is buggy in mac. I think there's a problem with the mapping in vanilla allegro
      std::cout << "AXIS " << ev->joystick.axis << "; pos " << ev->joystick.pos << std::endl;
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

void ApplicationController::show_smart_phone()
{
   showing_smart_phone = true;
   return;
}

void ApplicationController::hide_smart_phone()
{
   showing_smart_phone = false;
   return;
}

void ApplicationController::draw_smart_phone()
{
   float phone_transparency = smart_phone_reveal_counter;
   ALLEGRO_COLOR fading_white =
      ALLEGRO_COLOR{phone_transparency, phone_transparency, phone_transparency, phone_transparency};
   ALLEGRO_BITMAP *smart_phone_image = obtain_bitmap_bin()->auto_get(get_image_identifier_for_smart_phone());

   float smart_phone_y_offset = (AllegroFlare::interpolator::tripple_fast_in(smart_phone_reveal_counter) * -100);

   allegro_flare::placement2d smart_phone_placement(
      1920/3 * 1,
      1080/3*2 + smart_phone_y_offset + 80,
      800,
      800
   );
   smart_phone_placement.start_transform();
   al_draw_tinted_bitmap(smart_phone_image, fading_white, 0, 0, 0);
   smart_phone_placement.restore_transform();
   return;
}

void ApplicationController::update_smart_phone()
{
   if (showing_smart_phone)
   {
      smart_phone_reveal_counter += 1.0/60.0f;
      if (smart_phone_reveal_counter >= 1.0) smart_phone_reveal_counter = 1.0f;
   }
   else
   {
      smart_phone_reveal_counter -= 1.0/60.0f;
      if (smart_phone_reveal_counter <= 0.0) smart_phone_reveal_counter = 0.0f;
   }
   return;
}

bool ApplicationController::parse_and_run_line(std::string raw_script_line, int line_num)
{
   std::string DIALOG = "DIALOG";
   std::string GOTO = "GOTO";
   std::string CHOICE = "CHOICE";
   std::string PLAY_MUSIC = "PLAY_MUSIC";
   std::string MARKER = "MARKER";
   std::string SIGNAL = "SIGNAL"; // outputs text to the terminal
   std::string SET_CHARACTER_ART = "SET_CHARACTER_ART";
   std::string SET_CHARACTER_FRAMING = "SET_CHARACTER_FRAMING";
   std::string BEAT = "BEAT";
   std::string WAIT = "WAIT";
   std::string COLLECT = "COLLECT";
   std::string COLLECT_SILENTLY = "COLLECT_SILENTLY";
   std::string IF_IN_INVENTORY = "IF_IN_INVENTORY";
   std::string OPENSCRIPT = "OPENSCRIPT";
   std::string ADD_FLAG = "ADD_FLAG";
   std::string IF_FLAG = "IF_FLAG";
   std::string PHONE = "PHONE";
   std::string SET_BACKGROUND = "SET_BACKGROUND";
   std::string SET_TITLE = "SET_TITLE";
   std::string CLEAR_DIALOGS = "CLEAR_DIALOGS";

   bool continue_directly_to_next_script_line = false;
   Krampus21::DialogBoxes::Base* created_dialog = nullptr;
   std::string script_line = Blast::String::Trimmer(raw_script_line).trim();

   std::pair<std::string, std::string> command_and_argument = parse_command_and_argument(script_line);
   std::string command = command_and_argument.first;
   std::string argument = command_and_argument.second;

   if (command != PHONE)
   {
      hide_smart_phone();
   }

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
   else if (command == PLAY_MUSIC)
   {
      // parse tokens
      std::vector<std::string> tokens = tokenize(argument);

      if (!assert_min_token_count(tokens, 1))
      {
         std::cout << "tokens must be at least 1 on line " << line_num << std::endl;
         return false;
      }
      std::string music_filename_identifier = tokens[0]; //"etherial-ambience-01.wav";

      audio_controller.play_music_track_by_identifier(music_filename_identifier);

      continue_directly_to_next_script_line = true;
   }
   else if (command == SET_TITLE)
   {
      // parse tokens
      std::vector<std::string> tokens = tokenize(argument);

      if (!assert_min_token_count(tokens, 1))
      {
         std::cout << "tokens must be at least 1 on line " << line_num << std::endl;
         return false;
      }

      std::string text = tokens[0];
      created_dialog = dialog_factory.create_title_text_dialog(text);

      continue_directly_to_next_script_line = true;
   }
   else if (command == CLEAR_DIALOGS)
   {
      if (current_dialog)
      {
         if (current_dialog) delete current_dialog;
         current_dialog = nullptr;
      }

      continue_directly_to_next_script_line = true;
   }
   else if (command == SET_BACKGROUND)
   {
      // parse tokens
      std::vector<std::string> tokens = tokenize(argument);

      if (!assert_min_token_count(tokens, 1))
      {
         std::cout << "tokens must be at least 1 on line " << line_num << std::endl;
         return false;
      }

      Krampus21::Backgrounds::Base* created_background = nullptr;
      Krampus21::BackgroundFactory background_factory(obtain_bitmap_bin());

      if (tokens[0] == "none")
      {
         if (current_background) delete current_background;
         current_background = nullptr;
      }
      else if (tokens[0] == "monoplex")
      {
         created_background = background_factory.create_monoplex();
      }
      else
      {
         std::string background_bitmap_filename_identifier = tokens[0];
         created_background = background_factory.create_image(background_bitmap_filename_identifier);

         // TODO create a simple background with a good-ole image
      }

      if (created_background)
      {
         if (current_background) delete current_background;
         current_background = created_background;
      }

      continue_directly_to_next_script_line = true;
   }
   else if (command == PHONE)
   {
      show_smart_phone();

      // parse tokens
      std::vector<std::string> tokens = tokenize(argument);

      // validate tokens
      if (!assert_min_token_count(tokens, 1))
      {
         std::cout << "tokens must be at least 1 on line " << line_num << std::endl;
         return false;
      }

      // play notification sound
      audio_controller.play_sound_effect_by_identifier("phone-notification.wav");


      // create the dialog
      std::vector<std::string> messages = tokens;
      created_dialog = dialog_factory.create_smart_phone_dialog(messages);

   }
   else if (command == OPENSCRIPT)
   {
      //std::string script_auto_prefix = "scripts/";
      std::string script_auto_prefix = "";
      std::string script_to_load = script_auto_prefix + argument;

      bool successful = load_script(script_to_load);

      if (successful)
      {
         if (current_dialog)
         {
            delete current_dialog;
            current_dialog = nullptr;
         }
         // consider stopping music? I think not.  The opening script should start, stop, or change the music
         // if needed.  Also, if the same music is already playing from the previous script...
         // it wont' stop it then start it... instead it will keep playing seamlessly
         continue_directly_to_next_script_line = true;

         // setting this flag is required so that the advancer does not automatically move to the next
         // line after oening the new script file
         set_script_freshly_loaded_via_OPENSCRIPT(true);
      }
   }
   else if (command == IF_IN_INVENTORY)
   {
      // tokenize
      std::vector<std::string> tokens = tokenize(argument);

      // validate
      // expect exactly 2 params
      if (!assert_token_count_eq(tokens, 2))
      {
         std::cout << "tokens must be equal to 2 on line " << line_num << std::endl;
         return false;
      }

      // get arguments
      int item_id = atoi(tokens[0].c_str());
      std::string consequence = tokens[1];

      // bonus:
      std::pair<std::string, std::string> consequence_command_and_argument = parse_command_and_argument(consequence);
      std::string consequence_command = consequence_command_and_argument.first;
      std::string consequence_argument = consequence_command_and_argument.second;
      // eval only GOTO
      if (consequence_command != "GOTO")
      {
         std::cout << "IF_IN_INVENTORY consequence argument must be a GOTO (line [" << line_num << "])" << std::endl;
      }
      // TODO: eval MARKER target exists

      if (af_inventory.has_item(item_id))
      {
         parse_and_run_line(consequence, line_num);
      }
      continue_directly_to_next_script_line = true;
   }
   else if (command == IF_FLAG)
   {
      // tokenize
      std::vector<std::string> tokens = tokenize(argument);

      // validate
      // expect exactly 2 params
      if (!assert_token_count_eq(tokens, 2))
      {
         std::cout << "tokens must be equal to 2 on line " << line_num << std::endl;
         return false;
      }

      // get arguments
      int flag_id = atoi(tokens[0].c_str());
      std::string consequence = tokens[1];

      // bonus:
      std::pair<std::string, std::string> consequence_command_and_argument = parse_command_and_argument(consequence);
      std::string consequence_command = consequence_command_and_argument.first;
      std::string consequence_argument = consequence_command_and_argument.second;
      // eval only GOTO
      if (consequence_command != "GOTO")
      {
         std::cout << "IF_IN_INVENTORY consequence argument must be a GOTO (line [" << line_num << "])" << std::endl;
      }
      // TODO: eval MARKER target exists

      if (flags.has_item(flag_id))
      {
         parse_and_run_line(consequence, line_num);
      }
      continue_directly_to_next_script_line = true;
   }
   else if (command == SIGNAL)
   {
      std::cout << argument << std::endl;
      continue_directly_to_next_script_line = true;
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
         if (tokens[i-1].empty() || tokens[i].empty())
         {
            std::cout << "WARNING: CHOICE argument on line [" << line_num << "] contains arguments that are empty. "
                      << "The full argument is \"" << argument << "\"" << std::endl;
         }
         choice_options.push_back({ tokens[i-1], tokens[i] });
      }

      //choice_options = { { "Boobar", "boobruhh" }, { "Zoozaz", "zazzle" } };
      created_dialog = dialog_factory.create_choice_dialog(choice_prompt, choice_options);
   }
   else if (command == WAIT)
   {
      // this will prevent the next line from executing until after a delay
      int num_sec_to_wait = 2.0;
      if (!argument.empty())
      {
         num_sec_to_wait = atoi(argument.c_str());
      }

      on_hold_for_wait_delay = true;
      wait_delay_countdown_sec = num_sec_to_wait;
   }
   else if (command == BEAT)
   {
      // essentially, this will add a pause or "beat" to the story.
      //std::string identifier = "etherial-ambience-01.wav";
      //audio_controller.play_music_track_by_identifier(identifier);
      //continue_directly_to_next_script_line = true;
      if (current_dialog)
      {
         delete current_dialog;
         current_dialog = nullptr;
      }
   }
   else if (command == COLLECT_SILENTLY || command == COLLECT)
   {
      int item_id = atoi(argument.c_str());
      std::tuple<std::string, std::string, std::string> item_definition = inventory.get_item_definition(item_id);
      std::string item_name = std::get<0>(item_definition);
      std::string item_bitmap_identifier = std::get<1>(item_definition);

      // add the item to the inventory
      af_inventory.add_item(item_id);

      // cout for debugging
      std::cout << "You got an item " << argument << std::endl;

      // construct the dialog
      if (command == COLLECT_SILENTLY)
      {
         continue_directly_to_next_script_line = true;
      }
      else if (command == COLLECT)
      {
         Krampus21::DialogBoxes::YouGotAnItem* created_you_got_an_item_dialog_box =
            dialog_factory.create_you_got_an_item_dialog(item_id, item_name, item_bitmap_identifier);
         created_dialog = created_you_got_an_item_dialog_box;
      }
   }
   else if (command == ADD_FLAG)
   {
      int flag_id = atoi(argument.c_str());

      // add the item to the inventory
      flags.add_item(flag_id);

      // cout for debugging
      std::cout << "A flag was set on the flag num " << argument << std::endl;

      continue_directly_to_next_script_line = true;
   }
   else if (command == SET_CHARACTER_ART)
   {
      character.set_sprite_record_identifier(argument);
      continue_directly_to_next_script_line = true;
   }
   else if (command == SET_CHARACTER_FRAMING)
   {
      if (argument == "wide") character.frame_wide();
      else if (argument == "mid") character.frame_mid();
      else if (argument == "close-up") character.frame_closeup();
      else
      {
         std::cout << "WARNING: Unrecognized argument \"" << argument << "\" "
                   << "for command \"" << command << "\"" << std::endl;
      }
      continue_directly_to_next_script_line = true;
   }
   else if (command == MARKER)
   {
      continue_directly_to_next_script_line = true;
   }
   else if (command == GOTO)
   {
      bool successful = script.goto_marker(argument);
      if (!successful)
      {
         std::cout << "WARNING: Attempted to GOTO a marker named \"" << argument << "\" "
                   << "but that marker does not exist. This is from line ["
                   << line_num << "], which is \"" << script_line << "\"" << std::endl;
      }
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

bool ApplicationController::assert_token_count_eq(std::vector<std::string> tokens, int value)
{
   return (tokens.size() == value);
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


