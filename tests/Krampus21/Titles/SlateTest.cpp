
#include <gtest/gtest.h>

#include <Krampus21/Titles/Slate.hpp>

TEST(Krampus21_Titles_SlateTest, can_be_created_without_blowing_up)
{
   Krampus21::Titles::Slate slate;
}

TEST(Krampus21_Titles_SlateTest, run__returns_the_expected_response)
{
   Krampus21::Titles::Slate slate;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, slate.run());
}
