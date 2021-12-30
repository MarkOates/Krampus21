
#include <Krampus21/ProgramRunner.hpp>
#include <allegro5/allegro.h>
#include <Blast/CommandLineFlaggedArgumentsParser.hpp>

int main(int argc, char **argv)
{
   std::vector<std::string> args;
   for (int i=0; i<argc; i++) args.push_back(argv[i]);

   Blast::CommandLineFlaggedArgumentsParser parser(args);
   std::vector<std::vector<std::string>> flags = parser.get_flagged_args("-s");
   std::vector<std::string> subset;
   std::string script_to_start;
   if (!flags.empty()) subset = flags.back();
   if (!subset.empty()) script_to_start = subset.back();

   Krampus21::ProgramRunner program_runner;
   if (!script_to_start.empty()) program_runner.set_script_to_start(script_to_start);

   program_runner.run();

   return 0;
}
