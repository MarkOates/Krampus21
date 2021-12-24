
#include <gtest/gtest.h>

#include <Krampus21/Elements/DialogBoxNameTag.hpp>


#include <AllegroFlare/Testing/WithAllegroRenderingFixture.hpp>
#include <chrono>
#include <thread>


class Krampus21_Elements_DialogBoxNameTagTest : public ::testing::Test {};
class Krampus21_Elements_DialogBoxNameTagWithAllegroRenderingFixtureTest
   : public AllegroFlare::Testing::WithAllegroRenderingFixture {};


TEST_F(Krampus21_Elements_DialogBoxNameTagTest, can_be_created_without_blowing_up)
{
   Krampus21::Elements::DialogBoxNameTag dialog_box_name_tag;
}


TEST_F(Krampus21_Elements_DialogBoxNameTagWithAllegroRenderingFixtureTest, render__renders_the_name_tag)
{
   Krampus21::Elements::DialogBoxNameTag dialog_box_name_tag(&get_font_bin_ref());
   dialog_box_name_tag.render();
   al_flip_display();
   std::this_thread::sleep_for(std::chrono::seconds(1));
}

