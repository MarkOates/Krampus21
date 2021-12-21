

#include <Krampus21/ScriptLoader.hpp>
#include <iostream>
#include <Blast/String/Trimmer.hpp>


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
      Krampus21::DialogBoxes::Base* created_dialog = parse_line_and_create_dialog(script_line);
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

Krampus21::DialogBoxes::Base* ScriptLoader::parse_line_and_create_dialog(std::string script_line)
{
   std::string DIALOG = "DIALOG";
   std::string CHOICE = "CHOICE";
   Krampus21::DialogBoxes::Base* created_dialog = nullptr;
   std::pair<std::string, std::string> command_and_argument = parse_command_and_argument(script_line);
   std::string command = command_and_argument.first;
   std::string argument = command_and_argument.second;

   if (command.empty() || command == DIALOG)
   {
      created_dialog = dialog_factory.create_basic_dialog(std::vector<std::string>{script_line});
   }
   else if (command == CHOICE)
   {
      std::string choice_prompt = "[coice-prompt-text-not-extracted]";
      std::vector<std::pair<std::string, std::string>> choice_options = {};
      choice_options = { { "Boobar", "boobruhh" }, { "Zoozaz", "zazzle" } };
      created_dialog = dialog_factory.create_choice_dialog(choice_prompt, choice_options);
   }

   return created_dialog;
}

std::pair<std::string, std::string> ScriptLoader::parse_command_and_argument(std::string script_line)
{
   std::pair<std::string, std::string> result{"", ""};
   std::string DELIMETER = ": ";

   std::size_t pos = script_line.find(DELIMETER);

   if (pos == std::string::npos)
   {
      result.first = "DIALOG";
      result.second = script_line;
   }
   else
   {
      std::string command_fragment_unsanitized = script_line.substr(0, pos);

      // TODO validate format of command (all caps, underscore, no spaces)
      // here

      result.first = Blast::String::Trimmer(command_fragment_unsanitized).trim();
      result.second = Blast::String::Trimmer(script_line.substr(pos+DELIMETER.size())).trim();
   }

   return result;
}
} // namespace Krampus21


