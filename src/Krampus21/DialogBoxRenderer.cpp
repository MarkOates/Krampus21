

#include <Krampus21/DialogBoxRenderer.hpp>
#include <allegro5/allegro.h>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{


DialogBoxRenderer::DialogBoxRenderer()
   : dialog_box(nullptr)
{
}


DialogBoxRenderer::~DialogBoxRenderer()
{
}


void DialogBoxRenderer::render()
{
   if (!(al_is_system_installed()))
      {
         std::stringstream error_message;
         error_message << "DialogBoxRenderer" << "::" << "render" << ": error: " << "guard \"al_is_system_installed()\" not met";
         throw std::runtime_error(error_message.str());
      }
   return;
}
} // namespace Krampus21


