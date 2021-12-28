#pragma once


#include <string>


namespace Krampus21
{
   namespace Backgrounds
   {
      class Base
      {
      private:
         std::string type;
         float reveal_counter;
         float reveal_speed;
         bool active;

      public:
         Base(std::string type="Base");
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



