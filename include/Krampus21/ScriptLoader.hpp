#pragma once


#include <Krampus21/DialogBoxes/Base.hpp>
#include <Krampus21/DialogFactory.hpp>
#include <string>
#include <utility>
#include <vector>


namespace Krampus21
{
   class ScriptLoader
   {
   private:
      std::vector<std::string> script_lines;
      Krampus21::DialogFactory dialog_factory;

   public:
      ScriptLoader(std::vector<std::string> script_lines={});
      ~ScriptLoader();

      std::vector<Krampus21::DialogBoxes::Base*> parse();
      Krampus21::DialogBoxes::Base* parse_line_and_build_dialog(std::string script_line={});
      std::pair<std::string, std::string> parse_command_and_argument(std::string script_line={});
   };
}



