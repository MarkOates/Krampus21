

#include <Krampus21/ProgramRunner.hpp>
#include <AllegroFlare/Display.hpp>
#include <AllegroFlare/Screens.hpp>
#include <AllegroFlare/Framework.hpp>
#include <map>
#include <string>
#include <AllegroFlare/AudioRepositoryElement.hpp>
#include <Krampus21/ScreenManager.hpp>


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
         //{ TITLE_SCREEN_MUSIC, { "TitleScreen - With Edit - 01.ogg", false } },
         //{ LEVEL_1_MUSIC, { "02 sawsquarenoise - Stage 1.ogg", true } },
         //{ GAME_OVER_SCREEN_MUSIC, { "05 sawsquarenoise - Boss Splash.ogg", false } },
         //{ GAME_WON_SCREEN_MUSIC, { "sawsquarenoise_-_10_-_Towel_Defence_Ending.ogg", false } },
         //{ FINAL_BOSS_MUSIC, { "Boss Theme.ogg", true } },
      };
   std::map<std::string, AllegroFlare::AudioRepositoryElement> sound_effect_elements =
      std::map<std::string, AllegroFlare::AudioRepositoryElement>{
         //{ PLAYER_SHOOT_BULLET_SOUND_EFFECT, { "sfx_wpn_laser8.wav", false } },
         //{ ENEMY_TAKES_HIT_SOUND_EFFECT, { "sfx_wpn_punch3.wav", false } },
         //{ ENEMY_EXPLOSION_SOUND_EFFECT, { "sfx_wpn_punch4.wav", false } },
         //{ BULLET_DEFLECTED_SOUND_EFFECT, { "sfx_wpn_noammo1.wav", false } },
      };

   Krampus21::ScreenManager *screen_manager = new Krampus21::ScreenManager(
      &framework,
      &screens,
      music_track_elements,
      sound_effect_elements
   );
   screens.add(screen_manager);
   screen_manager->initialize();

   framework.run_loop();

   delete screen_manager;
}
} // namespace Krampus21


