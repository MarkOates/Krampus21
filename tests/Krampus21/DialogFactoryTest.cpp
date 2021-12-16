
#include <gtest/gtest.h>

#include <Krampus21/DialogFactory.hpp>

TEST(Krampus21_DialogFactoryTest, can_be_created_without_blowing_up)
{
   Krampus21::DialogFactory dialog_factory;
}

TEST(Krampus21_DialogFactoryTest, run__returns_the_expected_response)
{
   Krampus21::DialogFactory dialog_factory;
   Krampus21::DialogBoxes::Basic basic_dialog_box;

   basic_dialog_box = dialog_factory.build_basic_test_dialog();

   std::vector<std::string> expected_pages = {
      { "Interesting.  I'm just sitting here working." },
      { "Oh well. I guess I'll just have to keep grinding." },
      { "At least I'm listening to some cool music." },
   };
   ASSERT_EQ(expected_pages, basic_dialog_box.get_pages());
}
