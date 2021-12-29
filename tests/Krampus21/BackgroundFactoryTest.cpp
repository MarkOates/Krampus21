
#include <gtest/gtest.h>

#include <Krampus21/BackgroundFactory.hpp>

TEST(Krampus21_BackgroundFactoryTest, can_be_created_without_blowing_up)
{
   Krampus21::BackgroundFactory background_factory;
}


TEST(Krampus21_BackgroundFactoryTest, create_monoplex__creates_a_monoplex_with_the_expected_properties)
{
   AllegroFlare::BitmapBin bitmap_bin;
   Krampus21::BackgroundFactory background_factory(&bitmap_bin);

   Krampus21::Backgrounds::Monoplex* created_monoplex = background_factory.create_monoplex();

   ASSERT_NE(nullptr, created_monoplex);
   EXPECT_EQ("Monoplex", created_monoplex->get_type());
}


