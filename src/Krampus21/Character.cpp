

#include <Krampus21/Character.hpp>



namespace Krampus21
{


Character::Character(AllegroFlare::FontBin* font_bin, AllegroFlare::BitmapBin* bitmap_bin)
   : font_bin(font_bin)
   , bitmap_bin(bitmap_bin)
{
}


Character::~Character()
{
}


std::string Character::run()
{
   return "Hello World!";
}
} // namespace Krampus21


