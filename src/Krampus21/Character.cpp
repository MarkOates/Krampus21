

#include <Krampus21/Character.hpp>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{


Character::Character(AllegroFlare::FontBin* font_bin, AllegroFlare::BitmapBin* bitmap_bin)
   : font_bin(font_bin)
   , bitmap_bin(bitmap_bin)
   , place({ 1920/2, 1080/5*2, 800, 800 })
   , sprite_record_identifier("[character-sprite-default-and-unset]")
{
}


Character::~Character()
{
}


void Character::set_font_bin(AllegroFlare::FontBin* font_bin)
{
   this->font_bin = font_bin;
}


void Character::set_bitmap_bin(AllegroFlare::BitmapBin* bitmap_bin)
{
   this->bitmap_bin = bitmap_bin;
}


void Character::set_sprite_record_identifier(std::string sprite_record_identifier)
{
   this->sprite_record_identifier = sprite_record_identifier;
}


allegro_flare::placement2d Character::get_place()
{
   return place;
}


std::string Character::get_sprite_record_identifier()
{
   return sprite_record_identifier;
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

void Character::frame_mid()
{
   place.scale.x = 1.0;
   place.scale.y = 1.0;
   return;
}

void Character::frame_wide()
{
   place.scale.x = 0.8;
   place.scale.y = 0.8;
   return;
}

void Character::frame_closeup()
{
   place.scale.x = 2.0;
   place.scale.y = 2.0;
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
   return bitmap_bin->auto_get(get_sprite_record_identifier());
}
} // namespace Krampus21


