
#include <gtest/gtest.h>

#include <Krampus21/Screens/Base.hpp>

TEST(Krampus21_Screens_BaseTest, can_be_created_without_blowing_up)
{
   Krampus21::Screens::Base base;
}

TEST(Krampus21_Screens_BaseTest, run__returns_the_expected_response)
{
   Krampus21::Screens::Base base;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, base.run());
}
