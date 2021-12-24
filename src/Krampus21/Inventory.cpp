

#include <Krampus21/Inventory.hpp>
#include <stdexcept>
#include <sstream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <stdexcept>
#include <sstream>
#include <cmath>
#include <AllegroFlare/Color.hpp>
#include <AllegroFlare/Interpolators.hpp>


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


void Inventory::set_font_bin(AllegroFlare::FontBin* font_bin)
{
   this->font_bin = font_bin;
}


void Inventory::set_bitmap_bin(AllegroFlare::BitmapBin* bitmap_bin)
{
   this->bitmap_bin = bitmap_bin;
}


void Inventory::set_af_inventory(AllegroFlare::Inventory* af_inventory)
{
   this->af_inventory = af_inventory;
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
   draw_item_selection_cursor();
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
         inventory_position++;
      }
      inventory_position++;
   }
   return;
}

void Inventory::draw_details_frame()
{
   // draw label
   ALLEGRO_FONT* font = obtain_item_name_font();
   al_draw_text(font, ALLEGRO_COLOR{1, 1, 1, 1}, 850, 100, ALLEGRO_ALIGN_LEFT, "Watch");

   // draw graphic
   ALLEGRO_BITMAP *bitmap = bitmap_bin->auto_get("watch-01.png");
   allegro_flare::placement2d box_place;
   box_place.position.x = 1025;
   box_place.position.y = 290;
   box_place.size.x = 800;
   box_place.size.y = 800;
   box_place.scale.x = 0.6;
   box_place.scale.y = 0.6;
   box_place.start_transform();
   al_draw_bitmap(bitmap, 0, 0, 0);
   box_place.restore_transform();

   // draw multiline description
   float x = 820;
   float y = 420;
   float width = 1300 - 800- 50 + 5;
   int dialog_box_num_revealed_characters = 999;
   std::string text = "This is the details text that will be shown in the right pane.";
   float text_padding_x = 40.0f;
   float text_padding_y = 30.0f;
   float text_box_max_width = width - (text_padding_x * 2);
   ALLEGRO_FONT* text_font = obtain_description_font();
   float line_height = al_get_font_line_height(text_font) * 1.2;
   ALLEGRO_COLOR text_color = al_color_html("ffffff");
   al_draw_multiline_text(
      text_font,
      text_color,
      x + text_padding_x,
      y + text_padding_y,
      text_box_max_width,
      line_height,
      ALLEGRO_ALIGN_LEFT,
      concat_text(text, dialog_box_num_revealed_characters).c_str()
   );
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

void Inventory::draw_item_selection_cursor(float x, float y)
{
   ALLEGRO_COLOR color_a = al_color_name("aquamarine");
   ALLEGRO_COLOR color_b = AllegroFlare::color::transparent;
   float speed_multiplier = 1.1;
   float mix_factor = AllegroFlare::interpolator::slow_in_out(fmod(al_get_time() * speed_multiplier, 1.0));
   ALLEGRO_COLOR color = AllegroFlare::color::mix(color_a, color_b, mix_factor);
   float r = 8;
   float thickness = 6.0;
   al_draw_rounded_rectangle(x, y, x+150, y+150, r, r, color, thickness);
   return;
}

void Inventory::draw_inventory_item_box(float x, float y, int item)
{
   ALLEGRO_COLOR backfill_color = ALLEGRO_COLOR{0.0, 0.0, 0.0, 0.3};
   float roundness = 6.0f;

   // draw frame
   al_draw_filled_rounded_rectangle(x+0, y+0, x+150, y+150, roundness, roundness, backfill_color);

   std::tuple<std::string, std::string, std::string> item_definition = get_item_definition(item);
   bool contains_item = !std::get<0>(item_definition).empty();
   if (contains_item)
   {
      std::string item_name = std::get<0>(item_definition);
      std::string item_bitmap_identifier = std::get<1>(item_definition); //"watch-01.png";
      ALLEGRO_BITMAP *bitmap = bitmap_bin->auto_get(item_bitmap_identifier);

      //ALLEGRO_COLOR color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};
      //ALLEGRO_FONT *font = obtain_item_name_font();
      //al_draw_text(font, color, x, y + 150 - 20, ALLEGRO_ALIGN_LEFT, item_name.c_str());

      allegro_flare::placement2d box_place;
      box_place.position.x = x + 150/2;
      box_place.position.y = y + 150/2;
      box_place.size.x = 800;
      box_place.size.y = 800;
      box_place.scale.x = 0.25;
      box_place.scale.y = 0.25;

      box_place.start_transform();
      al_draw_bitmap(bitmap, 0, 0, 0);
      box_place.restore_transform();
   }
   return;
}

std::tuple<std::string, std::string, std::string> Inventory::get_item_definition(int index)
{
   if (inventory_index.find(index) == inventory_index.end()) return {};
   return inventory_index[index];
}

ALLEGRO_FONT* Inventory::obtain_title_font()
{
   return font_bin->auto_get("Lato-Bold.ttf -40");
}

ALLEGRO_FONT* Inventory::obtain_description_font()
{
   return font_bin->auto_get("Lato-Regular.ttf -36");
}

ALLEGRO_FONT* Inventory::obtain_item_name_font()
{
   return font_bin->auto_get("Lato-Bold.ttf -46");
}

std::map<int, std::tuple<std::string, std::string, std::string>> Inventory::build_inventory_index()
{
   std::map<int, std::tuple<std::string, std::string, std::string>> result = {
      //{ 1, { "Bracelet", "bracelet.png", "A gift given to you." } },
      { 2, { "Watch", "watch-01.png", "Useful tool to keep you on track." } },
   };
   return result;
}

std::string Inventory::concat_text(std::string source_text, int length)
{
   return source_text.substr(0, length);
}
} // namespace Krampus21


