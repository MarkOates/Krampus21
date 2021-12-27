
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <Krampus21/DialogBoxRenderers/SmartPhone.hpp>

#include <AllegroFlare/Testing/WithAllegroRenderingFixture.hpp>
#include <chrono>
#include <thread>

class Krampus21_SmartPhoneTest : public ::testing::Test {};
class Krampus21_SmartPhoneWithAllegroRenderingFixtureTest
   : public AllegroFlare::Testing::WithAllegroRenderingFixture {};


TEST_F(Krampus21_SmartPhoneWithAllegroRenderingFixtureTest, can_be_created_without_blowing_up)
{
   Krampus21::DialogBoxRenderers::SmartPhone smart_phone_dialog_renderer(
      &get_font_bin_ref(),
      600,
      100,
      { "Hello, this is bubble text" }
   );

   al_clear_to_color(ALLEGRO_COLOR{0, 0, 0, 1});
   smart_phone_dialog_renderer.render();
   al_flip_display();

   //std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));

   std::this_thread::sleep_for(std::chrono::seconds(1));
}


