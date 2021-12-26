#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <Krampus21/Titles/Feature.hpp>

#include <AllegroFlare/Testing/WithAllegroRenderingFixture.hpp>
#include <chrono>
#include <thread>

static void SHOW_RENDER(int seconds=1) { al_flip_display(); std::this_thread::sleep_for(std::chrono::seconds(seconds)); }

class Krampus21_Titles_FeatureTest : public ::testing::Test {};
class Krampus21_Titles_FeatureWithAllegroRenderingFixtureTest :
   public AllegroFlare::Testing::WithAllegroRenderingFixture {};


TEST_F(Krampus21_Titles_FeatureTest, can_be_created_without_blowing_up)
{
   Krampus21::Titles::Feature slate;
}


TEST_F(Krampus21_Titles_FeatureWithAllegroRenderingFixtureTest, can_be_created_without_blowing_up)
{
   std::string title_text = "FADE TO WHITE";
   std::string secondary_text = "A VISUAL NOVEL";
   Krampus21::Titles::Feature slate(&get_font_bin_ref(), title_text, secondary_text);
   al_clear_to_color(ALLEGRO_COLOR{0, 0, 0, 1.0});
   slate.render();
   SHOW_RENDER();
}


