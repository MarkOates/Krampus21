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
         int primary_text_kerning;
         int secondary_text_kerning;

      public:
         Slate(AllegroFlare::FontBin* font_bin=nullptr, std::string primary_text="", std::string secondary_text="");
         ~Slate();

         void set_primary_text_kerning(int primary_text_kerning);
         void set_secondary_text_kerning(int secondary_text_kerning);
         int get_primary_text_kerning();
         int get_secondary_text_kerning();
         void render();
         std::string kern(std::string text="", int amount=6);
         ALLEGRO_FONT* obtain_primary_text_font();
         ALLEGRO_FONT* obtain_secondary_text_font();
      };
   }
}



