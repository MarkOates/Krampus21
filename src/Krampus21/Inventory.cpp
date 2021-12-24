

#include <Krampus21/Inventory.hpp>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{


Inventory::Inventory()
   : af_inventory(nullptr)
{
}


Inventory::~Inventory()
{
}


void Inventory::render()
{
   if (!(af_inventory))
      {
         std::stringstream error_message;
         error_message << "Inventory" << "::" << "render" << ": error: " << "guard \"af_inventory\" not met";
         throw std::runtime_error(error_message.str());
      }
   return;
}
} // namespace Krampus21


