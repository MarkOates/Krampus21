
#include <gtest/gtest.h>

#include <Krampus21/Backgrounds/Image.hpp>

TEST(Krampus21_Backgrounds_ImageTest, can_be_created_without_blowing_up)
{
   Krampus21::Backgrounds::Image image;
}

TEST(Krampus21_Backgrounds_ImageTest, run__returns_the_expected_response)
{
   Krampus21::Backgrounds::Image image;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, image.run());
}
