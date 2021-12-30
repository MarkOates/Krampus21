#pragma once


#include <Krampus21/DialogBoxes/Basic.hpp>
#include <Krampus21/DialogBoxes/Choice.hpp>
#include <Krampus21/DialogBoxes/SmartPhone.hpp>
#include <Krampus21/DialogBoxes/TitleText.hpp>
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
      Krampus21::DialogBoxes::SmartPhone* create_smart_phone_dialog(std::vector<std::string> pages={});
      Krampus21::DialogBoxes::Basic* create_basic_dialog(std::vector<std::string> pages={});
      Krampus21::DialogBoxes::TitleText* create_title_text_dialog(std::string title_text="[title-text-that-is-not-set]");
      Krampus21::DialogBoxes::Choice* create_choice_dialog(std::string prompt="[prompt-argument-set-as-default]", std::vector<std::pair<std::string, std::string>> options={});
      Krampus21::DialogBoxes::YouGotAnItem* create_you_got_an_item_dialog(int item_num=0, std::string item_name="[unset-item-name]", std::string item_bitmap_identifier="[unset-item-bitmap-identifier]");
      Krampus21::DialogBoxes::Basic build_basic_dialog_from_file(std::string filename="no-filename-set.txt");
   };
}



