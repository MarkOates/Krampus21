

#include <Krampus21/ProgramRunner.hpp>
#include <AllegroFlare/Display.hpp>
#include <AllegroFlare/Screens.hpp>
#include <AllegroFlare/Framework.hpp>
#include <map>
#include <string>
#include <AllegroFlare/AudioRepositoryElement.hpp>
#include <Krampus21/ApplicationController.hpp>


namespace Krampus21
{


ProgramRunner::ProgramRunner()
{
}


ProgramRunner::~ProgramRunner()
{
}


void ProgramRunner::run()
{
   AllegroFlare::Display *display;
   AllegroFlare::Screens screens;
   AllegroFlare::Framework framework(screens);

   framework.initialize();
   display = framework.create_display(1920, 1080, ALLEGRO_FULLSCREEN_WINDOW);
   //display = framework.create_display(AllegroFlare::Display::RESOLUTION_HD_1080);
   display->set_orthographic_projection(0, 0, 1920, 1080);

   // these two lists are essentially a fragment of a master Krampus21 config:

   std::map<std::string, AllegroFlare::AudioRepositoryElement> music_track_elements =
      std::map<std::string, AllegroFlare::AudioRepositoryElement>{
         { "etherial-ambience-01.wav", { "etherial-ambience-01.wav", true } },
         { "ringing-ambience-01.wav", { "ringing-ambience-01.wav", true } },
         //{ "ambiences-clips_2-machine-noise.wav", { "ambiences-clips_2-machine-noise.wav", true } },
         //{ TITLE_SCREEN_MUSIC, { "TitleScreen - With Edit - 01.ogg", false } },
         //{ LEVEL_1_MUSIC, { "02 sawsquarenoise - Stage 1.ogg", true } },
         //{ GAME_OVER_SCREEN_MUSIC, { "05 sawsquarenoise - Boss Splash.ogg", false } },
         //{ GAME_WON_SCREEN_MUSIC, { "sawsquarenoise_-_10_-_Towel_Defence_Ending.ogg", false } },
         //{ FINAL_BOSS_MUSIC, { "Boss Theme.ogg", true } },
      };
   std::map<std::string, AllegroFlare::AudioRepositoryElement> sound_effect_elements =
      std::map<std::string, AllegroFlare::AudioRepositoryElement>{
         { "phone-notification.wav", { "phone-notification.wav", false, } },
         //_BULLET_SOUND_EFFECT, { "sfx_wpn_laser8.wav", false } },
         //{ ENEMY_TAKES_HIT_SOUND_EFFECT, { "sfx_wpn_punch3.wav", false } },
         //{ ENEMY_EXPLOSION_SOUND_EFFECT, { "sfx_wpn_punch4.wav", false } },
         //{ BULLET_DEFLECTED_SOUND_EFFECT, { "sfx_wpn_noammo1.wav", false } },
      };

   std::string script_filename = "/Users/markoates/Repos/Krampus21/bin/programs/data/dialogs/development.txt";

   Krampus21::ApplicationController *screen_manager = new Krampus21::ApplicationController(
      &framework,
      &screens,
      sound_effect_elements,
      music_track_elements
   );
   screens.add(screen_manager);

   screen_manager->load_script(script_filename);
   screen_manager->initialize();
   screen_manager->start_game();

   framework.run_loop();

   delete screen_manager;
}
} // namespace Krampus21


