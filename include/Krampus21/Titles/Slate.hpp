#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <allegro5/allegro_font.h>
#include <string>


namespace Krampus21
{
   namespace Titles
   {
      class Slate
      {
      private:
         AllegroFlare::FontBin* font_bin;
         std::string primary_text;
         std::string secondary_text;

      public:
         Slate(AllegroFlare::FontBin* font_bin=nullptr, std::string primary_text="", std::string secondary_text="");
         ~Slate();

         void render();
         ALLEGRO_FONT* obtain_primary_text_font();
         ALLEGRO_FONT* obtain_secondary_text_font();
      };
   }
}



