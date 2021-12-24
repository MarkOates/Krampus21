

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
   , inventory_index(build_inventory_index())
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
   ALLEGRO_COLOR left_overbackfill_color = ALLEGRO_COLOR{1.0 * 0.02, 0.8 * 0.02, 0.02 * 0.02, 0.02};
   ALLEGRO_COLOR top_and_bottom_pin_line_color = ALLEGRO_COLOR{0.2, 0.2, 0.2, 0.2};

   // backfill
   al_draw_filled_rectangle(0, 0, place.size.x, place.size.y, backfill_color);

   // left "overbackfill"
   al_draw_filled_rectangle(0, 0, 800, place.size.y, left_overbackfill_color);

   // top and bottom pin lines
   al_draw_line(0, 0, place.size.x, 0, top_and_bottom_pin_line_color, 2.0);
   al_draw_line(0, place.size.y, place.size.x, place.size.y, top_and_bottom_pin_line_color, 2.0);
   return;
}

void Inventory::draw_inventory_title_text()
{
   ALLEGRO_FONT *font = obtain_title_font();
   ALLEGRO_COLOR color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};
   al_draw_text(font, color, 0, -50, ALLEGRO_ALIGN_LEFT, "I N V E N T O R Y");
   return;
}

void Inventory::draw_inventory_boxes_and_elevated_item_selection()
{
   std::vector<int> items_in_inventory = af_inventory->get_items_ref();

   float x = 80;
   float y = 80;
   float spacing = 150 + 20;
   int inventory_position = 0;
   for (unsigned row=0; row<3; row++)
   {
      for (unsigned column=0; column<4; column++)
      {
         int item_to_draw = 0;
         if (inventory_position >= items_in_inventory.size()) {}
         else { item_to_draw = items_in_inventory[inventory_position]; }

         draw_inventory_item_box(x + column * spacing, y + row * spacing, item_to_draw);
      }
      inventory_position++;
   }
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

void Inventory::draw_inventory_item_box(float x, float y, int item)
{
   ALLEGRO_COLOR backfill_color = ALLEGRO_COLOR{0.0, 0.0, 0.0, 0.3};
   float roundness = 6.0f;

   // draw frame
   al_draw_filled_rounded_rectangle(x+0, y+0, x+150, y+150, roundness, roundness, backfill_color);

   bool contains_item = true;
   if (contains_item)
   {
      std::string item_name = "Item name";
      ALLEGRO_FONT *font = obtain_item_name_font();
      ALLEGRO_COLOR color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};
      al_draw_text(font, color, x, y + 150 - 20, ALLEGRO_ALIGN_LEFT, item_name.c_str());
   }
   return;
}

ALLEGRO_FONT* Inventory::obtain_title_font()
{
   return font_bin->auto_get("Lato-Bold.ttf -40");
}

ALLEGRO_FONT* Inventory::obtain_item_name_font()
{
   return font_bin->auto_get("Lato-Regular.ttf -30");
}

std::map<int, std::tuple<std::string, std::string, std::string>> Inventory::build_inventory_index()
{
   std::map<int, std::tuple<std::string, std::string, std::string>> result = {
      { 1, { "Bracelet", "bracelet.png", "A gift given to you by Ami" } },
      //{ 2, { "Watch", "watch.png", "Useful tool to keep you on track." } },
   };
   return result;
}
} // namespace Krampus21


