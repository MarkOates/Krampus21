#pragma once


#include <Krampus21/DialogBoxes/Base.hpp>
#include <string>


namespace Krampus21
{
   namespace DialogBoxes
   {
      class Basic : public Krampus21::DialogBoxes::Base
      {
      private:

      public:
         Basic();
         ~Basic();

         std::string run();
      };
   }
}



