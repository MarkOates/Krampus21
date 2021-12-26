#pragma once


#include <Krampus21/DialogBoxes/Base.hpp>


namespace Krampus21
{
   namespace DialogBoxes
   {
      class YouGotAnItem : public Krampus21::DialogBoxes::Base
      {
      private:
         int item_num;

      public:
         YouGotAnItem(int item_num=0);
         ~YouGotAnItem();

         float infer_age();
         void show();
      };
   }
}



