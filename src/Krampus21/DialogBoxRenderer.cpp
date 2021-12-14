

#include <Krampus21/DialogBoxRenderer.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{


DialogBoxRenderer::DialogBoxRenderer(AllegroFlare::FontBin* font_bin, Krampus21::DialogBoxes::Base* dialog_box)
   : font_bin(font_bin)
   , dialog_box(dialog_box)
   , place({ 1920/2, 1080/3*2, 1920/2, 1080/3 })
   , default_font(nullptr)
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
   float roundness = 18.0f;
   float border_thickness = 5.0f;
   float border_inner_padding = border_thickness * 3;
   ALLEGRO_COLOR fill_color = al_color_html("162428");
   ALLEGRO_COLOR border_color = al_color_html("244751");
   std::string text = get_dialog_box_text();
   ALLEGRO_FONT* text_font = obtain_dialog_font();
   ALLEGRO_COLOR text_color = al_color_html("66a9bc");
   float text_padding_x = 40.0f;
   float text_padding_y = 30.0f;

   // draw backfill and border
   place.start_transform();
   al_draw_filled_rounded_rectangle(
      0 + border_inner_padding,
      0 + border_inner_padding,
      place.size.x - border_inner_padding,
      place.size.y - border_inner_padding,
      roundness * 0.5,
      roundness * 0.5,
      fill_color
   );
   al_draw_rounded_rectangle(0, 0, place.size.x, place.size.y, roundness, roundness, border_color, border_thickness);

   // draw text
   al_draw_text(text_font, text_color, text_padding_x, text_padding_y, ALLEGRO_ALIGN_LEFT, text.c_str());

   place.restore_transform();
   return;
}

std::string DialogBoxRenderer::get_dialog_box_text()
{
   if (!(dialog_box))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "get_dialog_box_text" << ": error: " << "guard \"dialog_box\" not met";
         throw std::runtime_error(error_message.str());
      }
   return "This is dummy dialog text.";
}

ALLEGRO_FONT* DialogBoxRenderer::obtain_dialog_font()
{
   if (!(al_is_font_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "obtain_dialog_font" << ": error: " << "guard \"al_is_font_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(al_is_ttf_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "obtain_dialog_font" << ": error: " << "guard \"al_is_ttf_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(font_bin))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "obtain_dialog_font" << ": error: " << "guard \"font_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   static const std::string FONT_IDENTIFIER = "Purista Medium.ttf -50";
   ALLEGRO_FONT* result_font = font_bin->operator[](FONT_IDENTIFIER);
   return result_font;
}
} // namespace Krampus21


