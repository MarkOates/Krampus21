

#include <Krampus21/Inventory.hpp>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{


Inventory::Inventory()
   : inventory(nullptr)
{
}


Inventory::~Inventory()
{
}


void Inventory::render()
{
   if (!(inventory))
      {
         std::stringstream error_message;
         error_message << "Inventory" << "::" << "render" << ": error: " << "guard \"inventory\" not met";
         throw std::runtime_error(error_message.str());
      }
   return;
}
} // namespace Krampus21


