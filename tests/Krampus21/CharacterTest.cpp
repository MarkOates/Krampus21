
#include <gtest/gtest.h>

#include <Krampus21/Character.hpp>

#include <AllegroFlare/Testing/WithAllegroRenderingFixture.hpp>

class Krampus21_CharacterTest : public ::testing::Test {};
class Krampus21_CharacterWithAllegroRenderingFixtureTest : public AllegroFlare::Testing::WithAllegroRenderingFixture {};

TEST_F(Krampus21_CharacterTest, can_be_created_without_blowing_up)
{
   Krampus21::Character character;
}

TEST_F(Krampus21_CharacterWithAllegroRenderingFixtureTest, can_be_created_without_blowing_up)
{
   Krampus21::Character character(&get_font_bin_ref(), &get_bitmap_bin_ref());
   character.render();
   al_flip_display();
   sleep(1);
}

