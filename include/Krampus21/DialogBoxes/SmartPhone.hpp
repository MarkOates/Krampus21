#pragma once


#include <Krampus21/DialogBoxes/Base.hpp>
#include <string>
#include <vector>


namespace Krampus21
{
   namespace DialogBoxes
   {
      class SmartPhone : public Krampus21::DialogBoxes::Base
      {
      private:
         std::vector<std::string> messages;

      public:
         SmartPhone(std::vector<std::string> messages={"[no-messages-set]"});
         ~SmartPhone();

         void render();
      };
   }
}



