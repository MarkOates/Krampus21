
#include <gtest/gtest.h>

#include <Krampus21/DialogBoxes/Basic.hpp>

TEST(Krampus21_DialogBoxes_BasicTest, can_be_created_without_blowing_up)
{
   Krampus21::DialogBoxes::Basic basic;
}

TEST(Krampus21_DialogBoxes_BasicTest, run__returns_the_expected_response)
{
   Krampus21::DialogBoxes::Basic basic;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, basic.run());
}
