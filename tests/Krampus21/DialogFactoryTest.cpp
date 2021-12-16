
#include <gtest/gtest.h>

#include <Krampus21/DialogFactory.hpp>

TEST(Krampus21_DialogFactoryTest, can_be_created_without_blowing_up)
{
   Krampus21::DialogFactory dialog_factory;
}

TEST(Krampus21_DialogFactoryTest, run__returns_the_expected_response)
{
   Krampus21::DialogFactory dialog_factory;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, dialog_factory.run());
}
