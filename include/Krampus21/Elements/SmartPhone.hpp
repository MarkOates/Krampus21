#pragma once


#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/FontBin.hpp>
#include <allegro_flare/placement2d.h>


namespace Krampus21
{
   namespace Elements
   {
      class SmartPhone
      {
      private:
         AllegroFlare::FontBin* font_bin;
         AllegroFlare::BitmapBin* bitmap_bin;
         allegro_flare::placement2d place;

      public:
         SmartPhone(AllegroFlare::FontBin* font_bin=nullptr, AllegroFlare::BitmapBin* bitmap_bin=nullptr);
         ~SmartPhone();

         void render();
      };
   }
}



