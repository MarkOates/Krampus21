
#include <gtest/gtest.h>

#include <Krampus21/ScreenFactory.hpp>

TEST(Krampus21_ScreenFactoryTest, can_be_created_without_blowing_up)
{
   Krampus21::ScreenFactory screen_factory;
}

TEST(Krampus21_ScreenFactoryTest, run__returns_the_expected_response)
{
   Krampus21::ScreenFactory screen_factory;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, screen_factory.run());
}
