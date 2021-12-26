#pragma once


#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/FontBin.hpp>
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
         float age;
         float width;
         float height;

      public:
         YouGotAnItemRenderer(AllegroFlare::FontBin* font_bin=nullptr, AllegroFlare::BitmapBin* bitmap_bin=nullptr, float age=0, float width=400, float height=400);
         ~YouGotAnItemRenderer();

         float get_age();
         void render();
         float get_live_reveal_counter();
         ALLEGRO_FONT* obtain_notification_text_font();
         ALLEGRO_FONT* obtain_item_name_text_font();
         ALLEGRO_COLOR opaquify(ALLEGRO_COLOR color={0,0,0,0});
      };
   }
}



