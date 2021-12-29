
#include <gtest/gtest.h>

#include <Krampus21/BackgroundFactory.hpp>

TEST(Krampus21_BackgroundFactoryTest, can_be_created_without_blowing_up)
{
   Krampus21::BackgroundFactory background_factory;
}

TEST(Krampus21_BackgroundFactoryTest, run__returns_the_expected_response)
{
   Krampus21::BackgroundFactory background_factory;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, background_factory.run());
}
