#pragma once


#include <AllegroFlare/AudioController.hpp>
#include <AllegroFlare/AudioRepositoryElement.hpp>
#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Screen.hpp>
#include <AllegroFlare/Screens.hpp>
#include <Krampus21/DialogBoxes/Base.hpp>
#include <Krampus21/UserEventEmitter.hpp>
#include <allegro5/allegro.h>
#include <map>
#include <string>
#include <vector>


namespace Krampus21
{
   class ScreenManager : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Framework* framework;
      AllegroFlare::Screens* screens;
      std::map<std::string, AllegroFlare::AudioRepositoryElement> sound_effect_elements;
      std::map<std::string, AllegroFlare::AudioRepositoryElement> music_track_elements;
      std::string dialog_filename;
      ALLEGRO_EVENT_SOURCE user_event_emitter_souce;
      Krampus21::UserEventEmitter user_event_emitter;
      AllegroFlare::AudioController audio_controller;
      std::vector<Krampus21::DialogBoxes::Base*> dialogs;
      Krampus21::DialogBoxes::Base* current_dialog;
      int dialog_num_revealed_characters;
      bool initialized;

   public:
      ScreenManager(AllegroFlare::Framework* framework=nullptr, AllegroFlare::Screens* screens=nullptr, std::map<std::string, AllegroFlare::AudioRepositoryElement> sound_effect_elements={}, std::map<std::string, AllegroFlare::AudioRepositoryElement> music_track_elements={}, std::string dialog_filename="unset-dialog-file.txt");
      ~ScreenManager();

      std::string get_dialog_filename();
      void initialize();
      void start_game();
      void clear_all_dialogs();
      void shutdown_game();
      void advance_dialog();
      void move_dialog_choice_cursor_up();
      void move_dialog_choice_cursor_down();
      void submit_dialog_choice_selection();
      void update_dialog();
      bool dialog_is_finished();
      void primary_timer_func() override;
      void play_music_track(std::string identifier="unset-music-identifier");
      void key_down_func(ALLEGRO_EVENT* ev=nullptr) override;
      void joy_button_down_func(ALLEGRO_EVENT* ev=nullptr) override;
      void user_event_func(ALLEGRO_EVENT* ev=nullptr) override;
      AllegroFlare::FontBin* obtain_font_bin();
      bool is_current_dialog_a_choice();
   };
}



