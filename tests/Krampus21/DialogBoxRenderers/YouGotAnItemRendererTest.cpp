
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <Krampus21/DialogBoxRenderers/YouGotAnItemRenderer.hpp>

#include <AllegroFlare/Testing/WithAllegroRenderingFixture.hpp>
#include <chrono>
#include <thread>

class Krampus21_DialogBoxRenderers_YouGotAnItemRendererTest : public ::testing::Test {};
class Krampus21_DialogBoxRenderers_YouGotAnItemRendererWithAllegroRenderingFixtureTest
   : public AllegroFlare::Testing::WithAllegroRenderingFixture {};


TEST_F(Krampus21_DialogBoxRenderers_YouGotAnItemRendererTest, can_be_created_without_blowing_up)
{
   Krampus21::DialogBoxRenderers::YouGotAnItemRenderer you_got_an_item_renderer;
}

TEST_F(Krampus21_DialogBoxRenderers_YouGotAnItemRendererWithAllegroRenderingFixtureTest,
   render__renders_the_dialog_box)
{
   allegro_flare::placement2d place{ 1920/2, 1080/4*2, 400, 400 };
   float age = 0.0;

   int passes = 60*2;
   for (unsigned i=0; i<passes; i++)
   {
      al_clear_to_color(ALLEGRO_COLOR{0, 0, 0, 1});
      place.start_transform();
      Krampus21::DialogBoxRenderers::YouGotAnItemRenderer you_got_an_item_renderer(
         &get_font_bin_ref(),
         &get_bitmap_bin_ref(),
         age,
         place.size.x,
         place.size.y
      );
      you_got_an_item_renderer.render();
      place.restore_transform();
      al_flip_display();
      std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
      age += 1.0/60.0f;
   }
}

