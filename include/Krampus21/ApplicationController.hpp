#pragma once


#include <AllegroFlare/AudioController.hpp>
#include <AllegroFlare/AudioRepositoryElement.hpp>
#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Inventory.hpp>
#include <AllegroFlare/Screen.hpp>
#include <AllegroFlare/Screens.hpp>
#include <Krampus21/Backgrounds/Base.hpp>
#include <Krampus21/Character.hpp>
#include <Krampus21/DialogBoxes/Base.hpp>
#include <Krampus21/DialogFactory.hpp>
#include <Krampus21/Inventory.hpp>
#include <Krampus21/Script.hpp>
#include <Krampus21/UserEventEmitter.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
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
      Krampus21::Backgrounds::Base* current_background;
      Krampus21::Character character;
      bool initialized;
      Krampus21::Script script;
      Krampus21::DialogFactory dialog_factory;
      ALLEGRO_COLOR background_color;
      float letterbox_frame_height;
      ALLEGRO_COLOR letterbox_color;
      AllegroFlare::Inventory af_inventory;
      AllegroFlare::Inventory flags;
      Krampus21::Inventory inventory;
      bool script_freshly_loaded_via_OPENSCRIPT;
      bool showing_smart_phone;
      float smart_phone_reveal_counter;
      std::string image_identifier_for_smart_phone;
      float wait_delay_countdown_sec;
      bool on_hold_for_wait_delay;

   public:
      ApplicationController(AllegroFlare::Framework* framework=nullptr, AllegroFlare::Screens* screens=nullptr, std::map<std::string, AllegroFlare::AudioRepositoryElement> sound_effect_elements={}, std::map<std::string, AllegroFlare::AudioRepositoryElement> music_track_elements={});
      ~ApplicationController();

      void set_script_freshly_loaded_via_OPENSCRIPT(bool script_freshly_loaded_via_OPENSCRIPT);
      Krampus21::DialogBoxes::Base* get_current_dialog();
      Krampus21::Backgrounds::Base* get_current_background();
      bool get_script_freshly_loaded_via_OPENSCRIPT();
      std::string get_image_identifier_for_smart_phone();
      void initialize();
      bool load_script_lines(std::vector<std::string> script_lines={});
      bool load_script(std::string filename="unset-script-filename.txt");
      void advance();
      void handle_cursor_up_input();
      void handle_cursor_down_input();
      void handle_cursor_left_input();
      void handle_cursor_right_input();
      void handle_submit_input();
      void handle_cancel_input();
      void handle_option_input();
      void play_current_script_line();
      void start_game();
      void shutdown_game();
      bool dialog_is_finished();
      void open_inventory();
      void close_inventory();
      void toggle_inventory();
      void primary_timer_func() override;
      void draw_letterbox();
      void key_down_func(ALLEGRO_EVENT* ev=nullptr) override;
      void joy_button_down_func(ALLEGRO_EVENT* ev=nullptr) override;
      void joy_axis_func(ALLEGRO_EVENT* ev=nullptr) override;
      void user_event_func(ALLEGRO_EVENT* ev=nullptr) override;
      AllegroFlare::FontBin* obtain_font_bin();
      AllegroFlare::BitmapBin* obtain_bitmap_bin();
      void show_smart_phone();
      void hide_smart_phone();
      void draw_smart_phone();
      void update_smart_phone();
      bool parse_and_run_line(std::string raw_script_line="[empty-script-line]", int line_num=0);
      static std::pair<std::string, std::string> parse_command_and_argument(std::string script_line={});
      static std::map<std::string, int> build_markers_index(std::vector<std::string> script_lines={});
      static std::vector<std::string> tokenize(std::string str="", char delim='|');
      static bool assert_min_token_count(std::vector<std::string> tokens={}, int min=0);
      static bool assert_token_count_eq(std::vector<std::string> tokens={}, int value=0);
      static bool assert_odd_token_count(std::vector<std::string> tokens={}, int min=0);
      ALLEGRO_FONT* obtain_dialog_font();
   };
}



