#pragma once


#include <Krampus21/DialogBoxes/Basic.hpp>
#include <string>
#include <vector>


namespace Krampus21
{
   class DialogFactory
   {
   private:

   public:
      DialogFactory();
      ~DialogFactory();

      Krampus21::DialogBoxes::Basic build_basic_test_dialog();
      Krampus21::DialogBoxes::Basic* create_basic_test_dialog();
      Krampus21::DialogBoxes::Basic build_basic_dialog(std::vector<std::string> pages={});
      Krampus21::DialogBoxes::Basic* create_basic_dialog(std::vector<std::string> pages={});
      Krampus21::DialogBoxes::Basic build_basic_dialog_from_file(std::string filename="no-filename-set.txt");
   };
}



