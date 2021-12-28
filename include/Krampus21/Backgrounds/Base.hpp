#pragma once




namespace Krampus21
{
   namespace Backgrounds
   {
      class Base
      {
      private:
         float reveal_counter;
         float reveal_speed;
         bool active;

      public:
         Base();
         virtual ~Base();

         void activate();
         void deactivate();
         void managed_update();
         virtual void update();
         virtual void draw();
         void show();
         void hide();
      };
   }
}



