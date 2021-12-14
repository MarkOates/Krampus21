
#include <gtest/gtest.h>

#include <Krampus21/DialogBoxRenderer.hpp>


TEST(Krampus21_DialogBoxRendererTest, can_be_created_without_blowing_up)
{
   Krampus21::DialogBoxRenderer dialog_box_renderer;
}


TEST(Krampus21_DialogBoxRendererTest, render__when_allegro_is_not_installed__raises_an_exception)
{
   Krampus21::DialogBoxRenderer dialog_box_renderer;
   dialog_box_renderer.render();
}


