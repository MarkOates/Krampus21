

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
{
}


Monoplex::~Monoplex()
{
}


void Monoplex::draw()
{
   if (!(bitmap_bin))
      {
         std::stringstream error_message;
         error_message << "Monoplex" << "::" << "draw" << ": error: " << "guard \"bitmap_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   float time_now = al_get_time();
   ALLEGRO_BITMAP *monoplex_1_bitmap = bitmap_bin->auto_get("monoplex-1.png");
   ALLEGRO_BITMAP *monoplex_2_bitmap = bitmap_bin->auto_get("monoplex-2.png");
   ALLEGRO_BITMAP *monoplex_3_bitmap = bitmap_bin->auto_get("monoplex-3.png");
   allegro_flare::placement2d monoplex_1_place;
   allegro_flare::placement2d monoplex_2_place;
   allegro_flare::placement2d monoplex_3_place;

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


