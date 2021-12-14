
#include <gtest/gtest.h>

#include <Krampus21/DialogBoxes/Base.hpp>


class MyTestDialogBox : public Krampus21::DialogBoxes::Base
{
public:
   MyTestDialogBox() : Krampus21::DialogBoxes::Base("MyTestDialogBox") {}
};


TEST(Krampus21_DialogBoxes_BaseTest, can_be_created_without_blowing_up)
{
   Krampus21::DialogBoxes::Base base;
}


TEST(Krampus21_DialogBoxes_BaseTest, when_derived_the_type_of_the_derived_class_is_set)
{
   std::string expected_type = "MyTestDialogBox";
   MyTestDialogBox dialog_box;
   ASSERT_EQ(expected_type, dialog_box.get_type());
}


TEST(Krampus21_DialogBoxes_BaseTest, set_pages__sets_the_pages_with_the_passed_value)
{
   std::vector<std::vector<std::string>> pages = {
      { "Page 1 has this test" },
      { "This is the text to page 2.", "Page 1 has two lines." },
      { "And finally the last page" },
   };
   MyTestDialogBox dialog_box;

   dialog_box.set_pages(pages);

   ASSERT_EQ(pages, dialog_box.get_pages());
}


