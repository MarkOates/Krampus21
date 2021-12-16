

#include <Krampus21/DialogFactory.hpp>
#include <Krampus21/DialogBoxes/Basic.hpp>
#include <sstream>
#include <Krampus21/DialogBoxes/Basic.hpp>
#include <Blast/FileExistenceChecker.hpp>


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

Krampus21::DialogBoxes::Basic DialogFactory::build_basic_test_dialog_from_file(std::string filename)
{
   Krampus21::DialogBoxes::Basic basic_dialog_box;
   Blast::FileExistenceChecker file_existence_checker(filename);
   if (!file_existence_checker.exists())
   {
      std::stringstream error_message;
      error_message << "[DialogFactory:build_basic_test_dialog_from_file]: error: "
                    << "the file \"" << filename << "\" is not present.";
      throw std::runtime_error(error_message.str());
   }

   basic_dialog_box.set_pages({
      { "Interesting.  I'm just sitting here working." },
      { "Oh well. I guess I'll just have to keep grinding." },
      { "At least I'm listening to some cool music." },
   });

   return basic_dialog_box;
}
} // namespace Krampus21


