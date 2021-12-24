#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <string>


namespace Krampus21
{
   namespace Elements
   {
      class DialogBoxNameTag
      {
      private:
         AllegroFlare::FontBin* font_bin;
         std::string name;
         float width;
         float height;

      public:
         DialogBoxNameTag(AllegroFlare::FontBin* font_bin=nullptr, std::string name="[name-not-set]", float width=200, float height=80);
         ~DialogBoxNameTag();

         float get_width();
         float get_height();
         void render();
      };
   }
}



