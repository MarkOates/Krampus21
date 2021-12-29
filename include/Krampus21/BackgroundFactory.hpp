#pragma once


#include <AllegroFlare/BitmapBin.hpp>
#include <Krampus21/Backgrounds/Monoplex.hpp>


namespace Krampus21
{
   class BackgroundFactory
   {
   private:
      AllegroFlare::BitmapBin* bitmap_bin;

   public:
      BackgroundFactory(AllegroFlare::BitmapBin* bitmap_bin=nullptr);
      ~BackgroundFactory();

      Krampus21::Backgrounds::Monoplex* create_monoplex();
   };
}



