
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <Krampus21/Backgrounds/Monoplex.hpp>

#include <AllegroFlare/Testing/WithAllegroRenderingFixture.hpp>
#include <chrono>
#include <thread>

class Krampus21_Backgrounds_MonoplexTest : public ::testing::Test {};
class Krampus21_Backgrounds_MonoplexWithAllegroRenderingFixtureTest
   : public AllegroFlare::Testing::WithAllegroRenderingFixture {};


TEST(Krampus21_Backgrounds_MonoplexTest, can_be_created_without_blowing_up)
{
   Krampus21::Backgrounds::Monoplex monoplex;
}


TEST_F(Krampus21_Backgrounds_MonoplexWithAllegroRenderingFixtureTest, draw__will_render_in_motion)
{
   Krampus21::Backgrounds::Monoplex monoplex(&get_bitmap_bin_ref());

   int frames = 60*1;
   for (unsigned i=0; i<frames; i++)
   {
      //update
      monoplex.managed_update();

      // draw
      al_clear_to_color(ALLEGRO_COLOR{0, 0, 0, 1});
      monoplex.draw();
      al_flip_display();
      sleep_for_frame();
   }
}


