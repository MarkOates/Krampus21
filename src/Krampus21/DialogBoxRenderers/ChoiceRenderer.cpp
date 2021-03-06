

#include <Krampus21/DialogBoxRenderers/ChoiceRenderer.hpp>
#include <Krampus21/Elements/DialogBoxFrame.hpp>
#include <stdexcept>
#include <sstream>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_primitives.h>
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


namespace Krampus21
{
namespace DialogBoxRenderers
{


ChoiceRenderer::ChoiceRenderer(AllegroFlare::FontBin* font_bin, AllegroFlare::BitmapBin* bitmap_bin, Krampus21::DialogBoxes::Choice* choice_dialog_box, float width, float height)
   : font_bin(font_bin)
   , bitmap_bin(bitmap_bin)
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
   Krampus21::Elements::DialogBoxFrame(width, height).render();
   draw_prompt_text();
   draw_choices_with_cursor_and_current_selection(85);
   return;
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

void ChoiceRenderer::draw_choices_with_cursor_and_current_selection(float start_y)
{
   ALLEGRO_FONT* text_font = obtain_dialog_font();
   std::vector<std::pair<std::string, std::string>> options = obtain_choice_dialog_box_options();
   int current_selection_num = obtain_choice_dialog_box_cursor_position();
   float line_height = al_get_font_line_height(text_font);
   ALLEGRO_COLOR text_color = al_color_html("66a9bc");
   ALLEGRO_COLOR selection_hilight_color = ALLEGRO_COLOR{0.1, 0.1, 0.1, 0.1};
   float selection_box_x_padding = 18;
   float selection_box_y_padding = 0;
   float x = 200;

   int option_num = 0;
   for (auto &option : options)
   {
      bool this_option_is_currently_selected = (option_num == current_selection_num);
      std::string option_text = option.first;
      if (this_option_is_currently_selected)
      {
         float text_width = al_get_text_width(text_font, option_text.c_str());
         al_draw_filled_rectangle(
            x - selection_box_x_padding,
            start_y - selection_box_y_padding + option_num * line_height,
            x+text_width + selection_box_x_padding,
            start_y+line_height + selection_box_y_padding + option_num * line_height,
            selection_hilight_color
         );
      }
      al_draw_text(
         text_font,
         text_color,
         x,
         start_y + line_height*option_num,
         ALLEGRO_ALIGN_LEFT,
         option_text.c_str()
      );
      option_num++;
   }
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


