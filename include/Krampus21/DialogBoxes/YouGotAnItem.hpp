#pragma once


#include <Krampus21/DialogBoxes/Base.hpp>
#include <string>


namespace Krampus21
{
   namespace DialogBoxes
   {
      class YouGotAnItem : public Krampus21::DialogBoxes::Base
      {
      private:
         int item_num;
         std::string item_name;
         std::string item_bitmap_identifier;

      public:
         YouGotAnItem(int item_num=0, std::string item_name="[item-name-that-has-not-been-set]", std::string item_bitmap_identifier="[item-bitmap-identifier-has-not-been-set]");
         ~YouGotAnItem();

         std::string get_item_name();
         std::string get_item_bitmap_identifier();
         float infer_age();
         void show();
      };
   }
}



