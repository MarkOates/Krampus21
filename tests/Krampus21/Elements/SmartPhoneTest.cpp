
#include <gtest/gtest.h>

#include <Krampus21/Elements/SmartPhone.hpp>

TEST(Krampus21_Elements_SmartPhoneTest, can_be_created_without_blowing_up)
{
   Krampus21::Elements::SmartPhone smart_phone;
}

TEST(Krampus21_Elements_SmartPhoneTest, run__returns_the_expected_response)
{
   Krampus21::Elements::SmartPhone smart_phone;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, smart_phone.run());
}
