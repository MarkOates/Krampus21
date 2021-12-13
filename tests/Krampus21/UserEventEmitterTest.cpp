
#include <gtest/gtest.h>

#include <Krampus21/UserEventEmitter.hpp>

TEST(Krampus21_UserEventEmitterTest, can_be_created_without_blowing_up)
{
   Krampus21::UserEventEmitter user_event_emitter;
}

TEST(Krampus21_UserEventEmitterTest, run__returns_the_expected_response)
{
   Krampus21::UserEventEmitter user_event_emitter;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, user_event_emitter.run());
}
