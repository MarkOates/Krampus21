
#include <gtest/gtest.h>

#include <Krampus21/DialogBoxFactory.hpp>

TEST(Krampus21_DialogBoxFactoryTest, can_be_created_without_blowing_up)
{
   Krampus21::DialogBoxFactory dialog_box_factory;
}

TEST(Krampus21_DialogBoxFactoryTest, run__returns_the_expected_response)
{
   Krampus21::DialogBoxFactory dialog_box_factory;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, dialog_box_factory.run());
}
