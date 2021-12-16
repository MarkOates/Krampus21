
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <Krampus21/DialogFactory.hpp>


#define TEST_FIXTURE_FILENAME "/Users/markoates/Repos/Krampus21/tests/test_fixtures/dialog-1.txt"


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


TEST(Krampus21_DialogFactoryTest, build_basic_dialog_from_file__without_the_file_present__throws_an_exception)
{
   Krampus21::DialogFactory dialog_factory;
   std::string filename_that_is_not_present = "filename-that-is-not-present.txt";

   std::string expected_error_message = "[DialogFactory:build_basic_dialog_from_file]: error: " \
                                        "the file \"filename-that-is-not-present.txt\" is not present.";
   ASSERT_THROW_WITH_MESSAGE(
      dialog_factory.build_basic_dialog_from_file(filename_that_is_not_present),
      std::runtime_error,
      expected_error_message
   );
}


TEST(Krampus21_DialogFactoryTest, build_basic_dialog_from_file__sets_the_test_to_the_dialog)
{
   Krampus21::DialogFactory dialog_factory;
   Krampus21::DialogBoxes::Basic basic_dialog_box;

   basic_dialog_box = dialog_factory.build_basic_dialog_from_file(TEST_FIXTURE_FILENAME);

   std::vector<std::string> expected_pages = {
      "Hello Clarence.",
      "What have you been up to these days?",
      "Hope you have been doing well.",
   };
   ASSERT_EQ(expected_pages, basic_dialog_box.get_pages());
}


