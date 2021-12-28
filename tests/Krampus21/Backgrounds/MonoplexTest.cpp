
#include <gtest/gtest.h>

#include <Krampus21/Backgrounds/Monoplex.hpp>

TEST(Krampus21_Backgrounds_MonoplexTest, can_be_created_without_blowing_up)
{
   Krampus21::Backgrounds::Monoplex monoplex;
}

TEST(Krampus21_Backgrounds_MonoplexTest, run__returns_the_expected_response)
{
   Krampus21::Backgrounds::Monoplex monoplex;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, monoplex.run());
}
