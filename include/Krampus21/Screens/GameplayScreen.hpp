#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <Krampus21/DialogBoxes/Base.hpp>
#include <Krampus21/Screens/Base.hpp>


namespace Krampus21
{
   namespace Screens
   {
      class GameplayScreen : public Krampus21::Screens::Base
      {
      private:
         AllegroFlare::FontBin* font_bin;
         Krampus21::DialogBoxes::Base* current_dialog_box;

      public:
         GameplayScreen(AllegroFlare::FontBin* font_bin=nullptr);
         ~GameplayScreen();

         void set_current_dialog_box(Krampus21::DialogBoxes::Base* current_dialog_box);
         Krampus21::DialogBoxes::Base* get_current_dialog_box();
         void initialize_dialog_box();
         void primary_timer_func() override;
      };
   }
}



