

#include <Krampus21/Elements/SmartPhone.hpp>
#include <Krampus21/Elements/SmartPhoneDialogBubble.hpp>


namespace Krampus21
{
namespace Elements
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
   int line = 0;
   for (unsigned i=0; i<messages.size(); i++)
   {
      auto &message = messages[i];
      Krampus21::Elements::SmartPhoneDialogBubble dialog_bubble_element(font_bin, message, width, 180);
        //- name: font_bin
        //- name: text
        //- name: width
        //- name: height
        //- name: callout_on_left

      dialog_bubble_element.render();
   }
   return;
}
} // namespace Elements
} // namespace Krampus21


