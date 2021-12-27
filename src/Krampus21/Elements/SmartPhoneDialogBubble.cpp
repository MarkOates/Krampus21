

#include <Krampus21/Elements/SmartPhoneDialogBubble.hpp>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_color.h>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{
namespace Elements
{


SmartPhoneDialogBubble::SmartPhoneDialogBubble(std::string text, float width, float height)
   : text(text)
   , width(width)
   , height(height)
{
}


SmartPhoneDialogBubble::~SmartPhoneDialogBubble()
{
}


void SmartPhoneDialogBubble::render()
{
   if (!(al_is_primitives_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "SmartPhoneDialogBubble" << "::" << "render" << ": error: " << "guard \"al_is_primitives_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   ALLEGRO_COLOR bubble_color = al_color_name("dodgerblue");
   ALLEGRO_COLOR text_color = al_color_name("white");
   float roundness = height / 3;
   if (roundness <= 10.0) roundness = 10.0;

   al_draw_filled_rounded_rectangle(0, 0, width, height, roundness, roundness, bubble_color);
   return;
}
} // namespace Elements
} // namespace Krampus21


