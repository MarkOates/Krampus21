#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <Krampus21/DialogBoxes/Base.hpp>
#include <allegro5/allegro.h>
#include <allegro_flare/placement2d.h>


namespace Krampus21
{
   class DialogBoxRenderer
   {
   private:
      AllegroFlare::FontBin* font_bin;
      Krampus21::DialogBoxes::Base* dialog_box;
      allegro_flare::placement2d place;

   public:
      DialogBoxRenderer(AllegroFlare::FontBin* font_bin=nullptr);
      ~DialogBoxRenderer();

      allegro_flare::placement2d get_place();
      void render();
      ALLEGRO_FONT* obtain_dialog_font();
   };
}



