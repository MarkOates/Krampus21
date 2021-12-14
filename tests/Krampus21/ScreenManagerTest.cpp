
#include <gtest/gtest.h>

#include <Krampus21/ScreenManager.hpp>

TEST(Krampus21_ScreenManagerTest, can_be_created_without_blowing_up)
{
   Krampus21::ScreenManager screen_manager;
}

TEST(Krampus21_ScreenManagerTest, run__returns_the_expected_response)
{
   Krampus21::ScreenManager screen_manager;
   std::string expected_string = "Hello World!";
   //EXPECT_EQ(expected_string, screen_manager.run());
}

