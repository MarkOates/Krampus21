#pragma once


#include <Krampus21/DialogBoxes/Basic.hpp>
#include <Krampus21/DialogBoxes/Choice.hpp>
#include <Krampus21/DialogBoxes/YouGotAnItem.hpp>
#include <string>
#include <utility>
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
      Krampus21::DialogBoxes::Choice* create_choice_dialog(std::string prompt="[prompt-argument-set-as-default]", std::vector<std::pair<std::string, std::string>> options={});
      Krampus21::DialogBoxes::YouGotAnItem* create_you_got_an_item_dialog(int item_num=0);
      Krampus21::DialogBoxes::Basic build_basic_dialog_from_file(std::string filename="no-filename-set.txt");
   };
}



