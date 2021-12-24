#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <Krampus21/DialogBoxes/Base.hpp>
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
         Krampus21::DialogBoxes::Base* dialog_box;
         float width;
         float height;

      public:
         DialogBox(AllegroFlare::FontBin* font_bin=nullptr, Krampus21::DialogBoxes::Base* dialog_box=nullptr);
         ~DialogBox();

         float get_width();
         float get_height();
         void render();
         void draw_special_state_empty_text();
         void draw_action_text(std::string text="[unset-action-text]");
         std::string obtain_dialog_box_text();
         int obtain_dialog_box_num_revealed_characters();
         std::string concat_text(std::string source_text="", int length=0);
         ALLEGRO_FONT* obtain_dialog_font();
      };
   }
}



