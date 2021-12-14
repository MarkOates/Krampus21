
#include <gtest/gtest.h>

#include <Krampus21/DialogBoxRenderer.hpp>

TEST(Krampus21_DialogBoxRendererTest, can_be_created_without_blowing_up)
{
   Krampus21::DialogBoxRenderer dialog_box_renderer;
}

TEST(Krampus21_DialogBoxRendererTest, run__returns_the_expected_response)
{
   Krampus21::DialogBoxRenderer dialog_box_renderer;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, dialog_box_renderer.run());
}
