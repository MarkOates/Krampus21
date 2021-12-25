

#include <Krampus21/Titles/Slate.hpp>
#include <allegro_flare/placement2d.h>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{
namespace Titles
{


Slate::Slate(AllegroFlare::FontBin* font_bin)
   : font_bin(font_bin)
{
}


Slate::~Slate()
{
}


void Slate::render()
{
   if (!(font_bin))
      {
         std::stringstream error_message;
         error_message << "Slate" << "::" << "render" << ": error: " << "guard \"font_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   allegro_flare::placement2d label_pace;
   allegro_flare::placement2d title_pace;

   return;
}

ALLEGRO_FONT* Slate::obtain_title_font()
{
   return font_bin->auto_get("Lato-Regular.ttf -30");
}
} // namespace Titles
} // namespace Krampus21


