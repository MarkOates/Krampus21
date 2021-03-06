#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <string>
#include <vector>


namespace Krampus21
{
   namespace Elements
   {
      class SmartPhone
      {
      private:
         AllegroFlare::FontBin* font_bin;
         float width;
         float height;
         std::vector<std::string> messages;

      public:
         SmartPhone(AllegroFlare::FontBin* font_bin=nullptr, float width=1, float height=1, std::vector<std::string> messages={"[no-messages-set]"});
         ~SmartPhone();

         void render();
      };
   }
}



