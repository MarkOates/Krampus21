#pragma once


#include <AllegroFlare/BitmapBin.hpp>
#include <Krampus21/Backgrounds/Image.hpp>
#include <Krampus21/Backgrounds/Monoplex.hpp>
#include <string>


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
      Krampus21::Backgrounds::Image* create_image(std::string image_identifier="[unset-default-image-identifer-for-background-factory]");
   };
}



