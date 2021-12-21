#pragma once


#include <string>


namespace Krampus21
{
   namespace DialogBoxRenderers
   {
      class ChoiceRenderer
      {
      private:

      public:
         ChoiceRenderer();
         ~ChoiceRenderer();

         std::string run();
      };
   }
}



