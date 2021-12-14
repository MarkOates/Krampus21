

#include <Krampus21/DialogBoxes/Basic.hpp>



namespace Krampus21
{
namespace DialogBoxes
{


Basic::Basic(std::vector<std::string> lines)
   : Krampus21::DialogBoxes::Base({})
   , lines(lines)
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


