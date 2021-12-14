

#include <Krampus21/DialogBoxes/Base.hpp>



namespace Krampus21
{
namespace DialogBoxes
{


Base::Base(std::string type, std::vector<std::string> lines)
   : type(type)
   , lines(lines)
   , current_page_num(0)
{
}


Base::~Base()
{
}


std::string Base::get_type()
{
   return type;
}


std::vector<std::string> Base::get_lines()
{
   return lines;
}


std::string Base::get_current_page_num()
{
   return current_page_num;
}


void Base::start()
{
   return;
}

void Base::get_current_page_text()
{
   return;
}

void Base::init_page()
{
   return;
}

void Base::next_page()
{
   return;
}

void Base::is_finished()
{
   return;
}
} // namespace DialogBoxes
} // namespace Krampus21


