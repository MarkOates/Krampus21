

#include <Krampus21/DialogBoxes/Base.hpp>



namespace Krampus21
{
namespace DialogBoxes
{


Base::Base(std::string type, std::vector<std::string> pages)
   : type(type)
   , pages(pages)
   , current_page_num(0)
   , finished(false)
{
}


Base::~Base()
{
}


std::string Base::get_type()
{
   return type;
}


std::vector<std::string> Base::get_pages()
{
   return pages;
}


int Base::get_current_page_num()
{
   return current_page_num;
}


bool Base::get_finished()
{
   return finished;
}


void Base::set_pages(std::vector<std::string> pages)
{
   this->pages = pages;
   reset();
   return;
}

void Base::reset()
{
   current_page_num = 0;
   finished = false;
   return;
}

std::string Base::get_current_page_text()
{
   if (!current_page_is_valid()) return "[empty]";
   return pages[current_page_num];
}

bool Base::next_page()
{
   //if (at_last_page()) return false;
   if (get_finished()) return false;
   current_page_num++;
   if (current_page_num >= num_pages()) finished = true;
   return true;
}

int Base::num_pages()
{
   return pages.size();
}

bool Base::has_no_pages()
{
   return pages.empty();
}

bool Base::at_last_page()
{
   return (current_page_num == (num_pages() - 1));
}

bool Base::current_page_is_valid()
{
   if (pages.empty()) return false;
   if (current_page_num < 0) return false;
   if (current_page_num >= pages.size()) return false;
   return true;
}
} // namespace DialogBoxes
} // namespace Krampus21


