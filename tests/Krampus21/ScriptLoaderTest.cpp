
#include <gtest/gtest.h>

#include <Krampus21/ScriptLoader.hpp>

TEST(Krampus21_ScriptLoaderTest, can_be_created_without_blowing_up)
{
   Krampus21::ScriptLoader script_loader;
}

TEST(Krampus21_ScriptLoaderTest, parse__will_parse_some_basic_dialog_lines)
{
   std::vector<std::string> script_lines = {
      "DIALOG: This is the most basic dialog.",
      "DIALOG: This is another basic dialog.",
   };
   Krampus21::ScriptLoader script_loader(script_lines);

   std::vector<Krampus21::DialogBoxes::Base*> parsed_script = script_loader.parse();

   EXPECT_EQ(2, parsed_script.size());
}

