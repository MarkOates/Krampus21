

#include <Krampus21/Backgrounds/Monoplex.hpp>
#include <allegro_flare/placement2d.h>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{
namespace Backgrounds
{


Monoplex::Monoplex(AllegroFlare::BitmapBin* bitmap_bin)
   : Krampus21::Backgrounds::Base("Monoplex")
   , bitmap_bin(bitmap_bin)
   , monoplex_1_counter(0)
   , monoplex_2_counter(0)
   , monoplex_3_counter(0)
{
}


Monoplex::~Monoplex()
{
}


void Monoplex::update()
{
   monoplex_1_counter += 60.0/1.0f;
   monoplex_2_counter += 60.0/1.0f;
   monoplex_3_counter += 60.0/1.0f;
   return;
}

void Monoplex::draw()
{
   if (!(bitmap_bin))
      {
         std::stringstream error_message;
         error_message << "Monoplex" << "::" << "draw" << ": error: " << "guard \"bitmap_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   float screen_cx = 1920/2;
   float screen_cy = 1080/2;
   float time_now = al_get_time();
   ALLEGRO_BITMAP *monoplex_1_bitmap = bitmap_bin->auto_get("monoplex-1.png");
   ALLEGRO_BITMAP *monoplex_2_bitmap = bitmap_bin->auto_get("monoplex-2.png");
   ALLEGRO_BITMAP *monoplex_3_bitmap = bitmap_bin->auto_get("monoplex-3.png");
   allegro_flare::placement2d monoplex_1_place{screen_cx, screen_cy, 800, 800};
   allegro_flare::placement2d monoplex_2_place{screen_cx, screen_cy, 800, 800};
   allegro_flare::placement2d monoplex_3_place{screen_cx, screen_cy, 800, 800};

   monoplex_1_place.start_transform();
   al_draw_bitmap(monoplex_1_bitmap, 0, 0, 0);
   monoplex_1_place.restore_transform();

   monoplex_2_place.start_transform();
   al_draw_bitmap(monoplex_2_bitmap, 0, 0, 0);
   monoplex_2_place.restore_transform();

   monoplex_3_place.start_transform();
   al_draw_bitmap(monoplex_3_bitmap, 0, 0, 0);
   monoplex_3_place.restore_transform();

   return;
}
} // namespace Backgrounds
} // namespace Krampus21


