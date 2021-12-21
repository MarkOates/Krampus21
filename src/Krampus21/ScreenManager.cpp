

#include <Krampus21/ScreenManager.hpp>
#include <Krampus21/DialogFactory.hpp>
#include <stdexcept>
#include <sstream>
#include <Krampus21/ScriptLoader.hpp>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>
#include <Krampus21/DialogBoxRenderer.hpp>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{


ScreenManager::ScreenManager(AllegroFlare::Framework* framework, AllegroFlare::Screens* screens, std::map<std::string, AllegroFlare::AudioRepositoryElement> sound_effect_elements, std::map<std::string, AllegroFlare::AudioRepositoryElement> music_track_elements, std::string dialog_filename)
   : AllegroFlare::Screen()
   , framework(framework)
   , screens(screens)
   , sound_effect_elements(sound_effect_elements)
   , music_track_elements(music_track_elements)
   , dialog_filename(dialog_filename)
   , user_event_emitter_souce({})
   , user_event_emitter({})
   , audio_controller(&framework->get_sample_bin_ref(), sound_effect_elements, music_track_elements)
   , dialogs({})
   , current_dialog(nullptr)
   , initialized(false)
{
}


ScreenManager::~ScreenManager()
{
}


std::string ScreenManager::get_dialog_filename()
{
   return dialog_filename;
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

void ScreenManager::start_game()
{
   clear_all_dialogs();

   std::vector<std::string> script_lines = {
      { "DIALOG: This will be the first dialog loaded through a script loader." },
      { "CHOICE: How will you go? | Out like a flame | GOTO FLAMING_END | Quietly in the night | GOTO CALM_END" },
   };

   Krampus21::ScriptLoader script_loader(script_lines);
   dialogs = script_loader.parse();

   if (dialogs.empty())
   {
      // no dialogs are loaded
   }
   else
   {
      current_dialog = dialogs[0];
   }

   play_music_track("etherial-ambience-01.wav");
}

void ScreenManager::clear_all_dialogs()
{
   for (auto &dialog : dialogs) { if (dialog) delete dialog; }
   dialogs.clear();
   current_dialog = nullptr;
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

void ScreenManager::advance_dialog()
{
   if (!(framework))
      {
         std::stringstream error_message;
         error_message << "ScreenManager" << "::" << "advance_dialog" << ": error: " << "guard \"framework\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!current_dialog) return;
   current_dialog->next_page();
   return;
}

void ScreenManager::move_dialog_choice_cursor_up()
{
   // TODO
   return;
}

void ScreenManager::move_dialog_choice_cursor_down()
{
   // TODO
   return;
}

void ScreenManager::submit_dialog_choice_selection()
{
   // TODO
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
   else
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
            advance_dialog();
            break;
         case ALLEGRO_KEY_UP:
         case ALLEGRO_KEY_K:
            if (is_current_dialog_a_choice()) move_dialog_choice_cursor_up();
            break;
         case ALLEGRO_KEY_DOWN:
         case ALLEGRO_KEY_J:
            if (is_current_dialog_a_choice()) move_dialog_choice_cursor_down();
            break;
         case ALLEGRO_KEY_ENTER:
            submit_dialog_choice_selection();
            break;
      }
      break;
   }
   return;
}

void ScreenManager::joy_button_down_func(ALLEGRO_EVENT* ev)
{
   int button_mapped_for_advancing_dialog = 1;
   switch (ev->joystick.button)
   {
   case 4:
      shutdown_game();
      break;
   case 1:
      advance_dialog();
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

bool ScreenManager::is_current_dialog_a_choice()
{
   return (current_dialog && current_dialog->is_type("Choice"));
}
} // namespace Krampus21


