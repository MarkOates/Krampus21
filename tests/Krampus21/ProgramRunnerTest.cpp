

#include <gtest/gtest.h>

#include <Krampus21/ProgramRunner.hpp>

TEST(Krampus21_ProgramRunnerTest, can_be_created_without_blowing_up)
{
   Krampus21::ProgramRunner program_runner;
}

TEST(Krampus21_ProgramRunnerTest, run__runs_the_program)
{
   Krampus21::ProgramRunner program_runner;
   program_runner.run();
}

