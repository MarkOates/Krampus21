#pragma once


#include <Krampus21/DialogBoxes/Base.hpp>
#include <string>


namespace Krampus21
{
   namespace DialogBoxes
   {
      class TitleText : public Krampus21::DialogBoxes::Base
      {
      private:
         std::string primary_text;

      public:
         TitleText(std::string primary_text="[unset-title-text]");
         ~TitleText();

         void set_primary_text(std::string primary_text);
         std::string get_primary_text();
      };
   }
}



