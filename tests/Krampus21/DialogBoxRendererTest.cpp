
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <Krampus21/DialogBoxRenderer.hpp>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#ifdef _WIN32
#define TEST_FIXTURE_FONT_FOLDER "/msys64/home/Mark/Repos/Krampus21/bin/programs/data/fonts/"
#else
#define TEST_FIXTURE_FONT_FOLDER "/Users/markoates/Repos/Krampus21/bin/programs/data/fonts/"
#endif


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


TEST(Krampus21_DialogBoxRendererTest, render__when_allegro_primitives_are_not_installed__raises_an_exception)
{
   al_init();

   Krampus21::DialogBoxRenderer dialog_box_renderer;
   std::string expected_error_message =
      "DialogBoxRenderer::render: error: guard \"al_is_primitives_addon_initialized()\" not met";
   ASSERT_THROW_WITH_MESSAGE(dialog_box_renderer.render(), std::runtime_error, expected_error_message);

   al_uninstall_system();
}


TEST(Krampus21_DialogBoxRendererTest, render__when_there_is_no_allegro_display__raises_an_exception)
{
   al_init();
   al_init_primitives_addon();
   Krampus21::DialogBoxRenderer dialog_box_renderer;

   std::string expected_error_message =
      "DialogBoxRenderer::render: error: guard \"al_get_current_display()\" not met";
   ASSERT_THROW_WITH_MESSAGE(dialog_box_renderer.render(), std::runtime_error, expected_error_message);

   al_uninstall_system();
}


TEST(Krampus21_DialogBoxRendererTest, render__when_the_allegro_font_addon_has_not_been_initialized__raises_an_exception)
{
   al_init();
   al_init_primitives_addon();
   al_init_ttf_addon();
   ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);
   Krampus21::DialogBoxes::Base dialog_box;
   dialog_box.set_pages({ { "Some test dialog text." } });
   Krampus21::DialogBoxRenderer dialog_box_renderer(nullptr, &dialog_box);

   std::string expected_error_message =
      "DialogBoxRenderer::obtain_dialog_font: error: guard \"al_is_font_addon_initialized()\" not met";
   ASSERT_THROW_WITH_MESSAGE(dialog_box_renderer.render(), std::runtime_error, expected_error_message);

   al_destroy_display(display);
   al_uninstall_system();
}


TEST(Krampus21_DialogBoxRendererTest, render__when_the_allegro_ttf_addon_has_not_been_initialized__raises_an_exception)
{
   al_init();
   al_init_primitives_addon();
   al_init_font_addon();
   al_init_ttf_addon();
   ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);
   Krampus21::DialogBoxes::Base dialog_box;
   dialog_box.set_pages({ { "Some test dialog text." } });
   Krampus21::DialogBoxRenderer dialog_box_renderer(nullptr, &dialog_box);

   std::string expected_error_message =
      "DialogBoxRenderer::obtain_dialog_font: error: guard \"font_bin\" not met";
   ASSERT_THROW_WITH_MESSAGE(dialog_box_renderer.render(), std::runtime_error, expected_error_message);

   al_destroy_display(display);
   al_uninstall_system();
}


TEST(Krampus21_DialogBoxRendererTest, render__when_there_is_no_font_bin__raises_an_exception)
{
   al_init();
   al_init_primitives_addon();
   al_init_font_addon();
   al_init_ttf_addon();
   ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);
   Krampus21::DialogBoxes::Base dialog_box;
   dialog_box.set_pages({ { "Some test dialog text." } });
   Krampus21::DialogBoxRenderer dialog_box_renderer(nullptr, &dialog_box);

   std::string expected_error_message =
      "DialogBoxRenderer::obtain_dialog_font: error: guard \"font_bin\" not met";
   ASSERT_THROW_WITH_MESSAGE(dialog_box_renderer.render(), std::runtime_error, expected_error_message);

   al_destroy_display(display);
   al_uninstall_system();
}


TEST(Krampus21_DialogBoxRendererTest, render__when_there_is_no_dialog_box__raises_an_exception)
{
   al_init();
   al_init_primitives_addon();
   al_init_font_addon();
   al_init_ttf_addon();
   ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);
   AllegroFlare::FontBin font_bin;
   Krampus21::DialogBoxRenderer dialog_box_renderer(&font_bin);

   std::string expected_error_message =
      "DialogBoxRenderer::render: error: guard \"dialog_box\" not met";
   ASSERT_THROW_WITH_MESSAGE(dialog_box_renderer.render(), std::runtime_error, expected_error_message);

   al_destroy_display(display);
   al_uninstall_system();
}


TEST(Krampus21_DialogBoxRendererTest, render__draws_the_dialog_box)
{
   al_init();
   al_init_primitives_addon();
   al_init_font_addon();
   al_init_ttf_addon();
   ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);
   AllegroFlare::FontBin font_bin;
   font_bin.set_full_path(TEST_FIXTURE_FONT_FOLDER);
   Krampus21::DialogBoxes::Base dialog_box;
   dialog_box.set_pages({ { "Some test dialog text with multiple pages.", "Here's the second page." } });
   Krampus21::DialogBoxRenderer dialog_box_renderer(&font_bin, &dialog_box);

   dialog_box_renderer.render();
   al_flip_display();
   sleep(1);

   al_destroy_display(display);
   al_uninstall_system();
}


TEST(Krampus21_DialogBoxRendererTest, render__when_the_dialog_box_is_finish__renders_special_empty_text)
{
   al_init();
   al_init_primitives_addon();
   al_init_font_addon();
   al_init_ttf_addon();
   ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);
   AllegroFlare::FontBin font_bin;
   font_bin.set_full_path(TEST_FIXTURE_FONT_FOLDER);
   Krampus21::DialogBoxes::Base dialog_box;
   dialog_box.next_page();
   Krampus21::DialogBoxRenderer dialog_box_renderer(&font_bin, &dialog_box);

   dialog_box_renderer.render();
   al_flip_display();
   sleep(1);

   al_destroy_display(display);
   al_uninstall_system();
}


TEST(Krampus21_DialogBoxRendererTest, render__draws_multiline_dialog)
{
   al_init();
   al_init_primitives_addon();
   al_init_font_addon();
   al_init_ttf_addon();
   ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);
   AllegroFlare::FontBin font_bin;
   font_bin.set_full_path(TEST_FIXTURE_FONT_FOLDER);
   Krampus21::DialogBoxes::Base dialog_box;
   dialog_box.set_pages({ { "Some test dialog text. There's actually a lot of text that will need to fit." } });
   Krampus21::DialogBoxRenderer dialog_box_renderer(&font_bin, &dialog_box);

   dialog_box_renderer.render();
   al_flip_display();
   sleep(1);

   al_destroy_display(display);
   al_uninstall_system();
}


