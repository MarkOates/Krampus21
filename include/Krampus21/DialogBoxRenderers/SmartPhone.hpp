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
         float window_width;
         float window_height;
         std::vector<std::string> messages;
         float reveal_counter;
         bool draw_background_fill;

      public:
         SmartPhone(AllegroFlare::FontBin* font_bin=nullptr, float window_width=1, float window_height=1, std::vector<std::string> messages={}, float reveal_counter=0);
         ~SmartPhone();

         void set_draw_background_fill(bool draw_background_fill);
         bool get_draw_background_fill();
         void render();
         float build_sanitized_reveal_counter();
      };
   }
}



