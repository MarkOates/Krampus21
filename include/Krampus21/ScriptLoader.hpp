#pragma once


#include <string>
#include <vector>


namespace Krampus21
{
   class ScriptLoader
   {
   private:
      std::vector<std::string> script_lines;

   public:
      ScriptLoader(std::vector<std::string> script_lines={});
      ~ScriptLoader();

      std::string parse();
   };
}



