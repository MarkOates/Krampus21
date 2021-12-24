

#include <Krampus21/Elements/DialogBoxNameTag.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{
namespace Elements
{


DialogBoxNameTag::DialogBoxNameTag(AllegroFlare::FontBin* font_bin, std::string name, float width, float height)
   : font_bin(font_bin)
   , name(name)
   , width(width)
   , height(height)
{
}


DialogBoxNameTag::~DialogBoxNameTag()
{
}


float DialogBoxNameTag::get_width()
{
   return width;
}


float DialogBoxNameTag::get_height()
{
   return height;
}


void DialogBoxNameTag::render()
{
   if (!(font_bin))
      {
         std::stringstream error_message;
         error_message << "DialogBoxNameTag" << "::" << "render" << ": error: " << "guard \"font_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(al_is_system_installed()))
      {
         std::stringstream error_message;
         error_message << "DialogBoxNameTag" << "::" << "render" << ": error: " << "guard \"al_is_system_installed()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(al_is_primitives_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "DialogBoxNameTag" << "::" << "render" << ": error: " << "guard \"al_is_primitives_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(al_get_current_display()))
      {
         std::stringstream error_message;
         error_message << "DialogBoxNameTag" << "::" << "render" << ": error: " << "guard \"al_get_current_display()\" not met";
         throw std::runtime_error(error_message.str());
      }
   float roundness = 18.0f;
   float border_thickness = 5.0f;
   float border_inner_padding = border_thickness * 3;
   //ALLEGRO_COLOR fill_color = al_color_html("162428");
   float opacity = 0.7;
   ALLEGRO_COLOR fill_color = ALLEGRO_COLOR{0.02f*opacity, 0.0f*opacity, 0.1f*opacity, opacity};
   ALLEGRO_COLOR border_color = al_color_html("244751");

   // draw backfill
   al_draw_filled_rounded_rectangle(
      0 + border_inner_padding,
      0 + border_inner_padding,
      width - border_inner_padding,
      height - border_inner_padding,
      roundness * 0.5,
      roundness * 0.5,
      fill_color
   );
   // draw border
   al_draw_rounded_rectangle(
      0,
      0,
      width,
      height,
      roundness,
      roundness,
      border_color,
      border_thickness
   );

   return;
}
} // namespace Elements
} // namespace Krampus21


