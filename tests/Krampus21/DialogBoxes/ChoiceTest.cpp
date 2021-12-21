
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
   // TODO
}


TEST(Krampus21_DialogBoxes_ChoiceTest, move_cursor_position_down__decrements_the_cursor_position)
{
   // TODO
}


TEST(Krampus21_DialogBoxes_ChoiceTest,
   move_cursor_position_up__when_at_the_top_of_the_list_of_chioices__wraps_to_the_bottom)
{
   // TODO
}


TEST(Krampus21_DialogBoxes_ChoiceTest,
   move_cursor_position_down__when_at_the_end_of_the_list_of_chioices__wraps_back_to_the_top)
{
   // TODO
}


