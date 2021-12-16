

#include <Krampus21/ScreenManager.hpp>
#include <Krampus21/DialogFactory.hpp>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>
#include <Krampus21/DialogBoxRenderer.hpp>
#include <stdexcept>
#include <sstream>


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
   , audio_controller({})
   , dialog({})
   , dialog_num_revealed_characters(0)
   , initialized(false)
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
   std::string dialog_filename = "/Users/markoates/Repos/Krampus21/bin/programs/data/dialogs/dialog-1.txt";
   Krampus21::DialogFactory dialog_factory;
   //dialog = dialog_factory.build_basic_test_dialog();
   dialog = dialog_factory.build_basic_dialog_from_file(dialog_filename);
   dialog_num_revealed_characters = 0;
   initialized = true;
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
   dialog.next_page();
   dialog_num_revealed_characters = 0;
   return;
}

void ScreenManager::update_dialog_playing()
{
   dialog_num_revealed_characters++;
   return;
}

void ScreenManager::primary_timer_func()
{
   update_dialog_playing();
   Krampus21::DialogBoxRenderer renderer(obtain_font_bin(), &dialog, dialog_num_revealed_characters);
   renderer.render();
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
} // namespace Krampus21


