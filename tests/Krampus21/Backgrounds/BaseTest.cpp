
#include <gtest/gtest.h>

#include <Krampus21/Backgrounds/Base.hpp>

TEST(Krampus21_Backgrounds_BaseTest, can_be_created_without_blowing_up)
{
   Krampus21::Backgrounds::Base base;
}

TEST(Krampus21_Backgrounds_BaseTest, run__returns_the_expected_response)
{
   Krampus21::Backgrounds::Base base;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, base.run());
}
