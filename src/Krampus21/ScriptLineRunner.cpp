

#include <Krampus21/ScriptLineRunner.hpp>
#include <Blast/String/Trimmer.hpp>
#include <iostream>
#include <Blast/String/Trimmer.hpp>
#include <Blast/StringSplitter.hpp>
#include <vector>
#include <string>


namespace Krampus21
{


ScriptLineRunner::ScriptLineRunner()
   : dialog_factory({})
{
}


ScriptLineRunner::~ScriptLineRunner()
{
}


Krampus21::DialogBoxes::Base* ScriptLineRunner::parse_line_and_create_dialog(std::string script_line)
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

      // tokenize
      std::vector<std::string> tokens = tokenize(argument);

      // validate
      // expect at least 3 tokens
      assert_min_token_count(tokens, 3);
      // expect an odd number of tokens
      assert_odd_token_count(tokens);

      // first token is the prompt
      choice_prompt = tokens[0];
      // next consecutive tokens are (choice_text, choice_value) pairs
      for (unsigned i=2; i<tokens.size(); i+=2)
      {
         // TODO warning if token is empty
         choice_options.push_back({ tokens[i-1], tokens[i] });
      }

      //choice_options = { { "Boobar", "boobruhh" }, { "Zoozaz", "zazzle" } };
      created_dialog = dialog_factory.create_choice_dialog(choice_prompt, choice_options);
   }

   return created_dialog;
}

std::pair<std::string, std::string> ScriptLineRunner::parse_command_and_argument(std::string script_line)
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

std::map<std::string, int> ScriptLineRunner::build_markers_index(std::vector<std::string> script_lines)
{
   std::map<std::string, int> result;
   for (unsigned i=0; i<script_lines.size(); i++)
   {
      std::string script_line = script_lines[i];
      std::pair<std::string, std::string> command_and_argument = parse_command_and_argument(script_line);
      std::string command = command_and_argument.first;
      std::string argument = command_and_argument.second;
      int line_num = i+1;

      if (command == "MARKER")
      {
         // TODO ensure symbols don't appear multiple times
         if (result.find(argument) != result.end())
         {
            std::cout << "Krampus21/ScriptLineRunner::build_markers_index: WARNING: the marker "
                      << "\"" << argument << "\""
                      << "is being set on line " << line_num
                      << " but was already declared earlier on line " << result[argument] << ". "
                      << "Note that the marker will be overwritten to this new line number ("
                      << line_num << ").";
         }

         result[argument] = line_num;
      }
   }
   return result;
}

std::vector<std::string> ScriptLineRunner::tokenize(std::string str, char delim)
{
   std::vector<std::string> tokens = Blast::StringSplitter(str, delim).split();
   for (auto &token : tokens) token = Blast::String::Trimmer(token).trim();
   return tokens;
}

bool ScriptLineRunner::assert_min_token_count(std::vector<std::string> tokens, int min)
{
   return (tokens.size() >= min);
}

bool ScriptLineRunner::assert_odd_token_count(std::vector<std::string> tokens, int min)
{
   return (tokens.size() % 2);
}
} // namespace Krampus21


