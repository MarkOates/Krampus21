
#include <gtest/gtest.h>

#include <Krampus21/ScriptLoader.hpp>

TEST(Krampus21_ScriptLoaderTest, can_be_created_without_blowing_up)
{
   Krampus21::ScriptLoader script_loader;
}

TEST(Krampus21_ScriptLoaderTest, run__returns_the_expected_response)
{
   Krampus21::ScriptLoader script_loader;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, script_loader.run());
}
