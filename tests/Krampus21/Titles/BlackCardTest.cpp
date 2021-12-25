
#include <gtest/gtest.h>

#include <Krampus21/Titles/BlackCard.hpp>

TEST(Krampus21_Titles_BlackCardTest, can_be_created_without_blowing_up)
{
   Krampus21::Titles::BlackCard black_card;
}

TEST(Krampus21_Titles_BlackCardTest, run__returns_the_expected_response)
{
   Krampus21::Titles::BlackCard black_card;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, black_card.run());
}
