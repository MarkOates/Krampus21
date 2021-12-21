
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <Krampus21/DialogBoxRenderers/ChoiceRenderer.hpp>

#include <Testing/WithAllegroRenderingFixture.hpp>

#ifdef _WIN32
#define TEST_FIXTURE_FONT_FOLDER "/msys64/home/Mark/Repos/Krampus21/bin/programs/data/fonts/"
#else
#define TEST_FIXTURE_FONT_FOLDER "/Users/markoates/Repos/Krampus21/bin/programs/data/fonts/"
#endif


class Krampus21_DialogBoxRenderers_ChoiceRendererTest : public ::testing::Test {};
class Krampus21_DialogBoxRenderers_ChoiceRendererWithAllegroRenderingFixtureTest
   : public Testing::WithAllegroRenderingFixture {};


TEST_F(Krampus21_DialogBoxRenderers_ChoiceRendererTest, can_be_created_without_blowing_up)
{
   Krampus21::DialogBoxRenderers::ChoiceRenderer choice_renderer;
}


TEST_F(Krampus21_DialogBoxRenderers_ChoiceRendererTest, render__without_a_choice_dialog_box__throws_an_exception)
{
   al_init();
   Krampus21::DialogBoxRenderers::ChoiceRenderer choice_renderer;
   std::string expected_error_message = "ChoiceRenderer::render: error: guard \"choice_dialog_box\" not met";
   ASSERT_THROW_WITH_MESSAGE(choice_renderer.render(), std::runtime_error, expected_error_message);
   al_uninstall_system();
}


TEST_F(Krampus21_DialogBoxRenderers_ChoiceRendererWithAllegroRenderingFixtureTest,
   render__does_not_blow_up)
{
   allegro_flare::placement2d place{ 1920/2, 1080/4*3, 1920/5*3, 1080/4 };
   Krampus21::DialogBoxes::Choice choice_dialog_box;
   Krampus21::DialogBoxRenderers::ChoiceRenderer choice_renderer(
      &get_font_bin_ref(),
      &choice_dialog_box,
      place.size.x,
      place.size.y
   );

   place.start_transform();
   choice_renderer.render();
   place.restore_transform();
   al_flip_display();
   sleep(1);

   SUCCEED();
}


