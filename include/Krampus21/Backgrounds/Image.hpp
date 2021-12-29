#pragma once


#include <AllegroFlare/BitmapBin.hpp>
#include <Krampus21/Backgrounds/Base.hpp>
#include <allegro5/allegro.h>
#include <string>


namespace Krampus21
{
   namespace Backgrounds
   {
      class Image : public Krampus21::Backgrounds::Base
      {
      private:
         AllegroFlare::BitmapBin* bitmap_bin;
         std::string image_filename;

      public:
         Image(AllegroFlare::BitmapBin* bitmap_bin=nullptr);
         ~Image();

         void draw() override;
         ALLEGRO_BITMAP* obtain_background_bitmap();
      };
   }
}



