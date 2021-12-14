

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
{
}


DialogBoxRenderer::~DialogBoxRenderer()
{
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
   al_draw_filled_rounded_rectangle(0, 0, 100, 200, 4.0, 4.0, al_color_name("green"));
   return;
}
} // namespace Krampus21


