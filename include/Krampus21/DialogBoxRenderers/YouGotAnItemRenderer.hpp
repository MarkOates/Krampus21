#pragma once


#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/FontBin.hpp>
#include <allegro5/allegro.h>
#include <string>


namespace Krampus21
{
   namespace DialogBoxRenderers
   {
      class YouGotAnItemRenderer
      {
      private:
         AllegroFlare::FontBin* font_bin;
         AllegroFlare::BitmapBin* bitmap_bin;
         std::string item_name;
         std::string item_bitmap_identifier;
         float age;
         float width;
         float height;

      public:
         YouGotAnItemRenderer(AllegroFlare::FontBin* font_bin=nullptr, AllegroFlare::BitmapBin* bitmap_bin=nullptr, std::string item_name="[a-name-that-has-not-been-set]", std::string item_bitmap_identifier="[an-bitmap-identifier-that-nas-not-been-set]", float age=0, float width=400, float height=400);
         ~YouGotAnItemRenderer();

         std::string get_item_name();
         std::string get_item_bitmap_identifier();
         float get_age();
         void render();
         float get_live_reveal_counter();
         ALLEGRO_FONT* obtain_notification_text_font();
         ALLEGRO_FONT* obtain_item_name_text_font();
         ALLEGRO_COLOR opaquify(ALLEGRO_COLOR color={0,0,0,0});
      };
   }
}



