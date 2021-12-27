#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <allegro5/allegro_font.h>
#include <string>


namespace Krampus21
{
   namespace Elements
   {
      class SmartPhoneDialogBubble
      {
      private:
         AllegroFlare::FontBin* font_bin;
         std::string text;
         float width;
         float height;
         bool callout_on_left;

      public:
         SmartPhoneDialogBubble(AllegroFlare::FontBin* font_bin=nullptr, std::string text="", float width=1, float height=1, bool callout_on_left=false);
         ~SmartPhoneDialogBubble();

         void render();
         ALLEGRO_FONT* obtain_text_font();
      };
   }
}



