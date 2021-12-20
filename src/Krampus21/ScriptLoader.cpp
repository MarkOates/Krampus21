

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
   std::vector<Krampus21::DialogBoxes::Base*> result;

   for (auto &script_line : script_lines)
   {
      Krampus21::DialogBoxes::Base* created_dialog = nullptr;

      // parse the line and build the dialog
      created_dialog = dialog_factory.create_basic_dialog(std::vector<std::string>{script_line});

      result.push_back(created_dialog);
   }

   return result;
}
} // namespace Krampus21


