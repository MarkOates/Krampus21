

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
   place.start_transform();
   al_draw_filled_rounded_rectangle(0, 0, place.size.x, place.size.y, 4.0, 4.0, al_color_name("green"));
   place.restore_transform();
   return;
}
} // namespace Krampus21


