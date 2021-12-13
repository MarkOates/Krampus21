

#include <gtest/gtest.h>

#include <Krampus21/ProgramRunner.hpp>

TEST(Krampus21_ProgramRunnerTest, can_be_created_without_blowing_up)
{
   Krampus21::ProgramRunner program_runner;
}

TEST(Krampus21_ProgramRunnerTest, run__returns_the_expected_response)
{
   Krampus21::ProgramRunner program_runner;
   //EXPECT_EQ(expected_string, program_runner.run());
}

