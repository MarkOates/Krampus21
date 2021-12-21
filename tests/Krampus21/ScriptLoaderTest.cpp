
#include <gtest/gtest.h>

#include <Krampus21/ScriptLoader.hpp>


TEST(Krampus21_ScriptLoaderTest, can_be_created_without_blowing_up)
{
   Krampus21::ScriptLoader script_loader;
}


TEST(Krampus21_ScriptLoaderTest, parse__will_parse_some_basic_dialog_lines)
{
   std::vector<std::string> script_lines = {
      "DIALOG: This is the most basic dialog.",
      "DIALOG: This is another basic dialog.",
   };
   Krampus21::ScriptLoader script_loader(script_lines);

   std::vector<Krampus21::DialogBoxes::Base*> parsed_script = script_loader.parse();

   EXPECT_EQ(2, parsed_script.size());
}


TEST(Krampus21_ScriptLoaderTest, parse__command_and_argument__will_not_blow_up_on_an_empty_line)
   // note this is a private method test
{
   std::string script_line = "";
   std::pair<std::string, std::string> parsed_command_argument_pair;
   Krampus21::ScriptLoader script_loader;

   parsed_command_argument_pair = script_loader.parse_command_and_argument(script_line);

   std::pair<std::string, std::string> expected_command_argument_pair = {"DIALOG", ""};

   EXPECT_EQ(expected_command_argument_pair, parsed_command_argument_pair);
}


TEST(Krampus21_ScriptLoaderTest, parse_command_and_argument__will_parse_a_script_line_into_an_expected_set_of_elements)
   // note this is a private method test
{
   std::string script_line = "DIALOG: This is the most basic dialog.";
   std::pair<std::string, std::string> parsed_command_argument_pair;
   Krampus21::ScriptLoader script_loader;

   parsed_command_argument_pair = script_loader.parse_command_and_argument(script_line);

   std::pair<std::string, std::string> expected_command_argument_pair = {"DIALOG", "This is the most basic dialog."};

   EXPECT_EQ(expected_command_argument_pair, parsed_command_argument_pair);
}


TEST(Krampus21_ScriptLoaderTest, parse_line_and_create_dialog__will_parse_a_DIALOG_command)
   // note this is a private method test
{
   std::string script_line = "DIALOG: This is the most basic dialog line.";
   Krampus21::ScriptLoader script_loader;

   Krampus21::DialogBoxes::Base* created_dialog = script_loader.parse_line_and_create_dialog(script_line);

   ASSERT_NE(nullptr, created_dialog);
   EXPECT_EQ(true, created_dialog->is_type("Basic"));
}


TEST(Krampus21_ScriptLoaderTest, parse__command_and_argument__will_trim_the_argument_fragment)
   // note this is a private method test
{
   std::string script_line = "  DIALOG  :  This is the most basic dialog that should be trimmed  \n  ";
   std::pair<std::string, std::string> parsed_command_argument_pair;
   Krampus21::ScriptLoader script_loader;

   parsed_command_argument_pair = script_loader.parse_command_and_argument(script_line);

   std::pair<std::string, std::string> expected_command_argument_pair = {
      "DIALOG",
      "This is the most basic dialog that should be trimmed",
   };

   EXPECT_EQ(expected_command_argument_pair, parsed_command_argument_pair);
}


