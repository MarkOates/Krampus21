

#include <Krampus21/ScriptLoader.hpp>



namespace Krampus21
{


ScriptLoader::ScriptLoader(std::vector<std::string> script_lines)
   : script_lines(script_lines)
   , dialog_factory({})
{
}


ScriptLoader::~ScriptLoader()
{
}


std::vector<Krampus21::DialogBoxes::Base*> ScriptLoader::parse()
{
   std::vector<Krampus21::DialogBoxes::Base*> result = {
      dialog_factory.create_basic_test_dialog(),
      dialog_factory.create_basic_test_dialog(),
      dialog_factory.create_basic_test_dialog(),
   };
   return result;
}
} // namespace Krampus21


