

#include <Krampus21/ScreenManager.hpp>



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


void ScreenManager::load_initial_screen()
{
   return;
}

void ScreenManager::initialize()
{
   // TODO
   initialized = true;
   return;
}

void ScreenManager::key_down_func(ALLEGRO_EVENT* ev)
{
   return;
}

void ScreenManager::user_event_func(ALLEGRO_EVENT* ev)
{
   return;
}
} // namespace Krampus21


