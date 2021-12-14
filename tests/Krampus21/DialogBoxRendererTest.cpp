
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <Krampus21/DialogBoxRenderer.hpp>


TEST(Krampus21_DialogBoxRendererTest, can_be_created_without_blowing_up)
{
   Krampus21::DialogBoxRenderer dialog_box_renderer;
}


TEST(Krampus21_DialogBoxRendererTest, render__when_allegro_is_not_installed__raises_an_exception)
{
   Krampus21::DialogBoxRenderer dialog_box_renderer;
   std::string expected_error_message = "DialogBoxRenderer::render: error: guard \"al_is_system_installed()\" not met";
   ASSERT_THROW_WITH_MESSAGE(dialog_box_renderer.render(), std::runtime_error, expected_error_message);
}


