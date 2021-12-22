
#include <gtest/gtest.h>

#include <Krampus21/Character.hpp>

TEST(Krampus21_CharacterTest, can_be_created_without_blowing_up)
{
   Krampus21::Character character;
}

TEST(Krampus21_CharacterTest, run__returns_the_expected_response)
{
   Krampus21::Character character;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, character.run());
}
