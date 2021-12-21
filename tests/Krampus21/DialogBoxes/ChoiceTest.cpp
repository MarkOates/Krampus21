
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

