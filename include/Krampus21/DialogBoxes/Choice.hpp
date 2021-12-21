#pragma once


#include <Krampus21/DialogBoxes/Base.hpp>
#include <string>
#include <utility>
#include <vector>


namespace Krampus21
{
   namespace DialogBoxes
   {
      class Choice : public Krampus21::DialogBoxes::Base
      {
      private:
         std::string prompt;
         std::vector<std::pair<std::string, std::string>> options;
         int cursor_position;

      public:
         Choice();
         ~Choice();

      };
   }
}



