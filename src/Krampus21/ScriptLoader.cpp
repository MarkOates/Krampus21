

#include <Krampus21/ScriptLoader.hpp>
#include <iostream>


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

   int line_num = 0;
   for (auto &script_line : script_lines)
   {
      Krampus21::DialogBoxes::Base* created_dialog = parse_line_and_build_dialog(script_line);
      if (!created_dialog)
      {
         std::cout << "Script loading/parsing error on line [" << line_num << "]" << std::endl;
      }
      else
      {
         result.push_back(created_dialog);
      }
      line_num++;
   }

   return result;
}

Krampus21::DialogBoxes::Base* ScriptLoader::parse_line_and_build_dialog(std::string script_line)
{
   std::string DIALOG = "DIALOG";
   Krampus21::DialogBoxes::Base* created_dialog = nullptr;

   std::string commandment = DIALOG;
   std::string arguments = "";

   if (commandment == DIALOG)
   {
      created_dialog = dialog_factory.create_basic_dialog(std::vector<std::string>{script_line});
   }

   return created_dialog;
}
} // namespace Krampus21


