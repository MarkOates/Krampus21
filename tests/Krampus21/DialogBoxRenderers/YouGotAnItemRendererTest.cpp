
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <Krampus21/DialogBoxRenderers/YouGotAnItemRenderer.hpp>

#include <AllegroFlare/Testing/WithAllegroRenderingFixture.hpp>

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
   Krampus21::DialogBoxes::YouGotAnItem you_got_an_item_dialog_box(1);
   Krampus21::DialogBoxRenderers::YouGotAnItemRenderer you_got_an_item_renderer(
      &get_font_bin_ref(),
      &get_bitmap_bin_ref(),
      &you_got_an_item_dialog_box
   );
   you_got_an_item_renderer.render();
   al_flip_display();
   sleep(1);
}

