

#include <Krampus21/Titles/Slate.hpp>
#include <allegro_flare/placement2d.h>
#include <allegro5/allegro_font.h>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{
namespace Titles
{


Slate::Slate(AllegroFlare::FontBin* font_bin, std::string primary_text, std::string secondary_text)
   : font_bin(font_bin)
   , primary_text(primary_text)
   , secondary_text(secondary_text)
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
   float opacity = 1.0;
   ALLEGRO_FONT *primary_text_font = obtain_primary_text_font();
   ALLEGRO_COLOR fading_white = ALLEGRO_COLOR{opacity, opacity, opacity, opacity};
   float primary_text_width = al_get_text_width(primary_text_font, primary_text.c_str());
   float primary_text_height = al_get_font_line_height(primary_text_font);
   //FADE TO WHITE
   //FADING WHITE
   //FADING LIGHT

   allegro_flare::placement2d primary_text_place(1920/2, 1080/2-30, primary_text_width, primary_text_height);
   allegro_flare::placement2d secondary_text_place;

   primary_text_place.start_transform();
   al_draw_text(obtain_primary_text_font(), fading_white, 0, 0, ALLEGRO_ALIGN_CENTER, primary_text.c_str());
   primary_text_place.restore_transform();

   secondary_text_place.start_transform();
   al_draw_text(obtain_primary_text_font(), fading_white, 0, 0, ALLEGRO_ALIGN_CENTER, secondary_text.c_str());
   secondary_text_place.restore_transform();

   return;
}

ALLEGRO_FONT* Slate::obtain_primary_text_font()
{
   return font_bin->auto_get("Lato-Regular.ttf -30");
}

ALLEGRO_FONT* Slate::obtain_secondary_text_font()
{
   return font_bin->auto_get("Lato-Bold.ttf -30");
}
} // namespace Titles
} // namespace Krampus21


