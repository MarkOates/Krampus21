#pragma once


#include <string>


namespace Krampus21
{
   namespace Elements
   {
      class SmartPhoneDialogBubble
      {
      private:
         std::string text;
         float width;
         float height;

      public:
         SmartPhoneDialogBubble(std::string text="", float width=1, float height=1);
         ~SmartPhoneDialogBubble();

         void render();
      };
   }
}



