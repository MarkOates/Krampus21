#pragma once


#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/Inventory.hpp>
#include <allegro_flare/placement2d.h>


namespace Krampus21
{
   class Inventory
   {
   private:
      AllegroFlare::FontBin* font_bin;
      AllegroFlare::BitmapBin* bitmap_bin;
      AllegroFlare::Inventory* af_inventory;
      allegro_flare::placement2d place;

   public:
      Inventory(AllegroFlare::FontBin* font_bin=nullptr, AllegroFlare::BitmapBin* bitmap_bin=nullptr);
      ~Inventory();

      void set_font_bin(AllegroFlare::FontBin* font_bin);
      void set_bitmap_bin(AllegroFlare::BitmapBin* bitmap_bin);
      allegro_flare::placement2d get_place();
      void render();
   };
}



