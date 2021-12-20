#pragma once


#include <Krampus21/DialogBoxes/Base.hpp>
#include <Krampus21/DialogFactory.hpp>
#include <string>
#include <vector>


namespace Krampus21
{
   class ScriptLoader
   {
   private:
      std::vector<std::string> script_lines;
      Krampus21::DialogFactory dialog_factory;

   public:
      ScriptLoader(std::vector<std::string> script_lines={});
      ~ScriptLoader();

      std::vector<Krampus21::DialogBoxes::Base*> parse();
   };
}



