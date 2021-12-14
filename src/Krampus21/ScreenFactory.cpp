

#include <Krampus21/ScreenFactory.hpp>
#include <Krampus21/Screens/GameplayScreen.hpp>


namespace Krampus21
{


ScreenFactory::ScreenFactory()
{
}


ScreenFactory::~ScreenFactory()
{
}


Krampus21::Screens::Base* ScreenFactory::create_gameplay_screen()
{
   Krampus21::Screens::GameplayScreen *gameplay_screen = new Krampus21::Screens::GameplayScreen;
   gameplay_screen->set_type("GameplayScreen");
   return gameplay_screen;
}
} // namespace Krampus21


