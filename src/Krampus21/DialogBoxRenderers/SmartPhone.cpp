

#include <Krampus21/DialogBoxRenderers/SmartPhone.hpp>
#include <allegro5/allegro_primitives.h>
#include <AllegroFlare/Interpolators.hpp>
#include <Krampus21/Elements/SmartPhoneDialogBubble.hpp>
#include <AllegroFlare/Placement2D.hpp>


namespace Krampus21
{
namespace DialogBoxRenderers
{


SmartPhone::SmartPhone(AllegroFlare::FontBin* font_bin, float window_width, float window_height, std::vector<std::string> messages, float reveal_counter)
   : font_bin(font_bin)
   , window_width(window_width)
   , window_height(window_height)
   , messages(messages)
   , reveal_counter(reveal_counter)
   , draw_background_fill(false)
{
}


SmartPhone::~SmartPhone()
{
}


void SmartPhone::set_draw_background_fill(bool draw_background_fill)
{
   this->draw_background_fill = draw_background_fill;
}


bool SmartPhone::get_draw_background_fill()
{
   return draw_background_fill;
}


void SmartPhone::render()
{
   //int line = 0;
   float dialog_box_height = 180;
   float dialog_box_spacing = dialog_box_height + 30;
   AllegroFlare::Placement2D dialog_bubble_placement;
   float window_padding = 30;
   float bubble_width = window_width - window_padding * 2;

   float window_roundness = 22;
   if (draw_background_fill)
   {
      al_draw_filled_rounded_rectangle(
         0,
         0,
         window_width,
         window_height,
         window_roundness,
         window_roundness,
         ALLEGRO_COLOR{0, 0.08, 0.1, 0.95}
      );
   }

   for (unsigned i=0; i<messages.size(); i++)
   {
      float sanitized_reveal_counter = build_sanitized_reveal_counter();
      float y_reveal_offset = (1.0 - AllegroFlare::interpolator::tripple_fast_in(sanitized_reveal_counter))
                            * 80
                            + (1.0 - AllegroFlare::interpolator::tripple_fast_in(sanitized_reveal_counter))
                            * i * 20;
      float reveal_scale = AllegroFlare::interpolator::tripple_fast_in(sanitized_reveal_counter);
      float y_position = i * dialog_box_spacing + y_reveal_offset + window_padding;
      auto &message = messages[i];
      AllegroFlare::Placement2D dialog_bubble_placement{window_padding, y_position, 0, 0};
      dialog_bubble_placement.scale.y = 0.7 + reveal_scale * 0.3;

      dialog_bubble_placement.start_transform();
      Krampus21::Elements::SmartPhoneDialogBubble dialog_bubble_element(
         font_bin,
         message,
         bubble_width,
         dialog_box_height,
         true
      );
        //- name: font_bin
        //- name: text
        //- name: width
        //- name: height
        //- name: callout_on_left

      dialog_bubble_element.render();
      dialog_bubble_placement.restore_transform();
   }
   return;
}

float SmartPhone::build_sanitized_reveal_counter()
{
   float sanitized_reveal_counter = reveal_counter;
   if (sanitized_reveal_counter < 0.0) sanitized_reveal_counter = 0.0f;
   if (sanitized_reveal_counter >= 1.0) sanitized_reveal_counter = 1.0f;
   return sanitized_reveal_counter;
}
} // namespace DialogBoxRenderers
} // namespace Krampus21


