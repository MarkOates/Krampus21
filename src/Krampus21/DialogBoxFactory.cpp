

#include <Krampus21/DialogBoxFactory.hpp>
#include <Krampus21/DialogBoxes/Basic.hpp>


namespace Krampus21
{


DialogBoxFactory::DialogBoxFactory()
{
}


DialogBoxFactory::~DialogBoxFactory()
{
}


Krampus21::DialogBoxes::Base* DialogBoxFactory::create_basic_dialog_box(std::vector<std::string> lines)
{
   Krampus21::DialogBoxes::Basic *dialog_box = new Krampus21::DialogBoxes::Basic;
   return dialog_box;
}
} // namespace Krampus21


