

#include <Krampus21/Backgrounds/Monoplex.hpp>
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
   ALLEGRO_BITMAP *monoplex_1_bitmap = bitmap_bin->auto_get("monoplex-1.png");
   ALLEGRO_BITMAP *monoplex_2_bitmap = bitmap_bin->auto_get("monoplex-2.png");
   ALLEGRO_BITMAP *monoplex_3_bitmap = bitmap_bin->auto_get("monoplex-3.png");
   return;
}
} // namespace Backgrounds
} // namespace Krampus21


