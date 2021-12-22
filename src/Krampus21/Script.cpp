

#include <Krampus21/Script.hpp>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>
#include <Krampus21/ScriptLoader.hpp>


namespace Krampus21
{


Script::Script(std::vector<std::string> lines)
   : lines(lines)
   , current_line_num(-1)
   , markers_index({})
   , initialized(false)
   , finished(false)
{
}


Script::~Script()
{
}


void Script::initialize()
{
   if (!((!initialized)))
      {
         std::stringstream error_message;
         error_message << "Script" << "::" << "initialize" << ": error: " << "guard \"(!initialized)\" not met";
         throw std::runtime_error(error_message.str());
      }
   build_markers_index();
   if (!lines.empty())
   {
      current_line_num = 0;
      finished = true;
   }
   else
   {
      finished = false;
   }
   initialized = true;
   return;
}

std::string Script::get_current_line_text()
{
   if (!(initialized))
      {
         std::stringstream error_message;
         error_message << "Script" << "::" << "get_current_line_text" << ": error: " << "guard \"initialized\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!at_valid_line()) return "";
   return lines[current_line_num];
}

bool Script::goto_next_line()
{
   if (!(initialized))
      {
         std::stringstream error_message;
         error_message << "Script" << "::" << "goto_next_line" << ": error: " << "guard \"initialized\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (at_last_line())
   {
      current_line_num = -1;
      finished = true;
   }
   else
   {
      if (!at_valid_line()) return false;
      current_line_num++;
   }
   return !finished;
}

bool Script::goto_line_num(int line_num)
{
   if (!(initialized))
      {
         std::stringstream error_message;
         error_message << "Script" << "::" << "goto_line_num" << ": error: " << "guard \"initialized\" not met";
         throw std::runtime_error(error_message.str());
      }
   // TODO
   return false;
}

bool Script::at_last_line()
{
   if (!(initialized))
      {
         std::stringstream error_message;
         error_message << "Script" << "::" << "at_last_line" << ": error: " << "guard \"initialized\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!lines.empty() && current_line_num == (lines.size()-1));
}

bool Script::at_valid_line()
{
   if (lines.empty()) return false;
   if (current_line_num < 0) return false;
   if (current_line_num >= lines.size()) return false;
   return true;
}

void Script::build_markers_index()
{
   markers_index = Krampus21::ScriptLoader::build_markers_index(lines);
   return;
}
} // namespace Krampus21


