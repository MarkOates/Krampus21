#pragma once


#include <Krampus21/DialogBoxes/Base.hpp>


namespace Krampus21
{
   class DialogBoxRenderer
   {
   private:
      Krampus21::DialogBoxes::Base* dialog_box;

   public:
      DialogBoxRenderer();
      ~DialogBoxRenderer();

      void render();
   };
}



