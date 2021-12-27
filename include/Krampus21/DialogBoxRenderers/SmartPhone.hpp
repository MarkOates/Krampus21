#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <string>
#include <vector>


namespace Krampus21
{
   namespace DialogBoxRenderers
   {
      class SmartPhone
      {
      private:
         AllegroFlare::FontBin* font_bin;
         float width;
         float height;
         std::vector<std::string> messages;
         float reveal_counter;

      public:
         SmartPhone(AllegroFlare::FontBin* font_bin=nullptr, float width=1, float height=1, std::vector<std::string> messages={}, float reveal_counter=0);
         ~SmartPhone();

         void render();
         float build_sanitized_reveal_counter();
      };
   }
}



