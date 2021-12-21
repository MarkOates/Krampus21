
#include <gtest/gtest.h>

#include <Krampus21/DialogBoxes/Choice.hpp>


TEST(Krampus21_DialogBoxes_ChoiceTest, can_be_created_without_blowing_up)
{
   Krampus21::DialogBoxes::Choice choice;
}


TEST(Krampus21_DialogBoxes_ChoiceTest, get_type__returns_the_expected_value)
{
   Krampus21::DialogBoxes::Choice choice;
   EXPECT_EQ("Choice", choice.get_type());
}


TEST(Krampus21_DialogBoxes_ChoiceTest, when_not_initialized__cursor_position_is_set_to_negative_1)
{
   Krampus21::DialogBoxes::Choice choice;
   EXPECT_EQ(-1, choice.get_cursor_position());
}


TEST(Krampus21_DialogBoxes_ChoiceTest, when_initialized_with_some_options__cursor_position_is_set_to_0)
{
   std::vector<std::pair<std::string, std::string>> choice_options = {
     { "One simple choice", "GOTO A" },
   };
   Krampus21::DialogBoxes::Choice choice("What will you do?", choice_options);
   choice.initialize();

   EXPECT_EQ(0, choice.get_cursor_position());
}


TEST(Krampus21_DialogBoxes_ChoiceTest, move_cursor_position_up__when_options_are_empty__does_nothing)
{
   Krampus21::DialogBoxes::Choice choice;
   choice.initialize();

   choice.move_cursor_position_up();

   SUCCEED();
}


TEST(Krampus21_DialogBoxes_ChoiceTest, move_cursor_position_down__when_options_are_empty__does_nothing)
{
   Krampus21::DialogBoxes::Choice choice;
   choice.initialize();

   choice.move_cursor_position_down();

   SUCCEED();
}


TEST(Krampus21_DialogBoxes_ChoiceTest, move_cursor_position_down__increments_the_cursor_position)
{
   std::vector<std::pair<std::string, std::string>> choice_options = {
     { "Post a log", "GOTO A" },
     { "Keep coding", "GOTO B" },
     { "Drink more soylent", "GOTO C" },
   };
   Krampus21::DialogBoxes::Choice choice("What will you do?", choice_options);
   choice.initialize();

   choice.move_cursor_position_down();
   EXPECT_EQ(1, choice.get_cursor_position());
   choice.move_cursor_position_down();
   EXPECT_EQ(2, choice.get_cursor_position());
}


TEST(Krampus21_DialogBoxes_ChoiceTest, move_cursor_position_down__decrements_the_cursor_position)
{
   std::vector<std::pair<std::string, std::string>> choice_options = {
     { "Post a log", "GOTO A" },
     { "Keep coding", "GOTO B" },
     { "Drink more soylent", "GOTO C" },
   };
   Krampus21::DialogBoxes::Choice choice("What will you do?", choice_options);
   choice.initialize();

   choice.move_cursor_position_down();
   choice.move_cursor_position_down();
   choice.move_cursor_position_up();
   EXPECT_EQ(1, choice.get_cursor_position());
   choice.move_cursor_position_up();
   EXPECT_EQ(0, choice.get_cursor_position());
}


TEST(Krampus21_DialogBoxes_ChoiceTest,
   move_cursor_position_up__when_at_the_top_of_the_list_of_chioices__wraps_to_the_bottom)
{
   std::vector<std::pair<std::string, std::string>> choice_options = {
     { "Post a log", "GOTO A" },
     { "Keep coding", "GOTO B" },
     { "Drink more soylent", "GOTO C" },
   };
   Krampus21::DialogBoxes::Choice choice("What will you do?", choice_options);
   choice.initialize();

   choice.move_cursor_position_up();
   EXPECT_EQ(2, choice.get_cursor_position());
}


TEST(Krampus21_DialogBoxes_ChoiceTest,
   move_cursor_position_down__when_at_the_end_of_the_list_of_chioices__wraps_back_to_the_top)
{
   std::vector<std::pair<std::string, std::string>> choice_options = {
     { "Post a log", "GOTO A" },
     { "Keep coding", "GOTO B" },
     { "Drink more soylent", "GOTO C" },
   };
   Krampus21::DialogBoxes::Choice choice("What will you do?", choice_options);
   choice.initialize();

   choice.move_cursor_position_down();
   choice.move_cursor_position_down();
   choice.move_cursor_position_down();
   EXPECT_EQ(0, choice.get_cursor_position());
}


TEST(Krampus21_DialogBoxes_ChoiceTest, get_current_selection_text__with_no_options__returns_an_empty_string)
{
   // TODO
}


TEST(Krampus21_DialogBoxes_ChoiceTest, get_current_selection_value__with_no_options__returns_an_empty_string)
{
   // TODO
}


TEST(Krampus21_DialogBoxes_ChoiceTest, get_current_selection_text__returns_the_text_from_the_current_selection)
{
   // TODO
}


TEST(Krampus21_DialogBoxes_ChoiceTest, get_current_selection_value__returns_the_value_from_the_current_selection)
{
   // TODO
}


