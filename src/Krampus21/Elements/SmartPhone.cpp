

#include <Krampus21/Elements/SmartPhone.hpp>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{
namespace Elements
{


SmartPhone::SmartPhone(AllegroFlare::FontBin* font_bin, AllegroFlare::BitmapBin* bitmap_bin)
   : font_bin(font_bin)
   , bitmap_bin(bitmap_bin)
   , place({1920/2, 1080/2, 400, 400})
{
}


SmartPhone::~SmartPhone()
{
}


void SmartPhone::render()
{
   if (!(al_is_primitives_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "SmartPhone" << "::" << "render" << ": error: " << "guard \"al_is_primitives_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   place.start_transform();
   al_draw_filled_rectangle(400, 400, 200, 500, al_color_name("blue"));
   place.restore_transform();
   return;
}
} // namespace Elements
} // namespace Krampus21


