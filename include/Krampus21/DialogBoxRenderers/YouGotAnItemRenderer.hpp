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
         float width;
         float height;

      public:
         YouGotAnItemRenderer(AllegroFlare::FontBin* font_bin=nullptr, AllegroFlare::BitmapBin* bitmap_bin=nullptr, Krampus21::DialogBoxes::YouGotAnItem* you_got_an_item_dialog_box=nullptr, float width=1, float height=1);
         ~YouGotAnItemRenderer();

         void render();
         ALLEGRO_FONT* obtain_notification_text_font();
         ALLEGRO_FONT* obtain_item_name_text_font();
      };
   }
}



