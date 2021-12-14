

#include <Krampus21/ScreenManager.hpp>
#include <Krampus21/Screens/GameplayScreen.hpp>
#include <stdexcept>
#include <sstream>
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
   , current_screen(nullptr)
   , user_event_emitter_souce({})
   , user_event_emitter({})
   , audio_controller({})
   , initialized(false)
{
}


ScreenManager::~ScreenManager()
{
}


void ScreenManager::initialize()
{
   // TODO
   initialized = true;
   return;
}

void ScreenManager::load_initial_screen()
{
   if (!(initialized))
      {
         std::stringstream error_message;
         error_message << "ScreenManager" << "::" << "load_initial_screen" << ": error: " << "guard \"initialized\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (current_screen) delete current_screen;
   current_screen = new Krampus21::Screens::GameplayScreen;
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

void ScreenManager::key_down_func(ALLEGRO_EVENT* ev)
{
   switch (ev->type)
   {
   case ALLEGRO_EVENT_KEY_DOWN:
      shutdown_game();
      break;
   }
   return;
}

void ScreenManager::user_event_func(ALLEGRO_EVENT* ev)
{
   return;
}
} // namespace Krampus21


