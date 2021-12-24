#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <allegro5/allegro.h>
#include <string>


namespace Krampus21
{
   namespace Elements
   {
      class DialogBox
      {
      private:
         AllegroFlare::FontBin* font_bin;
         float width;
         float height;
         bool in_finished_state;
         bool draw_next_action_cursor;

      public:
         DialogBox(AllegroFlare::FontBin* font_bin=nullptr);
         ~DialogBox();

         float get_width();
         float get_height();
         bool get_in_finished_state();
         bool get_draw_next_action_cursor();
         void render();
         void draw_special_state_empty_text();
         void draw_action_text(std::string text="[unset-action-text]");
         ALLEGRO_FONT* obtain_dialog_font();
      };
   }
}



