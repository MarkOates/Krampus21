
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <Krampus21/Backgrounds/Image.hpp>

#ifdef _WIN32
#define TEST_FIXTURE_BITMAP_FOLDER "/msys64/home/Mark/Repos/Krampus21/bin/programs/data/bitmaps/"
#else
#define TEST_FIXTURE_BITMAP_FOLDER "/Users/markoates/Repos/Krampus21/bin/programs/data/bitmaps/"
#endif

#include <AllegroFlare/Testing/WithAllegroRenderingFixture.hpp>
#include <chrono>
#include <thread>

class Krampus21_Backgrounds_ImageTest : public ::testing::Test {};
class Krampus21_Backgrounds_ImageWithAllegroRenderingFixtureTest
   : public AllegroFlare::Testing::WithAllegroRenderingFixture {};


TEST(Krampus21_Backgrounds_ImageTest, can_be_created_without_blowing_up)
{
   Krampus21::Backgrounds::Image image_background;
}


TEST(Krampus21_Backgrounds_ImageTest, has_the_expected_type)
{
   Krampus21::Backgrounds::Image image_background;
   EXPECT_EQ("Image", image_background.get_type());
}


TEST_F(Krampus21_Backgrounds_ImageWithAllegroRenderingFixtureTest, draw__will_render_the_image)
{
   get_bitmap_bin_ref().set_full_path(TEST_FIXTURE_BITMAP_FOLDER);

   Krampus21::Backgrounds::Image image_background(&get_bitmap_bin_ref(), "outside-amys-place.png");

   int frames = 60;
   for (unsigned i=0; i<frames; i++)
   {
      //update
      image_background.managed_update();

      // draw
      al_clear_to_color(ALLEGRO_COLOR{0, 0, 0, 1});
      image_background.draw();
      al_flip_display();
      sleep_for_frame();
   }
}


