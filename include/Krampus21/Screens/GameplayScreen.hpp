#pragma once


#include <Krampus21/DialogBoxes/Base.hpp>
#include <Krampus21/Screens/Base.hpp>


namespace Krampus21
{
   namespace Screens
   {
      class GameplayScreen : public Krampus21::Screens::Base
      {
      private:
         Krampus21::DialogBoxes::Base* current_dialog_box;

      public:
         GameplayScreen();
         ~GameplayScreen();

         void set_current_dialog_box(Krampus21::DialogBoxes::Base* current_dialog_box);
         Krampus21::DialogBoxes::Base* get_current_dialog_box();
         void primary_timer_func() override;
      };
   }
}



