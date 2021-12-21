

#include <Krampus21/DialogBoxRenderers/ChoiceRenderer.hpp>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{
namespace DialogBoxRenderers
{


ChoiceRenderer::ChoiceRenderer(AllegroFlare::FontBin* font_bin, Krampus21::DialogBoxes::Choice* choice_dialog_box, float width, float height)
   : font_bin(font_bin)
   , choice_dialog_box(choice_dialog_box)
   , width(width)
   , height(height)
{
}


ChoiceRenderer::~ChoiceRenderer()
{
}


void ChoiceRenderer::render()
{
   if (!(al_is_system_installed()))
      {
         std::stringstream error_message;
         error_message << "ChoiceRenderer" << "::" << "render" << ": error: " << "guard \"al_is_system_installed()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(choice_dialog_box))
      {
         std::stringstream error_message;
         error_message << "ChoiceRenderer" << "::" << "render" << ": error: " << "guard \"choice_dialog_box\" not met";
         throw std::runtime_error(error_message.str());
      }
   draw_frame();
   draw_prompt_text();
   return;
}

ALLEGRO_FONT* ChoiceRenderer::obtain_dialog_font()
{
   if (!(al_is_font_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "ChoiceRenderer" << "::" << "obtain_dialog_font" << ": error: " << "guard \"al_is_font_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(al_is_ttf_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "ChoiceRenderer" << "::" << "obtain_dialog_font" << ": error: " << "guard \"al_is_ttf_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(font_bin))
      {
         std::stringstream error_message;
         error_message << "ChoiceRenderer" << "::" << "obtain_dialog_font" << ": error: " << "guard \"font_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   static const std::string FONT_IDENTIFIER = "Purista Medium.ttf -50";
   ALLEGRO_FONT* result_font = font_bin->operator[](FONT_IDENTIFIER);
   return result_font;
}

std::string ChoiceRenderer::obtain_choice_dialog_box_prompt()
{
   if (!(choice_dialog_box))
      {
         std::stringstream error_message;
         error_message << "ChoiceRenderer" << "::" << "obtain_choice_dialog_box_prompt" << ": error: " << "guard \"choice_dialog_box\" not met";
         throw std::runtime_error(error_message.str());
      }
   return choice_dialog_box->get_prompt();
}

std::vector<std::pair<std::string, std::string>> ChoiceRenderer::obtain_choice_dialog_box_options()
{
   if (!(choice_dialog_box))
      {
         std::stringstream error_message;
         error_message << "ChoiceRenderer" << "::" << "obtain_choice_dialog_box_options" << ": error: " << "guard \"choice_dialog_box\" not met";
         throw std::runtime_error(error_message.str());
      }
   return choice_dialog_box->get_options();
}

int ChoiceRenderer::obtain_choice_dialog_box_cursor_position()
{
   if (!(choice_dialog_box))
      {
         std::stringstream error_message;
         error_message << "ChoiceRenderer" << "::" << "obtain_choice_dialog_box_cursor_position" << ": error: " << "guard \"choice_dialog_box\" not met";
         throw std::runtime_error(error_message.str());
      }
   return choice_dialog_box->get_cursor_position();
}

void ChoiceRenderer::draw_prompt_text()
{
   int dialog_box_num_revealed_characters = 999;
   std::string text = obtain_choice_dialog_box_prompt();
   float text_padding_x = 40.0f;
   float text_padding_y = 30.0f;
   float text_box_max_width = width - (text_padding_x * 2);
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

void ChoiceRenderer::draw_choices_with_cursor_and_current_selection()
{
   std::vector<std::pair<std::string, std::string>> options = obtain_choice_dialog_box_options();
   int current_selection_num = obtain_choice_dialog_box_cursor_position();

   int option_num = 0;
   for (auto &option : options)
   {
      option_num++;
   }
   return;
}

void ChoiceRenderer::draw_frame()
{
   float roundness = 18.0f;
   float border_thickness = 5.0f;
   float border_inner_padding = border_thickness * 3;
   ALLEGRO_COLOR fill_color = al_color_html("162428");
   //ALLEGRO_COLOR border_color = al_color_html("244751");
   al_draw_filled_rounded_rectangle(
      0 + border_inner_padding,
      0 + border_inner_padding,
      width - border_inner_padding,
      height - border_inner_padding,
      roundness * 0.5,
      roundness * 0.5,
      fill_color
   );
   return;
}

std::string ChoiceRenderer::concat_text(std::string source_text, int length)
{
   if (!(choice_dialog_box))
      {
         std::stringstream error_message;
         error_message << "ChoiceRenderer" << "::" << "concat_text" << ": error: " << "guard \"choice_dialog_box\" not met";
         throw std::runtime_error(error_message.str());
      }
   return source_text.substr(0, length);
}
} // namespace DialogBoxRenderers
} // namespace Krampus21


