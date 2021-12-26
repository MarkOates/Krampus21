
#include <gtest/gtest.h>

#include <Krampu21/InventoryFactory.hpp>

TEST(Krampu21_InventoryFactoryTest, can_be_created_without_blowing_up)
{
   Krampu21::InventoryFactory inventory_factory;
}

TEST(Krampu21_InventoryFactoryTest, run__returns_the_expected_response)
{
   Krampu21::InventoryFactory inventory_factory;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, inventory_factory.run());
}
