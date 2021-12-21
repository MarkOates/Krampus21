#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <Krampus21/DialogBoxes/Choice.hpp>
#include <allegro5/allegro.h>
#include <string>


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
         ALLEGRO_FONT* obtain_dialog_font();
         std::string obtain_choice_dialog_box_prompt();
         void draw_prompt_text();
         void draw_frame();
         std::string concat_text(std::string source_text="", int length=0);
      };
   }
}



