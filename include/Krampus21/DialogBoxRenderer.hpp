#pragma once


#include <Krampus21/DialogBoxes/Base.hpp>
#include <allegro_flare/placement2d.h>


namespace Krampus21
{
   class DialogBoxRenderer
   {
   private:
      Krampus21::DialogBoxes::Base* dialog_box;
      allegro_flare::placement2d place;

   public:
      DialogBoxRenderer();
      ~DialogBoxRenderer();

      allegro_flare::placement2d get_place();
      void render();
   };
}



