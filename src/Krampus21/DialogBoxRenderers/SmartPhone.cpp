

#include <Krampus21/DialogBoxRenderers/SmartPhone.hpp>
#include <Krampus21/Elements/SmartPhoneDialogBubble.hpp>
#include <allegro_flare/placement2d.h>


namespace Krampus21
{
namespace DialogBoxRenderers
{


SmartPhone::SmartPhone(AllegroFlare::FontBin* font_bin, float width, float height, std::vector<std::string> messages)
   : font_bin(font_bin)
   , width(width)
   , height(height)
   , messages(messages)
{
}


SmartPhone::~SmartPhone()
{
}


void SmartPhone::render()
{
   //int line = 0;
   float dialog_box_height = 140;
   float dialog_box_spacing = dialog_box_height + 30;
   allegro_flare::placement2d dialog_bubble_placement;
   for (unsigned i=0; i<messages.size(); i++)
   {
      float y_position = i * dialog_box_spacing;
      auto &message = messages[i];
      allegro_flare::placement2d dialog_bubble_placement{0, y_position, 0, 0};

      dialog_bubble_placement.start_transform();
      Krampus21::Elements::SmartPhoneDialogBubble dialog_bubble_element(
         font_bin,
         message,
         width,
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
} // namespace DialogBoxRenderers
} // namespace Krampus21


