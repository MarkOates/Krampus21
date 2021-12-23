#pragma once


#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/FontBin.hpp>
#include <allegro5/allegro.h>
#include <allegro_flare/placement2d.h>
#include <string>


namespace Krampus21
{
   class Character
   {
   private:
      AllegroFlare::FontBin* font_bin;
      AllegroFlare::BitmapBin* bitmap_bin;
      allegro_flare::placement2d place;
      std::string sprite_record_identifier;

   public:
      Character(AllegroFlare::FontBin* font_bin=nullptr, AllegroFlare::BitmapBin* bitmap_bin=nullptr);
      ~Character();

      void set_font_bin(AllegroFlare::FontBin* font_bin);
      void set_bitmap_bin(AllegroFlare::BitmapBin* bitmap_bin);
      void set_sprite_record_identifier(std::string sprite_record_identifier);
      allegro_flare::placement2d get_place();
      std::string get_sprite_record_identifier();
      void render();
      ALLEGRO_BITMAP* infer_current_sprite();
   };
}



