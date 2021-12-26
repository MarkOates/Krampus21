

#include <Krampus21/DialogBoxRenderers/YouGotAnItemRenderer.hpp>
#include <allegro5/allegro_color.h>
#include <Krampus21/Elements/DialogBoxFrame.hpp>
#include <allegro_flare/placement2d.h>
#include <stdexcept>
#include <sstream>
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
   if (!(bitmap_bin))
      {
         std::stringstream error_message;
         error_message << "YouGotAnItemRenderer" << "::" << "render" << ": error: " << "guard \"bitmap_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   // style attributes
   ALLEGRO_COLOR fading_white = opaquify(ALLEGRO_COLOR{1, 1, 1, 1});
   ALLEGRO_FONT* notification_text_font = obtain_notification_text_font();
   ALLEGRO_FONT* item_name_text_font = obtain_item_name_text_font();
   float notification_text_font_line_heigt = al_get_font_line_height(notification_text_font);
   float item_name_text_font_line_heigt = al_get_font_line_height(item_name_text_font);
   ALLEGRO_COLOR text_color = opaquify(al_color_html("fbedc3"));
   std::string notification_text = "You got an item!";
   std::string item_name_text = "Watch";
   std::string item_bitmap_identifier = "watch-01.png";
   ALLEGRO_BITMAP* item_bitmap = bitmap_bin->auto_get(item_bitmap_identifier);
   Krampus21::Elements::DialogBoxFrame dialog_box_frame(width, height);
   dialog_box_frame.set_fill_color(opaquify(al_color_html("2a2104")));
   dialog_box_frame.set_border_color(opaquify(al_color_html("c49505")));
   allegro_flare::placement2d item_place(width/2, height/2, 800, 800);
   item_place.scale.x = 0.55;
   item_place.scale.y = 0.55;

   // animations
   float reveal_counter = get_live_reveal_counter();
   item_place.position.y += ((1.0 - reveal_counter) * 20);
   item_place.scale.x += item_place.scale.x * (0.2 * reveal_counter);
   item_place.scale.y += item_place.scale.y * (0.2 * reveal_counter);

   // draw the frame
   dialog_box_frame.render();

   // draw the notification text
   al_draw_text(
      notification_text_font,
      text_color,
      width/2,
      height/2 - 180,
      ALLEGRO_ALIGN_CENTER,
      notification_text.c_str()
   );

   // draw the item image
   item_place.start_transform();
   al_draw_tinted_bitmap(item_bitmap, fading_white, 0, 0, 0);
   item_place.restore_transform();

   // he collected item name
   al_draw_text(
      item_name_text_font,
      text_color,
      width/2,
      height/2 + 120,
      ALLEGRO_ALIGN_CENTER,
      item_name_text.c_str()
   );

   return;
}

float YouGotAnItemRenderer::get_live_reveal_counter()
{
   float age = you_got_an_item_dialog_box->infer_age();
   float time_duration_to_reveal = 0.8;
   if (age >= time_duration_to_reveal) age = time_duration_to_reveal;
   float reveal_duration_normalized = 1.0 - ((time_duration_to_reveal - age) / time_duration_to_reveal);
   //return 0.5;
   return reveal_duration_normalized;
}

ALLEGRO_FONT* YouGotAnItemRenderer::obtain_notification_text_font()
{
   if (!(al_is_font_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "YouGotAnItemRenderer" << "::" << "obtain_notification_text_font" << ": error: " << "guard \"al_is_font_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(al_is_ttf_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "YouGotAnItemRenderer" << "::" << "obtain_notification_text_font" << ": error: " << "guard \"al_is_ttf_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(font_bin))
      {
         std::stringstream error_message;
         error_message << "YouGotAnItemRenderer" << "::" << "obtain_notification_text_font" << ": error: " << "guard \"font_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   static const std::string FONT_IDENTIFIER = "Purista Medium.ttf -50";
   ALLEGRO_FONT* result_font = font_bin->operator[](FONT_IDENTIFIER);
   return result_font;
}

ALLEGRO_FONT* YouGotAnItemRenderer::obtain_item_name_text_font()
{
   return font_bin->auto_get("Lato-Bold.ttf -46");
}

ALLEGRO_COLOR YouGotAnItemRenderer::opaquify(ALLEGRO_COLOR color)
{
   //AllegroFlare::color::change_alpha(color, reveal_counter);
   //AllegroFlare::color::change_alpha(color, 1.0);
   float alpha = get_live_reveal_counter();
      color.a *= alpha;
      color.r *= color.a;
      color.g *= color.a;
      color.b *= color.a;
   return color;
}
} // namespace DialogBoxRenderers
} // namespace Krampus21


