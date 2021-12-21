
#include <gtest/gtest.h>

#include <Krampus21/DialogBoxRenderers/ChoiceRenderer.hpp>

TEST(Krampus21_DialogBoxRenderers_ChoiceRendererTest, can_be_created_without_blowing_up)
{
   Krampus21::DialogBoxRenderers::ChoiceRenderer choice_renderer;
}

TEST(Krampus21_DialogBoxRenderers_ChoiceRendererTest, run__returns_the_expected_response)
{
   Krampus21::DialogBoxRenderers::ChoiceRenderer choice_renderer;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, choice_renderer.run());
}
