

#include <Krampus21/DialogBoxRenderers/YouGotAnItemRenderer.hpp>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{
namespace DialogBoxRenderers
{


YouGotAnItemRenderer::YouGotAnItemRenderer(AllegroFlare::FontBin* font_bin, AllegroFlare::BitmapBin* bitmap_bin, Krampus21::DialogBoxes::YouGotAnItem* you_got_an_item_dialog_box)
   : font_bin(font_bin)
   , bitmap_bin(bitmap_bin)
   , you_got_an_item_dialog_box(you_got_an_item_dialog_box)
{
}


YouGotAnItemRenderer::~YouGotAnItemRenderer()
{
}


void YouGotAnItemRenderer::render()
{
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


