

#include <Krampus21/DialogBoxes/Choice.hpp>



namespace Krampus21
{
namespace DialogBoxes
{


Choice::Choice()
   : Krampus21::DialogBoxes::Base("Choice")
   , prompt("[prompt-question-not-set]")
   , options({})
   , cursor_position(-1)
{
}


Choice::~Choice()
{
}


} // namespace DialogBoxes
} // namespace Krampus21


