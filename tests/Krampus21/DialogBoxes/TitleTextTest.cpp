
#include <gtest/gtest.h>

#include <Krampus21/DialogBoxes/TitleText.hpp>

TEST(Krampus21_DialogBoxes_TitleTextTest, can_be_created_without_blowing_up)
{
   Krampus21::DialogBoxes::TitleText title_text;
}

TEST(Krampus21_DialogBoxes_TitleTextTest, run__returns_the_expected_response)
{
   Krampus21::DialogBoxes::TitleText title_text;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, title_text.run());
}
