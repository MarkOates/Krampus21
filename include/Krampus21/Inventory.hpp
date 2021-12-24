#pragma once


#include <AllegroFlare/Inventory.hpp>


namespace Krampus21
{
   class Inventory
   {
   private:
      AllegroFlare::Inventory* af_inventory;

   public:
      Inventory();
      ~Inventory();

      void render();
   };
}



