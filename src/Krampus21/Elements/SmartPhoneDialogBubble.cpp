

#include <Krampus21/Elements/SmartPhoneDialogBubble.hpp>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{
namespace Elements
{


SmartPhoneDialogBubble::SmartPhoneDialogBubble(AllegroFlare::FontBin* font_bin, std::string text, float width, float height, bool callout_on_left)
   : font_bin(font_bin)
   , text(text)
   , width(width)
   , height(height)
   , callout_on_left(callout_on_left)
{
}


SmartPhoneDialogBubble::~SmartPhoneDialogBubble()
{
}


void SmartPhoneDialogBubble::render()
{
   if (!(font_bin))
      {
         std::stringstream error_message;
         error_message << "SmartPhoneDialogBubble" << "::" << "render" << ": error: " << "guard \"font_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(al_is_primitives_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "SmartPhoneDialogBubble" << "::" << "render" << ": error: " << "guard \"al_is_primitives_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   //ALLEGRO_COLOR bubble_color = al_color_html("40669F");
   ALLEGRO_COLOR bubble_color = al_color_html("6F7C8F");
   ALLEGRO_COLOR text_color = al_color_name("white");
   float roundness = 32.0f;
   //if (roundness <= 10.0) roundness = 10.0;

   al_draw_filled_rounded_rectangle(0, 0, width, height, roundness, roundness, bubble_color);
   if (callout_on_left)
   {
      al_draw_filled_rectangle(0, height/2, height/2, height, bubble_color);
   }
   else
   {
      al_draw_filled_rectangle(width, height/2, width-height/2, height, bubble_color);
   }

   ALLEGRO_FONT *font = obtain_text_font();
   float padding_x = 30;
   float padding_y = 20;
   float text_box_width = width - padding_y * 2;
   float line_height = al_get_font_line_height(font);
   al_draw_multiline_text(
      font,
      text_color,
      padding_x,
      padding_y,
      text_box_width,
      line_height,
      ALLEGRO_ALIGN_LEFT,
      text.c_str()
   );

   return;
}

ALLEGRO_FONT* SmartPhoneDialogBubble::obtain_text_font()
{
   return font_bin->auto_get("Lato-Regular.ttf -48");
}
} // namespace Elements
} // namespace Krampus21


