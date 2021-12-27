
#include <gtest/gtest.h>

#include <Krampus21/DialogBoxes/SmartPhone.hpp>

TEST(Krampus21_DialogBoxes_SmartPhoneTest, can_be_created_without_blowing_up)
{
   Krampus21::DialogBoxes::SmartPhone smart_phone;
}

TEST(Krampus21_DialogBoxes_SmartPhoneTest, run__returns_the_expected_response)
{
   Krampus21::DialogBoxes::SmartPhone smart_phone;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, smart_phone.run());
}
