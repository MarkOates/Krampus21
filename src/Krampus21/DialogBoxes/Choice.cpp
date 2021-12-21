

#include <Krampus21/DialogBoxes/Choice.hpp>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{
namespace DialogBoxes
{


Choice::Choice(std::string prompt, std::vector<std::pair<std::string, std::string>> options)
   : Krampus21::DialogBoxes::Base("Choice")
   , prompt(prompt)
   , options(options)
   , cursor_position(-1)
   , initialized(false)
{
}


Choice::~Choice()
{
}


int Choice::get_cursor_position()
{
   return cursor_position;
}


void Choice::initialize()
{
   if (!((!initialized)))
      {
         std::stringstream error_message;
         error_message << "Choice" << "::" << "initialize" << ": error: " << "guard \"(!initialized)\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (options.empty())
   {
      // do nothing
   }
   else
   {
      cursor_position = 0;
   }
   initialized = true;
   return;
}

void Choice::move_cursor_position_down()
{
   if (!(initialized))
      {
         std::stringstream error_message;
         error_message << "Choice" << "::" << "move_cursor_position_down" << ": error: " << "guard \"initialized\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!has_valid_cursor_position()) return;

   cursor_position++;
   if (cursor_position >= options.size()) cursor_position = cursor_position % options.size();
   return;
}

void Choice::move_cursor_position_up()
{
   if (!(initialized))
      {
         std::stringstream error_message;
         error_message << "Choice" << "::" << "move_cursor_position_up" << ": error: " << "guard \"initialized\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!has_valid_cursor_position()) return;

   cursor_position--;
   if (cursor_position < 0) cursor_position = (cursor_position + (options.size() * 100)) % options.size();
   return;
}

bool Choice::has_valid_cursor_position()
{
   return (cursor_position != -1);
}
} // namespace DialogBoxes
} // namespace Krampus21


