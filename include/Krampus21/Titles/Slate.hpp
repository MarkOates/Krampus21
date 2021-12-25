#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <allegro5/allegro_font.h>


namespace Krampus21
{
   namespace Titles
   {
      class Slate
      {
      private:
         AllegroFlare::FontBin* font_bin;

      public:
         Slate(AllegroFlare::FontBin* font_bin=nullptr);
         ~Slate();

         void render();
         ALLEGRO_FONT* obtain_title_font();
      };
   }
}



