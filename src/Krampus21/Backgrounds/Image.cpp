

#include <Krampus21/Backgrounds/Image.hpp>
#include <allegro_flare/placement2d.h>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{
namespace Backgrounds
{


Image::Image(AllegroFlare::BitmapBin* bitmap_bin, std::string image_filename)
   : Krampus21::Backgrounds::Base("Image")
   , bitmap_bin(bitmap_bin)
   , image_filename(image_filename)
   , image_file_location_prefix("backgrounds/")
{
}


Image::~Image()
{
}


void Image::draw()
{
   if (!(bitmap_bin))
      {
         std::stringstream error_message;
         error_message << "Image" << "::" << "draw" << ": error: " << "guard \"bitmap_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   allegro_flare::placement2d background_image_placement{1920/2, 1080/2, 1920/2, 1080/2};
   float scale = 2.0f;
   background_image_placement.scale.x = background_image_placement.scale.y = scale;

   ALLEGRO_BITMAP *bitmap = obtain_background_bitmap();
   background_image_placement.start_transform();
   al_draw_bitmap(bitmap, 0, 0, 0);
   background_image_placement.restore_transform();
   return;
}

ALLEGRO_BITMAP* Image::obtain_background_bitmap()
{
   std::string full_identifier = image_file_location_prefix + image_filename;
   return bitmap_bin->auto_get(full_identifier);
}
} // namespace Backgrounds
} // namespace Krampus21


