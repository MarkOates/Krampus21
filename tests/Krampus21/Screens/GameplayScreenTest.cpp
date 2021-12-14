
#include <gtest/gtest.h>

#include <Krampus21/Screens/GameplayScreen.hpp>

TEST(Krampus21_Screens_GameplayScreenTest, can_be_created_without_blowing_up)
{
   Krampus21::Screens::GameplayScreen gameplay_screen;
}

TEST(Krampus21_Screens_GameplayScreenTest, run__returns_the_expected_response)
{
   Krampus21::Screens::GameplayScreen gameplay_screen;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, gameplay_screen.run());
}
