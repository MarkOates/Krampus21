
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

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

TEST(Krampus21_DialogFactoryTest, build_basic_test_dialog_from_file__without_the_file_present__throws_an_exception)
{
   Krampus21::DialogFactory dialog_factory;
   std::string filename_that_is_not_present = "filename-that-is-not-present.txt";

   std::string expected_error_message = "[DialogFactory:build_basic_test_dialog_from_file]: error: " \
                                        "the file \"filename-that-is-not-present.txt\" is not present.";
   ASSERT_THROW_WITH_MESSAGE(
      dialog_factory.build_basic_test_dialog_from_file(filename_that_is_not_present),
      std::runtime_error,
      expected_error_message
   );
}

