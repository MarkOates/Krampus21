#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <Krampus21/DialogBoxes/Base.hpp>
#include <allegro5/allegro.h>
#include <allegro_flare/placement2d.h>
#include <string>


namespace Krampus21
{
   class DialogBoxRenderer
   {
   private:
      AllegroFlare::FontBin* font_bin;
      Krampus21::DialogBoxes::Base* dialog_box;
      int dialog_box_num_revealed_characters;
      allegro_flare::placement2d place;

   public:
      DialogBoxRenderer(AllegroFlare::FontBin* font_bin=nullptr, Krampus21::DialogBoxes::Base* dialog_box=nullptr, int dialog_box_num_revealed_characters=9999);
      ~DialogBoxRenderer();

      int get_dialog_box_num_revealed_characters();
      allegro_flare::placement2d get_place();
      void render();
      void draw_special_state_empty_text();
      void draw_action_text(std::string text="[unset-action-text]");
      void draw_styled_revealed_text();
      std::string get_dialog_box_text();
      std::string concat_text(std::string source_text="", int length=0);
      ALLEGRO_FONT* obtain_dialog_font();
   };
}



