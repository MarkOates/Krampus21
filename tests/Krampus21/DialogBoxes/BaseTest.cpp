
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
   std::vector<std::string> pages = {
      "Page 1 has this test",
      "This is the text to page 2.\nPage 1 has two lines.",
      "And finally the last page",
   };
   MyTestDialogBox dialog_box;

   dialog_box.set_pages(pages);

   ASSERT_EQ(pages, dialog_box.get_pages());
}


TEST(Krampus21_DialogBoxes_BaseTest, next_page__will_increment_the_page_number)
{
   std::vector<std::string> pages = {
      "Page 1 has this test",
      "This is the text to page 2.\nPage 1 has two lines.",
      "And finally the last page",
   };
   MyTestDialogBox dialog_box;

   dialog_box.set_pages(pages);

   ASSERT_EQ(0, dialog_box.get_current_page_num());
   dialog_box.next_page();
   ASSERT_EQ(1, dialog_box.get_current_page_num());
   dialog_box.next_page();
   ASSERT_EQ(2, dialog_box.get_current_page_num());
}


TEST(Krampus21_DialogBoxes_BaseTest,
   next_page__when_at_the_last_page__will_return_false_and_not_increment_the_page_number)
{
   std::vector<std::string> pages = {
      "Page 1 has this test",
      "This is the text to page 2.\nPage 1 has two lines.",
      "And finally the last page.",
   };
   MyTestDialogBox dialog_box;

   dialog_box.set_pages(pages);

   for (unsigned i=0; i<(pages.size() - 1); i++)  // flip to second-to-last page
   {
      EXPECT_EQ(true, dialog_box.next_page());
   }

   EXPECT_EQ(false, dialog_box.next_page());
   std::string expected_last_page_text = "And finally the last page.";
   ASSERT_EQ(expected_last_page_text, dialog_box.get_current_page_text());
}


TEST(Krampus21_DialogBoxes_BaseTest, has_no_pages__will_true_if_there_are_no_pages)
{
   MyTestDialogBox dialog_box;
   ASSERT_EQ(true, dialog_box.has_no_pages());
}


TEST(Krampus21_DialogBoxes_BaseTest, get_current_page_text__will_return_a_special_empty_text_when_not_on_a_page)
{
   MyTestDialogBox dialog_box;
   dialog_box.next_page();

   std::string expected_page_text = "[empty]";

   ASSERT_EQ(expected_page_text, dialog_box.get_current_page_text());
}


TEST(Krampus21_DialogBoxes_BaseTest, next_page__will_increment_the_page_text)
{
   std::vector<std::string> pages = {
      "Page 1 has this test",
      "This is the text to page 2.\nPage 1 has two lines.",
      "And finally the last page.",
   };
   MyTestDialogBox dialog_box;

   dialog_box.set_pages(pages);
   dialog_box.next_page();

   std::string expected_page_text = "This is the text to page 2.\nPage 1 has two lines.";

   ASSERT_EQ(expected_page_text, dialog_box.get_current_page_text());
}


TEST(Krampus21_DialogBoxes_BaseTest,
   next_page__when_at_the_last_page__not_increment_the_page_text)
{
   std::vector<std::string> pages = {
      "Page 1 has this test",
      "This is the text to page 2.\nPage 1 has two lines.",
      "And finally the last page.",
   };
   MyTestDialogBox dialog_box;

   dialog_box.set_pages(pages);

   for (unsigned i=0; i<(pages.size() - 1); i++)  // flip to second-to-last page
   {
      EXPECT_EQ(true, dialog_box.next_page());
   }

   std::string expected_last_page_text = "And finally the last page.";

   ASSERT_EQ(expected_last_page_text, dialog_box.get_current_page_text());
   EXPECT_EQ(false, dialog_box.next_page());
   ASSERT_EQ(expected_last_page_text, dialog_box.get_current_page_text());
}


