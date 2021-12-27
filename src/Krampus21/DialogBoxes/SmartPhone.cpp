

#include <Krampus21/DialogBoxes/SmartPhone.hpp>



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


std::vector<std::string> SmartPhone::get_messages()
{
   return messages;
}


} // namespace DialogBoxes
} // namespace Krampus21


