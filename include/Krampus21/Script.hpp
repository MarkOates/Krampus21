#pragma once


#include <map>
#include <string>
#include <vector>


namespace Krampus21
{
   class Script
   {
   private:
      std::vector<std::string> lines;
      int current_line_num;
      std::map<std::string, int> markers_index;
      bool initialized;

   public:
      Script(std::vector<std::string> lines={});
      ~Script();

      void initialize();
      std::string get_current_line_text();
      bool at_last_line();
      bool at_valid_line();
      void build_markers_index();
   };
}



