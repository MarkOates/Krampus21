#pragma once


#include <AllegroFlare/AudioController.hpp>
#include <AllegroFlare/AudioRepositoryElement.hpp>
#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Screen.hpp>
#include <AllegroFlare/Screens.hpp>
#include <Krampus21/DialogBoxes/Base.hpp>
#include <Krampus21/DialogFactory.hpp>
#include <Krampus21/Script.hpp>
#include <Krampus21/UserEventEmitter.hpp>
#include <allegro5/allegro.h>
#include <map>
#include <string>
#include <utility>
#include <vector>


namespace Krampus21
{
   class ApplicationController : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Framework* framework;
      AllegroFlare::Screens* screens;
      std::map<std::string, AllegroFlare::AudioRepositoryElement> sound_effect_elements;
      std::map<std::string, AllegroFlare::AudioRepositoryElement> music_track_elements;
      ALLEGRO_EVENT_SOURCE user_event_emitter_souce;
      Krampus21::UserEventEmitter user_event_emitter;
      AllegroFlare::AudioController audio_controller;
      Krampus21::DialogBoxes::Base* current_dialog;
      bool initialized;
      Krampus21::Script script;
      Krampus21::DialogFactory dialog_factory;

   public:
      ApplicationController(AllegroFlare::Framework* framework=nullptr, AllegroFlare::Screens* screens=nullptr, std::map<std::string, AllegroFlare::AudioRepositoryElement> sound_effect_elements={}, std::map<std::string, AllegroFlare::AudioRepositoryElement> music_track_elements={});
      ~ApplicationController();

      void initialize();
      bool load_script(std::string filename="unset-script-filename.txt");
      void advance();
      void play_current_script_line();
      void start_game();
      void shutdown_game();
      bool dialog_is_finished();
      void primary_timer_func() override;
      void key_down_func(ALLEGRO_EVENT* ev=nullptr) override;
      void joy_button_down_func(ALLEGRO_EVENT* ev=nullptr) override;
      void joy_axis_func(ALLEGRO_EVENT* ev=nullptr) override;
      void user_event_func(ALLEGRO_EVENT* ev=nullptr) override;
      AllegroFlare::FontBin* obtain_font_bin();
      Krampus21::DialogBoxes::Base* parse_line_and_create_dialog(std::string script_line={});
      static std::pair<std::string, std::string> parse_command_and_argument(std::string script_line={});
      static std::map<std::string, int> build_markers_index(std::vector<std::string> script_lines={});
      static std::vector<std::string> tokenize(std::string str="", char delim='|');
      static bool assert_min_token_count(std::vector<std::string> tokens={}, int min=0);
      static bool assert_odd_token_count(std::vector<std::string> tokens={}, int min=0);
   };
}



