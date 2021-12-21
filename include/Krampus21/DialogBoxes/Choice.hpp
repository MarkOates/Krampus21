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
         bool initialized;

      public:
         Choice();
         ~Choice();

         int get_cursor_position();
         void initialize();
         void move_cursor_position_down();
         void move_cursor_position_up();
         bool has_valid_cursor_position();
      };
   }
}



