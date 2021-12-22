
#include <gtest/gtest.h>

#include <Krampus21/Script.hpp>

TEST(Krampus21_ScriptTest, can_be_created_without_blowing_up)
{
   Krampus21::Script script;
}

TEST(Krampus21_ScriptText, get_current_line_text__gets_the_text_from_the_current_line)
{
   // TODO
}

TEST(Krampus21_ScriptText, at_last_line__returns_true_if_on_the_last_line)
{
   // TODO
}

TEST(Krampus21_ScriptText, at_last_line__returns_false_if_not_on_the_last_line)
{
   // TODO
}

TEST(Krampus21_ScriptText, goto_next_line__with_no_lines_returns_false)
{
   // TODO
}

TEST(Krampus21_ScriptText, goto_next_line__will_advance_the_current_line_num)
{
   // TODO
}

TEST(Krampus21_ScriptText, goto_next_line__if_currently_at_the_last_line__returns_false)
{
   // TODO
}

TEST(Krampus21_ScriptText, goto_next_line__if_currently_at_the_last_line__sets_the_current_line_num_to_negative_1)
{
   // TODO
}

TEST(Krampus21_ScriptText, goto_next_line__if_currently_at_the_last_line__sets_the_finished_to_true)
{
   // TODO
}

TEST(Krampus21_ScriptText, goto_line_num__sets_the_current_line_num)
{
   // TODO
}

TEST(Krampus21_ScriptText, goto_line_num__if_outside_the_range_of_lines__does_nothing)
{
   // TODO
}

