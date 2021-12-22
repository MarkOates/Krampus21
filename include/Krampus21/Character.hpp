#pragma once


#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/FontBin.hpp>
#include <allegro5/allegro.h>
#include <allegro_flare/placement2d.h>


namespace Krampus21
{
   class Character
   {
   private:
      AllegroFlare::FontBin* font_bin;
      AllegroFlare::BitmapBin* bitmap_bin;
      allegro_flare::placement2d place;

   public:
      Character(AllegroFlare::FontBin* font_bin=nullptr, AllegroFlare::BitmapBin* bitmap_bin=nullptr);
      ~Character();

      allegro_flare::placement2d get_place();
      void render();
      ALLEGRO_BITMAP* infer_current_sprite();
   };
}



