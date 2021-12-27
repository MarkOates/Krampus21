

#include <Krampus21/DialogBoxes/SmartPhone.hpp>
#include <Krampus21/Elements/SmartPhoneDialogBubble.hpp>


namespace Krampus21
{
namespace DialogBoxes
{


SmartPhone::SmartPhone(std::vector<std::string> messages)
   : Krampus21::DialogBoxes::Base("SmartPhone")
   , messages(messages)
{
}


SmartPhone::~SmartPhone()
{
}


void SmartPhone::render()
{
   // TODO
   // render smart phone dialog
   //Krampus21::Elements::SmartPhoneDialogBubble dialog_bubble_element(text);
   //dialog_bubble_elemenet.render();
   return;
}
} // namespace DialogBoxes
} // namespace Krampus21


