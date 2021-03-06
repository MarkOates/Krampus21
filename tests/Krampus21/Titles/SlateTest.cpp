#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <Krampus21/Titles/Slate.hpp>

#ifdef _WIN32
#define TEST_FIXTURE_FONT_FOLDER "/msys64/home/Mark/Repos/Krampus21/bin/programs/data/fonts/"
#else
#define TEST_FIXTURE_FONT_FOLDER "/Users/markoates/Repos/Krampus21/bin/programs/data/fonts/"
#endif

#include <AllegroFlare/Testing/WithAllegroRenderingFixture.hpp>
#include <chrono>
#include <thread>

void SHOW_RENDER(int seconds=1) { al_flip_display(); std::this_thread::sleep_for(std::chrono::seconds(seconds)); }

class Krampus21_Titles_SlateTest : public ::testing::Test {};
class Krampus21_Titles_SlateWithAllegroRenderingFixtureTest :
   public AllegroFlare::Testing::WithAllegroRenderingFixture {};


TEST_F(Krampus21_Titles_SlateTest, can_be_created_without_blowing_up)
{
   Krampus21::Titles::Slate slate;
}


TEST_F(Krampus21_Titles_SlateWithAllegroRenderingFixtureTest, can_be_created_without_blowing_up)
{
   get_font_bin_ref().set_full_path(TEST_FIXTURE_FONT_FOLDER);

   std::string title_text = "ALLEGRO A GAME PROGRAMMING LIBRARY";
   std::string secondary_text = "made with";
   Krampus21::Titles::Slate slate(&get_font_bin_ref(), title_text, secondary_text);
   al_clear_to_color(ALLEGRO_COLOR{0, 0, 0, 1.0});
   slate.render();
   //SHOW_RENDER();
}


TEST_F(Krampus21_Titles_SlateWithAllegroRenderingFixtureTest, kern__with_empty_text__does_not_blow_up)
{
   get_font_bin_ref().set_full_path(TEST_FIXTURE_FONT_FOLDER);

   Krampus21::Titles::Slate slate(&get_font_bin_ref(), "", "");
   slate.render();
}


