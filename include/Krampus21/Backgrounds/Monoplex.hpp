#pragma once


#include <Krampus21/Backgrounds/Base.hpp>


namespace Krampus21
{
   namespace Backgrounds
   {
      class Monoplex : public Krampus21::Backgrounds::Base
      {
      private:

      public:
         Monoplex();
         virtual ~Monoplex();

         virtual void draw() override;
      };
   }
}



