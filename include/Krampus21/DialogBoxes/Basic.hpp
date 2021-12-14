#pragma once


#include <Krampus21/DialogBoxes/Base.hpp>
#include <string>
#include <vector>


namespace Krampus21
{
   namespace DialogBoxes
   {
      class Basic : public Krampus21::DialogBoxes::Base
      {
      private:
         std::vector<std::string> lines;

      public:
         Basic(std::vector<std::string> lines={});
         ~Basic();

         std::string run();
      };
   }
}



