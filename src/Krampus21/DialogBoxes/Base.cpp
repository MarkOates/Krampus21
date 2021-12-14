

#include <Krampus21/DialogBoxes/Base.hpp>



namespace Krampus21
{
namespace DialogBoxes
{


Base::Base(std::string type, std::vector<std::vector<std::string>> pages)
   : type(type)
   , pages(pages)
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


std::vector<std::vector<std::string>> Base::get_pages()
{
   return pages;
}


int Base::get_current_page_num()
{
   return current_page_num;
}


void Base::reset()
{
   current_page_num = 0;
   return;
}

void Base::get_current_page_text()
{
   return;
}

void Base::next_page()
{
   //if (current_page_is_valid()
   // TODO
   return;
}

bool Base::current_page_is_valid()
{
   if (pages.empty()) return false;
   if (current_page_num < 0) return false;
   if (current_page_num >= pages.size()) return false;
   return true;
}

bool Base::more_pages_to_go()
{
   if (current_page_is_valid() && current_page_num < pages.size()) return true;
   return false;
}

int Base::num_pages()
{
   return pages.size();
}

bool Base::at_last_page()
{
   return (current_page_num == num_pages());
}
} // namespace DialogBoxes
} // namespace Krampus21


