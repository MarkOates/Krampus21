

#include <Krampus21/Character.hpp>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{


Character::Character(AllegroFlare::FontBin* font_bin, AllegroFlare::BitmapBin* bitmap_bin)
   : font_bin(font_bin)
   , bitmap_bin(bitmap_bin)
   , place({ 1920/2, 1080/2, 800, 800 })
{
}


Character::~Character()
{
}


allegro_flare::placement2d Character::get_place()
{
   return place;
}


void Character::render()
{
   ALLEGRO_BITMAP *sprite = infer_current_sprite();
   if (!sprite) return;

   place.start_transform();
   al_draw_bitmap(sprite, 0, 0, 0);
   place.restore_transform();
   return;
}

ALLEGRO_BITMAP* Character::infer_current_sprite()
{
   if (!(bitmap_bin))
      {
         std::stringstream error_message;
         error_message << "Character" << "::" << "infer_current_sprite" << ": error: " << "guard \"bitmap_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   return bitmap_bin->auto_get("character-test-01.png");
}
} // namespace Krampus21


