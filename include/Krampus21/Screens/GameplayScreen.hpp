#pragma once


#include <Krampus21/Screens/Base.hpp>
#include <string>


namespace Krampus21
{
   namespace Screens
   {
      class GameplayScreen : public Krampus21::Screens::Base
      {
      private:

      public:
         GameplayScreen();
         ~GameplayScreen();

         std::string run();
      };
   }
}



