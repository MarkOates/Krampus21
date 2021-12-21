#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <Krampus21/DialogBoxes/Choice.hpp>
#include <allegro5/allegro.h>
#include <string>
#include <utility>
#include <vector>


namespace Krampus21
{
   namespace DialogBoxRenderers
   {
      class ChoiceRenderer
      {
      private:
         AllegroFlare::FontBin* font_bin;
         Krampus21::DialogBoxes::Choice* choice_dialog_box;
         float width;
         float height;

      public:
         ChoiceRenderer(AllegroFlare::FontBin* font_bin=nullptr, Krampus21::DialogBoxes::Choice* choice_dialog_box=nullptr, float width=1, float height=1);
         ~ChoiceRenderer();

         void render();
         void draw_prompt_text();
         void draw_choices_with_cursor_and_current_selection(float start_y=0);
         void draw_frame();
         ALLEGRO_FONT* obtain_dialog_font();
         std::string obtain_choice_dialog_box_prompt();
         std::vector<std::pair<std::string, std::string>> obtain_choice_dialog_box_options();
         int obtain_choice_dialog_box_cursor_position();
         std::string concat_text(std::string source_text="", int length=0);
      };
   }
}



