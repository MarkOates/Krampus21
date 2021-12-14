
#include <gtest/gtest.h>

#include <Krampus21/ScreenFactory.hpp>


TEST(Krampus21_ScreenFactoryTest, can_be_created_without_blowing_up)
{
   Krampus21::ScreenFactory screen_factory;
}


TEST(Krampus21_ScreenFactoryTest, create_gameplay_screen__returns_a_valid_screen_of_the_expected_type)
{
   Krampus21::ScreenFactory screen_factory;

   Krampus21::Screens::Base* created_screen = screen_factory.create_gameplay_screen();

   ASSERT_NE(nullptr, created_screen);
   std::string expected_type = "GameplayScreen";
   EXPECT_EQ(expected_type, created_screen->get_type());
}


