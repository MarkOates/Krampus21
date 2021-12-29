

#include <Krampus21/BackgroundFactory.hpp>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{


BackgroundFactory::BackgroundFactory(AllegroFlare::BitmapBin* bitmap_bin)
   : bitmap_bin(bitmap_bin)
{
}


BackgroundFactory::~BackgroundFactory()
{
}


Krampus21::Backgrounds::Monoplex* BackgroundFactory::create_monoplex()
{
   if (!(bitmap_bin))
      {
         std::stringstream error_message;
         error_message << "BackgroundFactory" << "::" << "create_monoplex" << ": error: " << "guard \"bitmap_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   Krampus21::Backgrounds::Monoplex* monoplex = new Krampus21::Backgrounds::Monoplex(bitmap_bin);
   return monoplex;
}
} // namespace Krampus21


