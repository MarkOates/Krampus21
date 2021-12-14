#pragma once


#include <Krampus21/Screens/Base.hpp>


namespace Krampus21
{
   class ScreenFactory
   {
   private:

   public:
      ScreenFactory();
      ~ScreenFactory();

      Krampus21::Screens::Base* create_gameplay_screen();
   };
}



