
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <Krampus21/Inventory.hpp>

#include <AllegroFlare/Testing/WithAllegroRenderingFixture.hpp>


class Krampus21_InventoryTest : public ::testing::Test {};
class Krampus21_InventoryTestWithAllegroRenderingFixture : public AllegroFlare::Testing::WithAllegroRenderingFixture {};


TEST_F(Krampus21_InventoryTest, can_be_created_without_blowing_up)
{
   Krampus21::Inventory inventory;
}


