#pragma once


#include <Krampus21/DialogBoxes/YouGotAnItem.hpp>


namespace Krampus21
{
   namespace DialogBoxRenderers
   {
      class YouGotAnItemRenderer
      {
      private:
         Krampus21::DialogBoxes::YouGotAnItem* you_got_an_item_dialog_box;

      public:
         YouGotAnItemRenderer();
         ~YouGotAnItemRenderer();

         void render();
      };
   }
}



