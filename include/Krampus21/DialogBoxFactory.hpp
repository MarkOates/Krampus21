#pragma once


#include <Krampus21/DialogBoxes/Base.hpp>
#include <string>
#include <vector>


namespace Krampus21
{
   class DialogBoxFactory
   {
   private:

   public:
      DialogBoxFactory();
      ~DialogBoxFactory();

      Krampus21::DialogBoxes::Base* create_basic_dialog_box_for_testing();
      Krampus21::DialogBoxes::Base* create_basic_dialog_box(std::vector<std::string> pages={});
   };
}



