
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <Krampus21/Inventory.hpp>

#include <AllegroFlare/Testing/WithAllegroRenderingFixture.hpp>


class Krampus21_InventoryTest : public ::testing::Test {};
class Krampus21_InventoryWithAllegroRenderingFixtureTest : public AllegroFlare::Testing::WithAllegroRenderingFixture {};


TEST_F(Krampus21_InventoryTest, can_be_created_without_blowing_up)
{
   Krampus21::Inventory inventory;
}


TEST_F(Krampus21_InventoryWithAllegroRenderingFixtureTest, render__does_not_blow_up)
{
   AllegroFlare::Inventory af_inventory;
   Krampus21::Inventory inventory(&get_font_bin_ref(), &get_bitmap_bin_ref(), &af_inventory);
   inventory.render();
   al_flip_display();
}


