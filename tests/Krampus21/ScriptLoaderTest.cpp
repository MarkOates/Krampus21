
#include <gtest/gtest.h>

#include <Krampus21/ScriptLoader.hpp>

TEST(Krampus21_ScriptLoaderTest, can_be_created_without_blowing_up)
{
   Krampus21::ScriptLoader script_loader;
}

TEST(Krampus21_ScriptLoaderTest, parse__does_not_blow_up)
{
   Krampus21::ScriptLoader script_loader;
   std::vector<Krampus21::DialogBoxes::Base*> parsed_script = script_loader.parse();
   EXPECT_EQ(3, parsed_script.size());
   SUCCEED();
}

