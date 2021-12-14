

#include <Krampus21/DialogBoxRenderer.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{


DialogBoxRenderer::DialogBoxRenderer()
   : dialog_box(nullptr)
   , place({ 1920/2, 1080/3*2, 1920/2, 1080/3 })
{
}


DialogBoxRenderer::~DialogBoxRenderer()
{
}


allegro_flare::placement2d DialogBoxRenderer::get_place()
{
   return place;
}


void DialogBoxRenderer::render()
{
   if (!(al_is_system_installed()))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "render" << ": error: " << "guard \"al_is_system_installed()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(al_is_primitives_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "render" << ": error: " << "guard \"al_is_primitives_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(al_get_current_display()))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "render" << ": error: " << "guard \"al_get_current_display()\" not met";
         throw std::runtime_error(error_message.str());
      }
   float roundness = 20.0f;
   float border_thickness = 5.0f;
   float border_inner_padding = border_thickness * 3;
   ALLEGRO_COLOR fill_color = al_color_html("353636");
   ALLEGRO_COLOR border_color = al_color_html("cccccc");

   place.start_transform();
   al_draw_filled_rounded_rectangle(
      0 + border_inner_padding,
      0 + border_inner_padding,
      place.size.x - border_inner_padding,
      place.size.y - border_inner_padding,
      roundness * 0.6,
      roundness * 0.6,
      fill_color
   );
   al_draw_rounded_rectangle(0, 0, place.size.x, place.size.y, roundness, roundness, border_color, border_thickness);
   place.restore_transform();
   return;
}
} // namespace Krampus21


