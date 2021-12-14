

#include <Krampus21/DialogBoxes/Base.hpp>
#include <stdexcept>
#include <sstream>


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


void Base::set_pages(std::vector<std::vector<std::string>> pages)
{
   this->pages = pages;
   reset();
   return;
}

void Base::reset()
{
   current_page_num = 0;
   return;
}

std::vector<std::string> Base::get_current_page_lines()
{
   if (!(current_page_is_valid()))
      {
         std::stringstream error_message;
         error_message << "Base" << "::" << "get_current_page_lines" << ": error: " << "guard \"current_page_is_valid()\" not met";
         throw std::runtime_error(error_message.str());
      }
   return pages[current_page_num];
}

bool Base::next_page()
{
   if (at_last_page()) return false;
   current_page_num++;
   return true;
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


