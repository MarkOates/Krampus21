

#include <Krampus21/Screens/GameplayScreen.hpp>



namespace Krampus21
{
namespace Screens
{


GameplayScreen::GameplayScreen()
   : Krampus21::Screens::Base()
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


void GameplayScreen::primary_timer_func()
{
   return;
}
} // namespace Screens
} // namespace Krampus21


