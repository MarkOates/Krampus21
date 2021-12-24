
#include <gtest/gtest.h>

#include <Krampus21/Elements/DialogBoxNameTag.hpp>


#include <AllegroFlare/Testing/WithAllegroRenderingFixture.hpp>


class Krampus21_Elements_DialogBoxNameTagTest : public ::testing::Test {};
class Krampus21_Elements_DialogBoxNameTagWithAllegroRenderingFixtureTest
   : public AllegroFlare::Testing::WithAllegroRenderingFixture {};


TEST_F(Krampus21_Elements_DialogBoxNameTagTest, can_be_created_without_blowing_up)
{
   Krampus21::Elements::DialogBoxNameTag dialog_box_name_tag;
}


