

#include <Krampus21/ScriptLoader.hpp>



namespace Krampus21
{


ScriptLoader::ScriptLoader(std::vector<std::string> script_lines)
   : script_lines(script_lines)
{
}


ScriptLoader::~ScriptLoader()
{
}


std::string ScriptLoader::parse()
{
   return "Hello World!";
}
} // namespace Krampus21


