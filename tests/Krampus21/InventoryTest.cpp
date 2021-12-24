
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <Krampus21/Inventory.hpp>

#include <AllegroFlare/Testing/WithAllegroRenderingFixture.hpp>

#include <chrono>
#include <thread>
void SHOW_RENDER(int seconds=1) { al_flip_display(); std::this_thread::sleep_for(std::chrono::seconds(seconds)); }

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
}


TEST_F(Krampus21_InventoryWithAllegroRenderingFixtureTest, render__displays_the_inventory_window)
{
   AllegroFlare::Inventory af_inventory;
   Krampus21::Inventory inventory(&get_font_bin_ref(), &get_bitmap_bin_ref(), &af_inventory);
   inventory.render();
   //SHOW_RENDER();
}


TEST_F(Krampus21_InventoryWithAllegroRenderingFixtureTest, render__when_an_item_is_selected__renders_the_details_pane)
{
   AllegroFlare::Inventory af_inventory;
   af_inventory.add_item(2);
   //af_inventory.add_item(2);
   //af_inventory.add_item(2);
   Krampus21::Inventory inventory(&get_font_bin_ref(), &get_bitmap_bin_ref(), &af_inventory);
   inventory.render();
   //SHOW_RENDER();
}


TEST_F(Krampus21_InventoryWithAllegroRenderingFixtureTest, draw_item_selection_cursor__renders_an_animated_style)
{
   AllegroFlare::Inventory af_inventory;
   af_inventory.add_item(2);
   Krampus21::Inventory inventory(&get_font_bin_ref(), &get_bitmap_bin_ref(), &af_inventory);
   for (unsigned i=0; i<60 * 4; i++)
   {
      al_clear_to_color(ALLEGRO_COLOR{0, 0, 0, 0});
      inventory.draw_item_selection_cursor(1920/2, 1080/2);
      al_flip_display();
   }
}


