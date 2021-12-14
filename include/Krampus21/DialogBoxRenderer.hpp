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

   public:
      DialogBoxRenderer(AllegroFlare::FontBin* font_bin=nullptr, Krampus21::DialogBoxes::Base* dialog_box=nullptr);
      ~DialogBoxRenderer();

      allegro_flare::placement2d get_place();
      void render();
      std::vector<std::string> get_dialog_box_lines();
      ALLEGRO_FONT* obtain_dialog_font();
   };
}



