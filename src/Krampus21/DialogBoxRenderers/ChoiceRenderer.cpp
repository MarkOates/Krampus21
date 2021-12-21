

#include <Krampus21/DialogBoxRenderers/ChoiceRenderer.hpp>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{
namespace DialogBoxRenderers
{


ChoiceRenderer::ChoiceRenderer(Krampus21::DialogBoxes::Choice* choice_dialog_box)
   : choice_dialog_box(choice_dialog_box)
{
}


ChoiceRenderer::~ChoiceRenderer()
{
}


void ChoiceRenderer::render()
{
   if (!(choice_dialog_box))
      {
         std::stringstream error_message;
         error_message << "ChoiceRenderer" << "::" << "render" << ": error: " << "guard \"choice_dialog_box\" not met";
         throw std::runtime_error(error_message.str());
      }
   return;
}
} // namespace DialogBoxRenderers
} // namespace Krampus21


