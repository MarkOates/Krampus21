

#include <Krampus21/Screens/GameplayScreen.hpp>
#include <Krampus21/DialogBoxFactory.hpp>
#include <Krampus21/DialogBoxRenderer.hpp>


namespace Krampus21
{
namespace Screens
{


GameplayScreen::GameplayScreen(AllegroFlare::FontBin* font_bin)
   : Krampus21::Screens::Base()
   , font_bin(font_bin)
   , current_dialog_box(nullptr)
{
}


GameplayScreen::~GameplayScreen()
{
}


void GameplayScreen::set_current_dialog_box(Krampus21::DialogBoxes::Base* current_dialog_box)
{
   this->current_dialog_box = current_dialog_box;
}


Krampus21::DialogBoxes::Base* GameplayScreen::get_current_dialog_box()
{
   return current_dialog_box;
}


void GameplayScreen::initialize_dialog_box()
{
   Krampus21::DialogBoxFactory dialog_box_factory;
   current_dialog_box = dialog_box_factory.create_basic_dialog_box_for_testing();
   return;
}

void GameplayScreen::primary_timer_func()
{
   if (current_dialog_box)
   {
      Krampus21::DialogBoxRenderer renderer(font_bin, current_dialog_box);
   }
   return;
}
} // namespace Screens
} // namespace Krampus21


