#pragma once


#include <Krampus21/DialogBoxes/Basic.hpp>


namespace Krampus21
{
   class DialogFactory
   {
   private:

   public:
      DialogFactory();
      ~DialogFactory();

      Krampus21::DialogBoxes::Basic build_basic_test_dialog();
   };
}



