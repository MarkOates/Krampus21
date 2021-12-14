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
         std::vector<std::vector<std::string>> pages;
         int current_page_num;

      public:
         Base(std::string type="Base", std::vector<std::vector<std::string>> pages={});
         ~Base();

         std::string get_type();
         std::vector<std::vector<std::string>> get_pages();
         int get_current_page_num();
         void set_pages(std::vector<std::vector<std::string>> pages={});
         void reset();
         std::vector<std::string> get_current_page_lines();
         bool next_page();
         bool current_page_is_valid();
         bool more_pages_to_go();
         int num_pages();
         bool at_last_page();
      };
   }
}



