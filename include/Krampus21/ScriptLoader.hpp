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
      Krampus21::DialogBoxes::Base* parse_line_and_create_dialog(std::string script_line={});
      std::pair<std::string, std::string> parse_command_and_argument(std::string script_line={});
      static std::vector<std::string> tokenize(std::string str="", char delim='|');
      static bool assert_min_token_count(std::vector<std::string> tokens={}, int min=0);
      static bool assert_odd_token_count(std::vector<std::string> tokens={}, int min=0);
   };
}



