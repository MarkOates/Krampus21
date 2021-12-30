

#include <Krampus21/DialogBoxRenderer.hpp>
#include <allegro_flare/placement2d.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <Krampus21/Elements/DialogBoxFrame.hpp>
#include <Krampus21/DialogBoxes/Choice.hpp>
#include <Krampus21/DialogBoxes/YouGotAnItem.hpp>
#include <Krampus21/DialogBoxes/SmartPhone.hpp>
#include <Krampus21/DialogBoxes/TitleText.hpp>
#include <Krampus21/DialogBoxRenderers/ChoiceRenderer.hpp>
#include <Krampus21/DialogBoxRenderers/YouGotAnItemRenderer.hpp>
#include <Krampus21/DialogBoxRenderers/SmartPhone.hpp>
#include <Krampus21/Titles/Slate.hpp>
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


DialogBoxRenderer::DialogBoxRenderer(AllegroFlare::FontBin* font_bin, AllegroFlare::BitmapBin* bitmap_bin, Krampus21::DialogBoxes::Base* dialog_box)
   : font_bin(font_bin)
   , bitmap_bin(bitmap_bin)
   , dialog_box(dialog_box)
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
   if (!(al_get_current_display()))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "render" << ": error: " << "guard \"al_get_current_display()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(dialog_box))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "render" << ": error: " << "guard \"dialog_box\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(al_is_font_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "render" << ": error: " << "guard \"al_is_font_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(al_is_ttf_addon_initialized()))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "render" << ": error: " << "guard \"al_is_ttf_addon_initialized()\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(font_bin))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "render" << ": error: " << "guard \"font_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (dialog_box->is_type("Choice"))
   {
      allegro_flare::placement2d place{ 1920/2, 1080/5*4, 1920/5*3, 1080/4 };

      float width = place.size.x;
      float height = place.size.y;
      place.start_transform();
      Krampus21::DialogBoxes::Choice* choice_dialog_box = static_cast<Krampus21::DialogBoxes::Choice*>(dialog_box);
      Krampus21::DialogBoxRenderers::ChoiceRenderer(font_bin, bitmap_bin, choice_dialog_box, width, height).render();
      place.restore_transform();
   }
   else if (dialog_box->is_type("TitleText"))
   {
      Krampus21::DialogBoxes::TitleText* title_text_dialog_box =
         static_cast<Krampus21::DialogBoxes::TitleText*>(dialog_box);
      std::string primary_text = title_text_dialog_box->get_primary_text();
      Krampus21::Titles::Slate slate_title(font_bin, primary_text, "");
      slate_title.set_primary_text_kerning(1);
      slate_title.render();
   }
   else if (dialog_box->is_type("SmartPhone"))
   {
      float dialog_window_width = 820;
      float dialog_window_height = 450;
      allegro_flare::placement2d place{ 1920/2 + 200, 1080/2, dialog_window_width, dialog_window_height };
      Krampus21::DialogBoxes::SmartPhone* smart_phone_dialog_box =
         static_cast<Krampus21::DialogBoxes::SmartPhone*>(dialog_box);
      std::vector<std::string> messages = smart_phone_dialog_box->get_messages();
      float reveal_counter = smart_phone_dialog_box->infer_age() * 2;

      place.start_transform();
      Krampus21::DialogBoxRenderers::SmartPhone smart_phone_dialog_box_renderer(
         font_bin,
         dialog_window_width,
         dialog_window_height,
         messages,
         reveal_counter
      );
      smart_phone_dialog_box_renderer.render();
      place.restore_transform();
   }
   else if (dialog_box->is_type("YouGotAnItem"))
   {
      allegro_flare::placement2d place{ 1920/2, 1080/2, 400, 420 };

      float width = place.size.x;
      float height = place.size.y;
      place.start_transform();
      Krampus21::DialogBoxes::YouGotAnItem* you_got_an_item_dialog_box =
         static_cast<Krampus21::DialogBoxes::YouGotAnItem*>(dialog_box);
      float age = you_got_an_item_dialog_box->infer_age();
      std::string item_name = you_got_an_item_dialog_box->get_item_name();
      std::string item_bitmap_identifier = you_got_an_item_dialog_box->get_item_bitmap_identifier();
      Krampus21::DialogBoxRenderers::YouGotAnItemRenderer you_got_an_item_dialog_box_renderer(
         font_bin,
         bitmap_bin,
         item_name,
         item_bitmap_identifier,
         age,
         width, height
      );
      you_got_an_item_dialog_box_renderer.render();
      place.restore_transform();
   }
   else if (dialog_box->is_type("Basic"))
   {
   //   // Note: BasicRenderer does not exist
   //   // probably... place.start_transform();
   //   //Krampus21::DialogBoxes::Basic* basic_dialog_box = static_cast<Krampus21::DialogBoxes::Basic*>(dalog_box);
   //   //Krampus21::DialogBoxRenderers::BasicRenderer(basic_dialog_box).render();
   //   //place.restore_transform();
   //
   //   // Instead:
   // draw frame
      allegro_flare::placement2d place{ 1920/2, 1080/5*4, 1920/5*3, 1080/4 };

      place.start_transform();
      Krampus21::Elements::DialogBoxFrame(place.size.x, place.size.y).render();

      if (dialog_box->get_finished())
      {
         draw_special_state_empty_text(place.size.x, place.size.y);
      }
      else
      {
         draw_styled_revealed_text(place.size.x);

         // draw the player's action cursor thing at the bottom
         int current_dialog_box_page_character_count = dialog_box->get_current_page_text().length();
         int num_revealed_characters = obtain_dialog_box_num_revealed_characters();
         if (num_revealed_characters >= current_dialog_box_page_character_count)
         {
            //if (dialog_box->at_last_page()) draw_action_text("[close]", place.size.x, place.size.y);
            draw_action_text(">>", place.size.x, place.size.y);
         }
      }

      place.restore_transform();
   }
   else
   {
      // TODO
      //std::cout << "Unrecognized dialog box type:: " + dialog_box->get_type();
      //throw std::runtime_error("Unrecognized dialog box type:: " + dialog_box->get_type());
   }

   return;
}

void DialogBoxRenderer::draw_special_state_empty_text(float width, float height)
{
   ALLEGRO_FONT* text_font = obtain_dialog_font();
   ALLEGRO_COLOR text_color = al_color_name("darkslategray");
   float line_height = al_get_font_line_height(text_font);
   std::string text = "[dialog finished]";
   al_draw_text(
      text_font,
      text_color,
      width * 0.5,
      height * 0.5 - line_height * 0.5,
      ALLEGRO_ALIGN_CENTER,
      text.c_str()
   );
   return;
}

void DialogBoxRenderer::draw_action_text(std::string text, float width, float height)
{
   ALLEGRO_FONT* text_font = obtain_dialog_font();
   ALLEGRO_COLOR text_color = al_color_html("66a9bc");
   float line_height = al_get_font_line_height(text_font);
   al_draw_text(
      text_font,
      text_color,
      width-20,
      height-line_height-10,
      ALLEGRO_ALIGN_RIGHT,
      text.c_str()
   );
   return;
}

void DialogBoxRenderer::draw_styled_revealed_text(float max_width)
{
   std::string text = obtain_dialog_box_text();
   float text_padding_x = 40.0f;
   float text_padding_y = 30.0f;
   float text_box_max_width = max_width - (text_padding_x * 2);
   ALLEGRO_FONT* text_font = obtain_dialog_font();
   float line_height = al_get_font_line_height(text_font);
   //ALLEGRO_COLOR text_color = al_color_html("66a9bc");
   ALLEGRO_COLOR text_color = al_color_name("skyblue");
   int num_revealed_characters = obtain_dialog_box_num_revealed_characters();

   al_draw_multiline_text(
      text_font,
      text_color,
      text_padding_x,
      text_padding_y,
      text_box_max_width,
      line_height,
      ALLEGRO_ALIGN_LEFT,
      concat_text(text, num_revealed_characters).c_str()
   );
   return;
}

std::string DialogBoxRenderer::obtain_dialog_box_text()
{
   if (!(dialog_box))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "obtain_dialog_box_text" << ": error: " << "guard \"dialog_box\" not met";
         throw std::runtime_error(error_message.str());
      }
   return dialog_box->get_current_page_text();
}

int DialogBoxRenderer::obtain_dialog_box_num_revealed_characters()
{
   if (!(dialog_box))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "obtain_dialog_box_num_revealed_characters" << ": error: " << "guard \"dialog_box\" not met";
         throw std::runtime_error(error_message.str());
      }
   return dialog_box->get_num_revealed_characters();
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


