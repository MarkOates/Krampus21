#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <Krampus21/DialogBoxes/Base.hpp>
#include <allegro5/allegro.h>
#include <allegro_flare/placement2d.h>
#include <string>
#include <vector>


namespace Krampus21
{
   class DialogBoxRenderer
   {
   private:
      AllegroFlare::FontBin* font_bin;
      Krampus21::DialogBoxes::Base* dialog_box;
      int dialog_box_num_revealed_characters;
      allegro_flare::placement2d place;
      bool showing_next_cursor;
      bool showing_close_cursor;

   public:
      DialogBoxRenderer(AllegroFlare::FontBin* font_bin=nullptr, Krampus21::DialogBoxes::Base* dialog_box=nullptr, int dialog_box_num_revealed_characters=9999);
      ~DialogBoxRenderer();

      void set_showing_next_cursor(bool showing_next_cursor);
      void set_showing_close_cursor(bool showing_close_cursor);
      int get_dialog_box_num_revealed_characters();
      allegro_flare::placement2d get_place();
      bool get_showing_next_cursor();
      bool get_showing_close_cursor();
      void render();
      void draw_styled_revealed_text();
      std::vector<std::string> get_dialog_box_lines();
      std::string concat_text(std::string source_text="", int length=0);
      ALLEGRO_FONT* obtain_dialog_font();
   };
}



