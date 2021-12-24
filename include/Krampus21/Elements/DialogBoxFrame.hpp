#pragma once




namespace Krampus21
{
   namespace Elements
   {
      class DialogBoxFrame
      {
      private:
         float width;
         float height;

      public:
         DialogBoxFrame();
         ~DialogBoxFrame();

         float get_width();
         float get_height();
         void render();
      };
   }
}



