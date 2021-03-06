

#include <Krampus21/Titles/Feature.hpp>
#include <allegro_flare/placement2d.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <stdexcept>
#include <sstream>
#include <Blast/StringJoiner.hpp>


namespace Krampus21
{
namespace Titles
{


Feature::Feature(AllegroFlare::FontBin* font_bin, std::string primary_text, std::string secondary_text)
   : font_bin(font_bin)
   , primary_text(primary_text)
   , secondary_text(secondary_text)
   , primary_text_kerning(4)
   , secondary_text_kerning(4)
{
}


Feature::~Feature()
{
}


void Feature::render()
{
   if (!(font_bin))
      {
         std::stringstream error_message;
         error_message << "Feature" << "::" << "render" << ": error: " << "guard \"font_bin\" not met";
         throw std::runtime_error(error_message.str());
      }
   float opacity = 1.0;
   ALLEGRO_COLOR fading_white = ALLEGRO_COLOR{opacity, opacity, opacity, opacity};
   ALLEGRO_FONT *primary_text_font = obtain_primary_text_font();
   ALLEGRO_FONT *secondary_text_font = obtain_secondary_text_font();
   std::string primary_text = kern(this->primary_text, primary_text_kerning);
   std::string secondary_text = kern(this->secondary_text, secondary_text_kerning);
   float primary_text_width = al_get_text_width(primary_text_font, primary_text.c_str());
   float primary_text_height = al_get_font_line_height(primary_text_font);
   float secondary_text_width = al_get_text_width(secondary_text_font, secondary_text.c_str());
   float secondary_text_height = al_get_font_line_height(secondary_text_font);
   //FADE TO WHITE
   //FADING WHITE
   //FADING LIGHT
   allegro_flare::placement2d primary_text_place(1920/2, 1080/2-30, primary_text_width, primary_text_height);
   allegro_flare::placement2d secondary_text_place(1920/2, 1080/2+56, secondary_text_width, secondary_text_height);

   // draw the text

   primary_text_place.start_transform();
   al_draw_text(primary_text_font, fading_white, 0, 0, ALLEGRO_ALIGN_LEFT, primary_text.c_str());
   primary_text_place.restore_transform();

   secondary_text_place.start_transform();
   al_draw_text(secondary_text_font, fading_white, 0, 0, ALLEGRO_ALIGN_LEFT, secondary_text.c_str());
   secondary_text_place.restore_transform();

   return;
}

std::string Feature::kern(std::string text, int amount)
{
   std::vector<char> v(text.begin(), text.end());
   std::vector<std::string> strs;

   for (auto &vc : v) strs.push_back(std::string(1, vc) + std::string(amount, ' '));
   std::string str = Blast::StringJoiner(strs, "").join();

   str.substr(0, str.length() - amount);
   return str;
}

ALLEGRO_FONT* Feature::obtain_primary_text_font()
{
   return font_bin->auto_get("Lato-Bold.ttf -70");
}

ALLEGRO_FONT* Feature::obtain_secondary_text_font()
{
   return font_bin->auto_get("Lato-Bold.ttf -32");
}
} // namespace Titles
} // namespace Krampus21


