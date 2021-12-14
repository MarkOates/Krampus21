

#include <Krampus21/DialogBoxRenderer.hpp>
#include <Blast/StringJoiner.hpp>
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
#include <stdexcept>
#include <sstream>


namespace Krampus21
{


DialogBoxRenderer::DialogBoxRenderer(AllegroFlare::FontBin* font_bin, Krampus21::DialogBoxes::Base* dialog_box, int dialog_box_num_revealed_characters)
   : font_bin(font_bin)
   , dialog_box(dialog_box)
   , dialog_box_num_revealed_characters(dialog_box_num_revealed_characters)
   , place({ 1920/2, 1080/4*3, 1920/2, 1080/4 })
   , showing_next_cursor(false)
   , showing_close_cursor(true)
{
}


DialogBoxRenderer::~DialogBoxRenderer()
{
}


void DialogBoxRenderer::set_showing_next_cursor(bool showing_next_cursor)
{
   this->showing_next_cursor = showing_next_cursor;
}


void DialogBoxRenderer::set_showing_close_cursor(bool showing_close_cursor)
{
   this->showing_close_cursor = showing_close_cursor;
}


int DialogBoxRenderer::get_dialog_box_num_revealed_characters()
{
   return dialog_box_num_revealed_characters;
}


allegro_flare::placement2d DialogBoxRenderer::get_place()
{
   return place;
}


bool DialogBoxRenderer::get_showing_next_cursor()
{
   return showing_next_cursor;
}


bool DialogBoxRenderer::get_showing_close_cursor()
{
   return showing_close_cursor;
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

   draw_styled_revealed_text();

   if (get_showing_next_cursor())
   {
      show_action_text(">>");
   }
   if (get_showing_close_cursor())
   {
      show_action_text("[close]");
   }

   place.restore_transform();
   return;
}

void DialogBoxRenderer::show_action_text(std::string text)
{
   ALLEGRO_FONT* text_font = obtain_dialog_font();
   ALLEGRO_COLOR text_color = al_color_html("66a9bc");
   float line_height = al_get_font_line_height(text_font);
   al_draw_text(
      text_font,
      text_color,
      place.size.x-20,
      place.size.y-line_height-10,
      ALLEGRO_ALIGN_RIGHT,
      text.c_str()
   );
   return;
}

void DialogBoxRenderer::draw_styled_revealed_text()
{
   std::string text = Blast::StringJoiner(get_dialog_box_lines(), "\n").join();
   float text_padding_x = 40.0f;
   float text_padding_y = 30.0f;
   float text_box_max_width = place.size.x - (text_padding_x * 2);
   ALLEGRO_FONT* text_font = obtain_dialog_font();
   float line_height = al_get_font_line_height(text_font);
   ALLEGRO_COLOR text_color = al_color_html("66a9bc");

   al_draw_multiline_text(
      text_font,
      text_color,
      text_padding_x,
      text_padding_y,
      text_box_max_width,
      line_height,
      ALLEGRO_ALIGN_LEFT,
      concat_text(text, dialog_box_num_revealed_characters).c_str()
   );
   return;
}

std::vector<std::string> DialogBoxRenderer::get_dialog_box_lines()
{
   if (!(dialog_box))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "get_dialog_box_lines" << ": error: " << "guard \"dialog_box\" not met";
         throw std::runtime_error(error_message.str());
      }
   return dialog_box->get_current_page_lines();
}

std::string DialogBoxRenderer::concat_text(std::string source_text, int length)
{
   if (!(dialog_box))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "concat_text" << ": error: " << "guard \"dialog_box\" not met";
         throw std::runtime_error(error_message.str());
      }
   return source_text.substr(0, length);
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


