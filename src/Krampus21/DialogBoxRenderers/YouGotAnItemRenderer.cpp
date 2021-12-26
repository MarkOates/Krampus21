

#include <Krampus21/DialogBoxRenderers/YouGotAnItemRenderer.hpp>
#include <allegro5/allegro_color.h>
#include <Krampus21/Elements/DialogBoxFrame.hpp>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{
namespace DialogBoxRenderers
{


YouGotAnItemRenderer::YouGotAnItemRenderer(AllegroFlare::FontBin* font_bin, AllegroFlare::BitmapBin* bitmap_bin, Krampus21::DialogBoxes::YouGotAnItem* you_got_an_item_dialog_box, float width, float height)
   : font_bin(font_bin)
   , bitmap_bin(bitmap_bin)
   , you_got_an_item_dialog_box(you_got_an_item_dialog_box)
   , width(width)
   , height(height)
{
}


YouGotAnItemRenderer::~YouGotAnItemRenderer()
{
}


void YouGotAnItemRenderer::render()
{
   Krampus21::Elements::DialogBoxFrame dialog_box_renderer;
   dialog_box_renderer.render();

   ALLEGRO_FONT* font = obtain_dialog_font();
   ALLEGRO_COLOR text_color = al_color_html("fbedc3");
   std::string notification_text = "You got an item!";
   al_draw_text(font, text_color, width/2, height/2, ALLEGRO_ALIGN_CENTER, notification_text.c_str());
   return;
}

ALLEGRO_FONT* YouGotAnItemRenderer::obtain_dialog_font()
{
   if (!(al_is_font_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "YouGotAnItemRenderer" << "::" << "obtain_dialog_font" << ": error: " << "guard \"al_is_font_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(al_is_ttf_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "YouGotAnItemRenderer" << "::" << "obtain_dialog_font" << ": error: " << "guard \"al_is_ttf_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(font_bin))
      {
         std::stringstream error_message;
         error_message << "YouGotAnItemRenderer" << "::" << "obtain_dialog_font" << ": error: " << "guard \"font_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   static const std::string FONT_IDENTIFIER = "Purista Medium.ttf -50";
   ALLEGRO_FONT* result_font = font_bin->operator[](FONT_IDENTIFIER);
   return result_font;
}
} // namespace DialogBoxRenderers
} // namespace Krampus21


