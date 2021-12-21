

#include <Krampus21/Script.hpp>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{


Script::Script(std::vector<std::string> lines)
   : lines(lines)
   , current_line_num(-1)
   , markers_index({})
   , initialized(false)
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
   // TODO
   build_markers_index();
   current_line_num = 0; // TODO <- if not empty?
   initialized = true;
   return;
}

std::string Script::get_current_line_text()
{
   // TODO
   return "";
}

bool Script::at_end()
{
   // TODO
   return false;
}

void Script::build_markers_index()
{
   // TODO
   return;
}
} // namespace Krampus21


