

#include <Krampus21/DialogFactory.hpp>
#include <Krampus21/DialogBoxes/Basic.hpp>
#include <Krampus21/DialogBoxes/Basic.hpp>
#include <sstream>
#include <Krampus21/DialogBoxes/Basic.hpp>
#include <Blast/FileExistenceChecker.hpp>
#include <AllegroFlare/UsefulPHP.hpp>


namespace Krampus21
{


DialogFactory::DialogFactory()
{
}


DialogFactory::~DialogFactory()
{
}


Krampus21::DialogBoxes::Basic DialogFactory::build_basic_test_dialog()
{
   Krampus21::DialogBoxes::Basic basic_dialog_box;
   basic_dialog_box.set_pages({
      { "Interesting.  I'm just sitting here working." },
      { "Oh well. I guess I'll just have to keep grinding." },
      { "At least I'm listening to some cool music." },
   });

   return basic_dialog_box;
}

Krampus21::DialogBoxes::Basic* DialogFactory::create_basic_test_dialog()
{
   Krampus21::DialogBoxes::Basic *basic_dialog_box = new Krampus21::DialogBoxes::Basic;
   basic_dialog_box->set_pages({
      { "Interesting.  I'm just sitting here working." },
      { "Oh well. I guess I'll just have to keep grinding." },
      { "At least I'm listening to some cool music." },
   });

   return basic_dialog_box;
}

Krampus21::DialogBoxes::Basic DialogFactory::build_basic_dialog(std::vector<std::string> pages)
{
   Krampus21::DialogBoxes::Basic basic_dialog_box;
   basic_dialog_box.set_pages(pages);
   return basic_dialog_box;
}

Krampus21::DialogBoxes::SmartPhone* DialogFactory::create_smart_phone_dialog(std::vector<std::string> pages)
{
   Krampus21::DialogBoxes::SmartPhone *smart_phone_dialog_box = new Krampus21::DialogBoxes::SmartPhone(pages);
   smart_phone_dialog_box->set_created_at(al_get_time());
   //smart_phone_dialog_box.set_pages(pages);
   return smart_phone_dialog_box;
}

Krampus21::DialogBoxes::Basic* DialogFactory::create_basic_dialog(std::vector<std::string> pages)
{
   Krampus21::DialogBoxes::Basic* basic_dialog_box = new Krampus21::DialogBoxes::Basic();
   basic_dialog_box->set_pages(pages);
   return basic_dialog_box;
}

Krampus21::DialogBoxes::TitleText* DialogFactory::create_title_text_dialog(std::string title_text)
{
   Krampus21::DialogBoxes::TitleText* title_text_dialog_box = new Krampus21::DialogBoxes::TitleText(title_text);
   return title_text_dialog_box;
}

Krampus21::DialogBoxes::Choice* DialogFactory::create_choice_dialog(std::string prompt, std::vector<std::pair<std::string, std::string>> options)
{
   Krampus21::DialogBoxes::Choice* choice_dialog_box = new Krampus21::DialogBoxes::Choice(prompt, options);
   choice_dialog_box->initialize();
   //basic_dialog_box->set_pages(pages); // ??? hmm
   return choice_dialog_box;
}

Krampus21::DialogBoxes::YouGotAnItem* DialogFactory::create_you_got_an_item_dialog(int item_num, std::string item_name, std::string item_bitmap_identifier)
{
   Krampus21::DialogBoxes::YouGotAnItem* you_got_an_item_dialog_box =
      new Krampus21::DialogBoxes::YouGotAnItem(item_num, item_name, item_bitmap_identifier);
   you_got_an_item_dialog_box->set_created_at(al_get_time());
   you_got_an_item_dialog_box->show();
   //choice_dialog_box->initialize(); // doesn't seem to require initialization
   return you_got_an_item_dialog_box;
}

Krampus21::DialogBoxes::Basic DialogFactory::build_basic_dialog_from_file(std::string filename)
{
   Krampus21::DialogBoxes::Basic basic_dialog_box;
   Blast::FileExistenceChecker file_existence_checker(filename);
   if (!file_existence_checker.exists())
   {
      std::stringstream error_message;
      error_message << "[DialogFactory:build_basic_dialog_from_file]: error: "
                    << "the file \"" << filename << "\" is not present.";
      throw std::runtime_error(error_message.str());
   }

   std::vector<std::string> file_lines = AllegroFlare::php::file_get_contents_split(filename);

   basic_dialog_box.set_pages(file_lines);

   return basic_dialog_box;
}
} // namespace Krampus21


