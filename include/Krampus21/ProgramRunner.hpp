#pragma once


#include <string>


namespace Krampus21
{
   class ProgramRunner
   {
   private:
      std::string script_to_start;

   public:
      ProgramRunner(std::string script_to_start="A-opening-scene.script.txt");
      ~ProgramRunner();

      void set_script_to_start(std::string script_to_start);
      void run();
   };
}



