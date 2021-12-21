
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
   EXPECT_EQ("Basic", created_dialog->get_type());
}


TEST(Krampus21_ScriptLoaderTest, parse_line_and_create_dialog__will_parse_a_CHOICE_command)
   // note this is a private method test
{
   std::string script_line = "CHOICE: This is the most basic dialog line.";
   Krampus21::ScriptLoader script_loader;

   Krampus21::DialogBoxes::Base* created_dialog = script_loader.parse_line_and_create_dialog(script_line);

   ASSERT_NE(nullptr, created_dialog);
   EXPECT_EQ("Choice", created_dialog->get_type());
   EXPECT_EQ("Choice", created_dialog->get_type());
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


TEST(Krampus21_ScriptLoaderTest, tokenize__will_split_a_source_string_into_trimmed_tokens)
   // note this is a private method test
{
   std::string source_string = "  Voo| do |daah || \t dang ";
   std::vector<std::string> expected_tokens = { "Voo", "do", "daah", "", "dang" };
   std::vector<std::string> actual_tokens = Krampus21::ScriptLoader::tokenize(source_string);
   EXPECT_EQ(expected_tokens, actual_tokens);
}


TEST(Krampus21_ScriptLoaderTest, assert_min_token_count__will_return_true_if_there_are_at_least_n_tokens)
{
   ASSERT_EQ(true, Krampus21::ScriptLoader::assert_min_token_count({}, 0));
   ASSERT_EQ(true, Krampus21::ScriptLoader::assert_min_token_count({ "t1", "t2", "t3" }, 3));
   ASSERT_EQ(true, Krampus21::ScriptLoader::assert_min_token_count({ "t1", "t2", "t3", "t4" }, 2));
}

TEST(Krampus21_ScriptLoaderTest, assert_min_token_count__will_return_false_if_there_are_less_than_n_tokens)
{
   ASSERT_EQ(false, Krampus21::ScriptLoader::assert_min_token_count({}, 1));
   ASSERT_EQ(false, Krampus21::ScriptLoader::assert_min_token_count({ "t1", "t2", "t3" }, 4));
   ASSERT_EQ(false, Krampus21::ScriptLoader::assert_min_token_count({ "t1", "t2", "t3", "t4" }, 999));
}

TEST(Krampus21_ScriptLoaderTest, assert_odd_token_count__will_return_true_if_the_number_of_tokens_is_odd)
{
   ASSERT_EQ(true, Krampus21::ScriptLoader::assert_min_token_count({ "t1" }));
   ASSERT_EQ(true, Krampus21::ScriptLoader::assert_min_token_count({ "t1", "t2", "t3" }));
   ASSERT_EQ(true, Krampus21::ScriptLoader::assert_min_token_count({ "t1", "t2", "t3", "t4", "t5", "t6", "t7" }));
}

TEST(Krampus21_ScriptLoaderTest, assert_odd_token_count__will_return_false_if_the_number_of_tokens_is_not_odd)
{
   ASSERT_EQ(false, Krampus21::ScriptLoader::assert_odd_token_count({ }));
   ASSERT_EQ(false, Krampus21::ScriptLoader::assert_odd_token_count({ "t1", "t2" }));
   ASSERT_EQ(false, Krampus21::ScriptLoader::assert_odd_token_count({ "t1", "t2", "t3", "t4", "t5", "t6" }));
}

