#pragma once


#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/Inventory.hpp>
#include <allegro_flare/placement2d.h>


namespace Krampus21
{
   class Inventory
   {
   private:
      AllegroFlare::FontBin* font_bin;
      AllegroFlare::BitmapBin* bitmap_bin;
      AllegroFlare::Inventory* af_inventory;
      allegro_flare::placement2d place;
      int cursor_x;
      int cursor_y;
      int num_columns;
      int num_rows;
      bool active;
      float active_animation_counter;
      float focus_selection_animation_counter;

   public:
      Inventory(AllegroFlare::FontBin* font_bin=nullptr, AllegroFlare::BitmapBin* bitmap_bin=nullptr);
      ~Inventory();

      void set_font_bin(AllegroFlare::FontBin* font_bin);
      void set_bitmap_bin(AllegroFlare::BitmapBin* bitmap_bin);
      allegro_flare::placement2d get_place();
      void update();
      void render();
      void draw_backframe();
      void draw_inventory_title_text();
      void draw_inventory_boxes_and_elevated_item_selection();
      void draw_details_frame();
      void move_cursor_up();
      void move_cursor_down();
      void move_cursor_left();
      void move_cursor_right();
      void activate();
      void deactivate();
   };
}



