

#include <Krampus21/Inventory.hpp>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{


Inventory::Inventory(AllegroFlare::FontBin* font_bin, AllegroFlare::BitmapBin* bitmap_bin)
   : font_bin(font_bin)
   , bitmap_bin(bitmap_bin)
   , af_inventory(nullptr)
   , place({ 1920/2, 1080/5*2, 800, 800 })
{
}


Inventory::~Inventory()
{
}


void Inventory::set_font_bin(AllegroFlare::FontBin* font_bin)
{
   this->font_bin = font_bin;
}


void Inventory::set_bitmap_bin(AllegroFlare::BitmapBin* bitmap_bin)
{
   this->bitmap_bin = bitmap_bin;
}


allegro_flare::placement2d Inventory::get_place()
{
   return place;
}


void Inventory::render()
{
   if (!(af_inventory))
      {
         std::stringstream error_message;
         error_message << "Inventory" << "::" << "render" << ": error: " << "guard \"af_inventory\" not met";
         throw std::runtime_error(error_message.str());
      }
   return;
}
} // namespace Krampus21


