

#include <Krampus21/DialogBoxes/SmartPhone.hpp>
#include <allegro5/allegro.h>


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


float SmartPhone::infer_age()
{
   return al_get_time() - get_created_at();
}
} // namespace DialogBoxes
} // namespace Krampus21


