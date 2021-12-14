#pragma once


#include <AllegroFlare/AudioController.hpp>
#include <AllegroFlare/AudioRepositoryElement.hpp>
#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Screen.hpp>
#include <AllegroFlare/Screens.hpp>
#include <Krampus21/UserEventEmitter.hpp>
#include <allegro5/allegro.h>
#include <map>
#include <string>


namespace Krampus21
{
   class ScreenManager : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Framework* framework;
      AllegroFlare::Screens* screens;
      std::map<std::string, AllegroFlare::AudioRepositoryElement> sound_effect_elements;
      std::map<std::string, AllegroFlare::AudioRepositoryElement> music_track_elements;
      ALLEGRO_EVENT_SOURCE user_event_emitter_souce;
      Krampus21::UserEventEmitter user_event_emitter;
      AllegroFlare::AudioController audio_controller;
      bool initialized;

   public:
      ScreenManager(AllegroFlare::Framework* framework=nullptr, AllegroFlare::Screens* screens=nullptr, std::map<std::string, AllegroFlare::AudioRepositoryElement> sound_effect_elements={}, std::map<std::string, AllegroFlare::AudioRepositoryElement> music_track_elements={});
      ~ScreenManager();

      void initialize();
      void shutdown_game();
      void advance_dialog();
      void key_down_func(ALLEGRO_EVENT* ev=nullptr) override;
      void user_event_func(ALLEGRO_EVENT* ev=nullptr) override;
   };
}



