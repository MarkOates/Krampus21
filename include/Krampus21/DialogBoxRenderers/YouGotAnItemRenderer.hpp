#pragma once


#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/FontBin.hpp>
#include <Krampus21/DialogBoxes/YouGotAnItem.hpp>
#include <allegro5/allegro.h>


namespace Krampus21
{
   namespace DialogBoxRenderers
   {
      class YouGotAnItemRenderer
      {
      private:
         AllegroFlare::FontBin* font_bin;
         AllegroFlare::BitmapBin* bitmap_bin;
         Krampus21::DialogBoxes::YouGotAnItem* you_got_an_item_dialog_box;

      public:
         YouGotAnItemRenderer(AllegroFlare::FontBin* font_bin=nullptr, AllegroFlare::BitmapBin* bitmap_bin=nullptr, Krampus21::DialogBoxes::YouGotAnItem* you_got_an_item_dialog_box=nullptr);
         ~YouGotAnItemRenderer();

         void render();
         ALLEGRO_FONT* obtain_dialog_font();
      };
   }
}



