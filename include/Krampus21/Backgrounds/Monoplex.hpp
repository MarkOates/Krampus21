#pragma once


#include <AllegroFlare/BitmapBin.hpp>
#include <Krampus21/Backgrounds/Base.hpp>


namespace Krampus21
{
   namespace Backgrounds
   {
      class Monoplex : public Krampus21::Backgrounds::Base
      {
      private:
         AllegroFlare::BitmapBin* bitmap_bin;
         float monoplex_1_counter;
         float monoplex_2_counter;
         float monoplex_3_counter;

      public:
         Monoplex(AllegroFlare::BitmapBin* bitmap_bin=nullptr);
         virtual ~Monoplex();

         virtual void update() override;
         virtual void draw() override;
      };
   }
}



