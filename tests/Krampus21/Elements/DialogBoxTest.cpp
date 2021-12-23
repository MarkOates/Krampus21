
#include <gtest/gtest.h>

#include <Krampus21/Elements/DialogBox.hpp>

TEST(Krampus21_Elements_DialogBoxTest, can_be_created_without_blowing_up)
{
   Krampus21::Elements::DialogBox dialog_box;
}

TEST(Krampus21_Elements_DialogBoxTest, run__returns_the_expected_response)
{
   Krampus21::Elements::DialogBox dialog_box;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, dialog_box.run());
}
