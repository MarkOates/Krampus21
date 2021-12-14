#pragma once


#include <string>
#include <vector>


namespace Krampus21
{
   namespace DialogBoxes
   {
      class Base
      {
      private:
         std::string type;
         std::vector<std::string> lines;
         std::string current_page_num;

      public:
         Base(std::string type="Base", std::vector<std::string> lines={});
         ~Base();

         std::string get_type();
         std::vector<std::string> get_lines();
         std::string get_current_page_num();
         void start();
         void get_current_page_text();
         void init_page();
         void next_page();
         void is_finished();
      };
   }
}



