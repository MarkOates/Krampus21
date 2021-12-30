

#include <Krampus21/DialogBoxes/TitleText.hpp>



namespace Krampus21
{
namespace DialogBoxes
{


TitleText::TitleText(std::string primary_text)
   : Krampus21::DialogBoxes::Base("TitleText")
   , primary_text(primary_text)
{
}


TitleText::~TitleText()
{
}


void TitleText::set_primary_text(std::string primary_text)
{
   this->primary_text = primary_text;
}


std::string TitleText::get_primary_text()
{
   return primary_text;
}


} // namespace DialogBoxes
} // namespace Krampus21


