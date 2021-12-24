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
         DialogBoxFrame(float width=1920/5*3, float height=1080/4);
         ~DialogBoxFrame();

         float get_width();
         float get_height();
         void render();
      };
   }
}



