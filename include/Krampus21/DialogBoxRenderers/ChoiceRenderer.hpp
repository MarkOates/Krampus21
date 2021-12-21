#pragma once


#include <Krampus21/DialogBoxes/Choice.hpp>


namespace Krampus21
{
   namespace DialogBoxRenderers
   {
      class ChoiceRenderer
      {
      private:
         Krampus21::DialogBoxes::Choice* choice_dialog_box;

      public:
         ChoiceRenderer(Krampus21::DialogBoxes::Choice* choice_dialog_box=nullptr);
         ~ChoiceRenderer();

         void render();
      };
   }
}



