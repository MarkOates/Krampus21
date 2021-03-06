
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <Krampus21/Elements/DialogBoxFrame.hpp>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <chrono>
#include <thread>


TEST(Krampus21_Elements_DialogBoxFrameTest, can_be_created_without_blowing_up)
{
   Krampus21::Elements::DialogBoxFrame dialog_box_renderer;
}


TEST(Krampus21_Elements_DialogBoxFrameTest, render__when_allegro_is_not_installed__raises_an_exception)
{
   Krampus21::Elements::DialogBoxFrame dialog_box_renderer;
   std::string expected_error_message = "DialogBoxFrame::render: error: guard \"al_is_system_installed()\" not met";
   ASSERT_THROW_WITH_MESSAGE(dialog_box_renderer.render(), std::runtime_error, expected_error_message);
}


TEST(Krampus21_Elements_DialogBoxFrameTest, render__when_allegro_primitives_are_not_installed__raises_an_exception)
{
   al_init();

   Krampus21::Elements::DialogBoxFrame dialog_box_renderer;
   std::string expected_error_message =
      "DialogBoxFrame::render: error: guard \"al_is_primitives_addon_initialized()\" not met";
   ASSERT_THROW_WITH_MESSAGE(dialog_box_renderer.render(), std::runtime_error, expected_error_message);

   al_uninstall_system();
}


TEST(Krampus21_Elements_DialogBoxFrameTest, render__when_there_is_no_allegro_display__raises_an_exception)
{
   al_init();
   al_init_primitives_addon();
   Krampus21::Elements::DialogBoxFrame dialog_box_renderer;

   std::string expected_error_message =
      "DialogBoxFrame::render: error: guard \"al_get_current_display()\" not met";
   ASSERT_THROW_WITH_MESSAGE(dialog_box_renderer.render(), std::runtime_error, expected_error_message);

   al_uninstall_system();
}


TEST(Krampus21_Elements_DialogBoxFrameTest, render__draws_the_dialog_box)
{
   al_init();
   al_init_primitives_addon();
   ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);
   Krampus21::Elements::DialogBoxFrame dialog_box_renderer;

   dialog_box_renderer.render();
   al_flip_display();
   std::this_thread::sleep_for(std::chrono::seconds(1));

   al_destroy_display(display);
   al_uninstall_system();
}


TEST(Krampus21_Elements_DialogBoxFrameTest, render__when_the_dialog_box_is_finish__renders_special_empty_text)
{
   al_init();
   al_init_primitives_addon();
   ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);
   Krampus21::Elements::DialogBoxFrame dialog_box_renderer;

   dialog_box_renderer.render();
   al_flip_display();
   //std::this_thread::sleep_for(std::chrono::seconds(1));

   al_destroy_display(display);
   al_uninstall_system();
}


