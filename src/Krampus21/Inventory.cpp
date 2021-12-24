

#include <Krampus21/Inventory.hpp>
#include <stdexcept>
#include <sstream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{


Inventory::Inventory(AllegroFlare::FontBin* font_bin, AllegroFlare::BitmapBin* bitmap_bin, AllegroFlare::Inventory* af_inventory)
   : font_bin(font_bin)
   , bitmap_bin(bitmap_bin)
   , af_inventory(af_inventory)
   , place({ 1920/2, 1080/2, 1300, 700 })
   , cursor_x(0)
   , cursor_y(0)
   , num_columns(4)
   , num_rows(3)
   , active(false)
   , active_animation_counter(0)
   , focus_selection_animation_counter(0)
{
}


Inventory::~Inventory()
{
}


allegro_flare::placement2d Inventory::get_place()
{
   return place;
}


void Inventory::update()
{
   if (!(font_bin))
      {
         std::stringstream error_message;
         error_message << "Inventory" << "::" << "update" << ": error: " << "guard \"font_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(bitmap_bin))
      {
         std::stringstream error_message;
         error_message << "Inventory" << "::" << "update" << ": error: " << "guard \"bitmap_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(af_inventory))
      {
         std::stringstream error_message;
         error_message << "Inventory" << "::" << "update" << ": error: " << "guard \"af_inventory\" not met";
         throw std::runtime_error(error_message.str());
      }
   // TODO
   return;
}

void Inventory::render()
{
   if (!(font_bin))
      {
         std::stringstream error_message;
         error_message << "Inventory" << "::" << "render" << ": error: " << "guard \"font_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(bitmap_bin))
      {
         std::stringstream error_message;
         error_message << "Inventory" << "::" << "render" << ": error: " << "guard \"bitmap_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   if (!(af_inventory))
      {
         std::stringstream error_message;
         error_message << "Inventory" << "::" << "render" << ": error: " << "guard \"af_inventory\" not met";
         throw std::runtime_error(error_message.str());
      }
   place.start_transform();

   draw_backframe();
   draw_inventory_title_text();
   draw_inventory_boxes_and_elevated_item_selection();
   draw_details_frame();

   place.restore_transform();

   return;
}

void Inventory::draw_backframe()
{
   ALLEGRO_COLOR backfill_color = ALLEGRO_COLOR{0.05, 0.05, 0.1, 0.7};
   ALLEGRO_COLOR top_and_bottom_pin_line_color = ALLEGRO_COLOR{0.2, 0.2, 0.2, 0.2};

   // backfill
   al_draw_filled_rectangle(0, 0, place.size.x, place.size.y, backfill_color);

   // top and bottom pin lines
   al_draw_line(0, 0, place.size.x, 0, top_and_bottom_pin_line_color, 2.0);
   al_draw_line(0, place.size.y, place.size.x, place.size.y, top_and_bottom_pin_line_color, 2.0);
   return;
}

void Inventory::draw_inventory_title_text()
{
   // TODO
   return;
}

void Inventory::draw_inventory_boxes_and_elevated_item_selection()
{
   // TODO
   return;
}

void Inventory::draw_details_frame()
{
   // TODO
   return;
}

void Inventory::move_cursor_up()
{
   // TODO
   return;
}

void Inventory::move_cursor_down()
{
   // TODO
   return;
}

void Inventory::move_cursor_left()
{
   // TODO
   return;
}

void Inventory::move_cursor_right()
{
   // TODO
   return;
}

void Inventory::activate()
{
   // TODO
   return;
}

void Inventory::deactivate()
{
   // TODO
   return;
}
} // namespace Krampus21


