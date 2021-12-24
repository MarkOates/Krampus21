

#include <Krampus21/Inventory.hpp>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{


Inventory::Inventory(AllegroFlare::FontBin* font_bin, AllegroFlare::BitmapBin* bitmap_bin, AllegroFlare::Inventory* af_inventory)
   : font_bin(font_bin)
   , bitmap_bin(bitmap_bin)
   , af_inventory(af_inventory)
   , place({ 1920/2, 1080/5*2, 800, 800 })
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
   draw_backframe();
   draw_inventory_title_text();
   draw_inventory_boxes_and_elevated_item_selection();
   draw_details_frame();
   return;
}

void Inventory::draw_backframe()
{
   // TODO
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


