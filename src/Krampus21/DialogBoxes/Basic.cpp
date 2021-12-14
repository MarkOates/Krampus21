

#include <Krampus21/DialogBoxes/Basic.hpp>



namespace Krampus21
{
namespace DialogBoxes
{


Basic::Basic()
   : Krampus21::DialogBoxes::Base({})
{
}


Basic::~Basic()
{
}


std::string Basic::run()
{
   return "Hello World!";
}
} // namespace DialogBoxes
} // namespace Krampus21


