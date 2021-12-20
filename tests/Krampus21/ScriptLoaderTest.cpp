
#include <gtest/gtest.h>

#include <Krampus21/ScriptLoader.hpp>

TEST(Krampus21_ScriptLoaderTest, can_be_created_without_blowing_up)
{
   Krampus21::ScriptLoader script_loader;
}

TEST(Krampus21_ScriptLoaderTest, run__returns_the_expected_response)
{
   std::vector<std::string> lines = {
      "This is the most basic dialog."
   };
   Krampus21::ScriptLoader script_loader(lines);
   script_loader.parse();
   SUCCESS();
}
