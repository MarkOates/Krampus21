#pragma once


#include <AllegroFlare/Inventory.hpp>


namespace Krampus21
{
   class Inventory
   {
   private:
      AllegroFlare::Inventory* inventory;

   public:
      Inventory();
      ~Inventory();

      void render();
   };
}



