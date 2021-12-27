
#include <gtest/gtest.h>

#include <Krampus21/ApplicationController.hpp>

TEST(Krampus21_ApplicationControllerTest, can_be_created_without_blowing_up)
{
   Krampus21::ApplicationController screen_manager;
}

TEST(Krampus21_ApplicationControllerTest, load_script__when_the_file_does_not_exist__responds_with_an_error)
{
   // TODO
}

TEST(Krampus21_ApplicationControllerTest, load_script__when_the_file_does_not_exist__returns_false)
{
   // TODO
}

TEST(Krampus21_ApplicationControllerTest, load_script__loads_the_script)
{
   // TODO
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


TEST(Krampus21_ApplicationControllerTest, parse__command_and_argument__will_not_blow_up_on_an_empty_line)
   // note this is a private method test
{
   std::string script_line = "";
   std::pair<std::string, std::string> parsed_command_argument_pair;
   Krampus21::ApplicationController script_loader;

   parsed_command_argument_pair = script_loader.parse_command_and_argument(script_line);

   std::pair<std::string, std::string> expected_command_argument_pair = {"DIALOG", ""};

   EXPECT_EQ(expected_command_argument_pair, parsed_command_argument_pair);
}


TEST(Krampus21_ApplicationControllerTest,
   parse_command_and_argument__will_parse_a_script_line_into_an_expected_set_of_elements)
   // note this is a private method test
{
   std::string script_line = "DIALOG: This is the most basic dialog.";
   std::pair<std::string, std::string> parsed_command_argument_pair;
   Krampus21::ApplicationController script_loader;

   parsed_command_argument_pair = script_loader.parse_command_and_argument(script_line);

   std::pair<std::string, std::string> expected_command_argument_pair = {"DIALOG", "This is the most basic dialog."};

   EXPECT_EQ(expected_command_argument_pair, parsed_command_argument_pair);
}


TEST(Krampus21_ApplicationControllerTest,
   parse_command_and_argument__on_a_line_with_no_command__will_parse_to_a_DIALOG_and_trim_the_text)
   // note this is a private method test
{
   std::string script_line = "  \tThis line will automatically become dialog, and will be trimmed. \n ";
   std::pair<std::string, std::string> parsed_command_argument_pair;
   Krampus21::ApplicationController script_loader;

   parsed_command_argument_pair = script_loader.parse_command_and_argument(script_line);

   std::pair<std::string, std::string> expected_command_argument_pair = {
      "DIALOG",
      "This line will automatically become dialog, and will be trimmed."
   };

   EXPECT_EQ(expected_command_argument_pair, parsed_command_argument_pair);
}


TEST(Krampus21_ApplicationControllerTest, parse_and_run_line__will_parse_a_DIALOG_command)
   // note this is a private method test
{
   std::string script_line = "DIALOG: This is the most basic dialog line.";
   Krampus21::ApplicationController script_loader;

   script_loader.parse_and_run_line(script_line);
   Krampus21::DialogBoxes::Base* created_dialog = script_loader.get_current_dialog();

   ASSERT_NE(nullptr, created_dialog);
   EXPECT_EQ("Basic", created_dialog->get_type());
}


TEST(Krampus21_ApplicationControllerTest, parse_and_run_line__will_parse_a_CHOICE_command)
   // note this is a private method test
{
   std::string script_line = "CHOICE: What would you choose? | Apple | COLLECT: APPLE | Pear | COLLECT: PEAR";
   Krampus21::ApplicationController script_loader;

   script_loader.parse_and_run_line(script_line);
   Krampus21::DialogBoxes::Base* created_dialog = script_loader.get_current_dialog();

   ASSERT_NE(nullptr, created_dialog);
   ASSERT_EQ("Choice", created_dialog->get_type());

   Krampus21::DialogBoxes::Choice* created_choice_dialog = static_cast<Krampus21::DialogBoxes::Choice*>(created_dialog);

   std::string expected_prompt = "What would you choose?";
   std::vector<std::pair<std::string, std::string>> expected_options = {
      { "Apple", "COLLECT: APPLE" },
      { "Pear", "COLLECT: PEAR" },
   };
   EXPECT_EQ(expected_prompt, created_choice_dialog->get_prompt());
   EXPECT_EQ(expected_options, created_choice_dialog->get_options());
   delete created_dialog;
}


TEST(Krampus21_ApplicationControllerTest, parse__command_and_argument__will_trim_the_argument_fragment)
   // note this is a private method test
{
   std::string script_line = "  DIALOG  :  This is the most basic dialog that should be trimmed  \n  ";
   std::pair<std::string, std::string> parsed_command_argument_pair;
   Krampus21::ApplicationController script_loader;

   parsed_command_argument_pair = script_loader.parse_command_and_argument(script_line);

   std::pair<std::string, std::string> expected_command_argument_pair = {
      "DIALOG",
      "This is the most basic dialog that should be trimmed",
   };

   EXPECT_EQ(expected_command_argument_pair, parsed_command_argument_pair);
}


TEST(Krampus21_ApplicationControllerTest, tokenize__will_split_a_source_string_into_trimmed_tokens)
   // note this is a private method test
{
   std::string source_string = "  Voo| do |daah || \t dang ";
   std::vector<std::string> expected_tokens = { "Voo", "do", "daah", "", "dang" };
   std::vector<std::string> actual_tokens = Krampus21::ApplicationController::tokenize(source_string);
   EXPECT_EQ(expected_tokens, actual_tokens);
}


TEST(Krampus21_ApplicationControllerTest, assert_min_token_count__will_return_true_if_there_are_at_least_n_tokens)
{
   ASSERT_EQ(true, Krampus21::ApplicationController::assert_min_token_count({}, 0));
   ASSERT_EQ(true, Krampus21::ApplicationController::assert_min_token_count({ "t1", "t2", "t3" }, 3));
   ASSERT_EQ(true, Krampus21::ApplicationController::assert_min_token_count({ "t1", "t2", "t3", "t4" }, 2));
}

TEST(Krampus21_ApplicationControllerTest, assert_min_token_count__will_return_false_if_there_are_less_than_n_tokens)
{
   ASSERT_EQ(false, Krampus21::ApplicationController::assert_min_token_count({}, 1));
   ASSERT_EQ(false, Krampus21::ApplicationController::assert_min_token_count({ "t1", "t2", "t3" }, 4));
   ASSERT_EQ(false, Krampus21::ApplicationController::assert_min_token_count({ "t1", "t2", "t3", "t4" }, 999));
}

TEST(Krampus21_ApplicationControllerTest, assert_odd_token_count__will_return_true_if_the_number_of_tokens_is_odd)
{
   ASSERT_EQ(true, Krampus21::ApplicationController::assert_min_token_count({ "t1" }));
   ASSERT_EQ(true, Krampus21::ApplicationController::assert_min_token_count({ "t1", "t2", "t3" }));
   ASSERT_EQ(true, Krampus21::ApplicationController::assert_min_token_count({ "t1", "t2", "t3", "t4", "t5", "t6", "t7" }));
}

TEST(Krampus21_ApplicationControllerTest, assert_odd_token_count__will_return_false_if_the_number_of_tokens_is_not_odd)
{
   ASSERT_EQ(false, Krampus21::ApplicationController::assert_odd_token_count({ }));
   ASSERT_EQ(false, Krampus21::ApplicationController::assert_odd_token_count({ "t1", "t2" }));
   ASSERT_EQ(false, Krampus21::ApplicationController::assert_odd_token_count({ "t1", "t2", "t3", "t4", "t5", "t6" }));
}

TEST(Krampus21_ApplicationControllerTest,
   assert_token_count_eq__will_return_true_if_the_number_of_tokens_is_equal_to_the_value)
{
   ASSERT_EQ(true, Krampus21::ApplicationController::assert_token_count_eq({ }, 0));
   ASSERT_EQ(true, Krampus21::ApplicationController::assert_token_count_eq({ "t1", "t2" }, 2));
   ASSERT_EQ(true, Krampus21::ApplicationController::assert_token_count_eq({ "t1", "t2", "t3", "t4", "t5", "t6" }, 6));
}

TEST(Krampus21_ApplicationControllerTest,
   assert_token_count_eq__will_return_false_if_the_number_of_tokens_is_equal_to_the_value)
{
   ASSERT_EQ(false, Krampus21::ApplicationController::assert_token_count_eq({ }, 1));
   ASSERT_EQ(false, Krampus21::ApplicationController::assert_token_count_eq({ "t1", "t2" }, 999));
   ASSERT_EQ(false, Krampus21::ApplicationController::assert_token_count_eq({ "t1", "t2", "t3", "t4", "t5", "t6" }, -1));
}

TEST(Krampus21_ApplicationControllerText,
   build_markers_index__will_build_an_index_with_the_markers_and_line_numbers_from_the_script)
{
   std::vector<std::string> lines = {
      { "MARKER: *MY_START_MARKER*" },
      { "This is the first line of the script." },
      { "This is the second line of the script." },
      { "If you've made it this far, you might have a chance." },
      { "In fact, I'll even give you a choice." },
      { "Or at least, the illusion of one ;)" },
      { "CHOICE: Where would you like to go? | Back to the top | GOTO *MY_START_MARKER* | "
           "Take me to the end | GOTO *MY_END_MARKER*" },
      { "MARKER: *MY_END_MARKER*" },
      { "Look at this kid. He might have a shot after all." },
   };

   std::map<std::string, int> built_index = Krampus21::ApplicationController::build_markers_index(lines);

   std::map<std::string, int> expected_index = { { "*MY_START_MARKER*", 1 }, { "*MY_END_MARKER*", 8 } };
   ASSERT_EQ(expected_index, built_index);
}

TEST(Krampus21_ApplicationControllerText, build_markers_index__indexes_markers_at_the_beginning_and_the_end)
{
   std::vector<std::string> lines = {
      { "MARKER: *A_MARKER_AT_THE_FIRST_LINE*" },
      { "This is just a line in the middle." },
      { "MARKER: *A_MARKER_AT_THE_LAST_LINE*" },
   };

   std::map<std::string, int> built_index = Krampus21::ApplicationController::build_markers_index(lines);

   std::map<std::string, int> expected_index = {
      { "*A_MARKER_AT_THE_FIRST_LINE*", 1 },
      { "*A_MARKER_AT_THE_LAST_LINE*", 3 },
   };
   ASSERT_EQ(expected_index, built_index);
}

TEST(Krampus21_ApplicationControllerText,
   build_markers_index__if_a_script_has_multiple_identical_markers__will_generate_a_warning)
{
   std::vector<std::string> lines = {
      { "MARKER: *A_MARKER_THAT_EXISTS_IN_TWO_PLACES*" },
      { "This is just a line in the middle." },
      { "MARKER: *A_MARKER_THAT_EXISTS_IN_TWO_PLACES*" },
   };

   testing::internal::CaptureStdout();
   std::map<std::string, int> built_index = Krampus21::ApplicationController::build_markers_index(lines);
   std::string cout_output = testing::internal::GetCapturedStdout();

   std::string expected_warning_message = "Krampus21/ApplicationController::build_markers_index: WARNING: "
      "the marker \"*A_MARKER_THAT_EXISTS_IN_TWO_PLACES*\"is being set on line 3 but was already declared earlier "
      "on line 1. Note that the marker will be overwritten to this new line number (3).";

   ASSERT_EQ(expected_warning_message, cout_output);
}

TEST(Krampus21_ApplicationControllerText,
   build_markers_index__if_a_script_has_multiple_identical_markers__will_set_the_line_number_to_the_last_declaration)
{
   std::vector<std::string> lines = {
      { "MARKER: *A_MARKER_THAT_EXISTS_IN_TWO_PLACES*" },
      { "This is just a line in the middle." },
      { "MARKER: *A_MARKER_THAT_EXISTS_IN_TWO_PLACES*" },
   };

   std::map<std::string, int> built_index = Krampus21::ApplicationController::build_markers_index(lines);

   std::map<std::string, int> expected_index = {
      { "*A_MARKER_THAT_EXISTS_IN_TWO_PLACES*", 3 },
   };
   ASSERT_EQ(expected_index, built_index);
}



