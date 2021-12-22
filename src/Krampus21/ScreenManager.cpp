

#include <Krampus21/ScreenManager.hpp>
#include <Krampus21/DialogFactory.hpp>
#include <stdexcept>
#include <sstream>
#include <AllegroFlare/UsefulPHP.hpp>
#include <Blast/FileExistenceChecker.hpp>
#include <Krampus21/ScriptLoader.hpp>
#include <stdexcept>
#include <sstream>
#include <Krampus21/DialogBoxRenderer.hpp>
#include <stdexcept>
#include <sstream>


namespace Krampus21
{


ScreenManager::ScreenManager(AllegroFlare::Framework* framework, AllegroFlare::Screens* screens, std::map<std::string, AllegroFlare::AudioRepositoryElement> sound_effect_elements, std::map<std::string, AllegroFlare::AudioRepositoryElement> music_track_elements)
   : AllegroFlare::Screen()
   , framework(framework)
   , screens(screens)
   , sound_effect_elements(sound_effect_elements)
   , music_track_elements(music_track_elements)
   , user_event_emitter_souce({})
   , user_event_emitter({})
   , audio_controller(&framework->get_sample_bin_ref(), sound_effect_elements, music_track_elements)
   , current_dialog(nullptr)
   , initialized(false)
   , script()
{
}


ScreenManager::~ScreenManager()
{
}


void ScreenManager::initialize()
{
   if (!((!initialized)))
      {
         std::stringstream error_message;
         error_message << "ScreenManager" << "::" << "initialize" << ": error: " << "guard \"(!initialized)\" not met";
         throw std::runtime_error(error_message.str());
      }
   audio_controller.initialize();
   initialized = true;
   return;
}

bool ScreenManager::load_script(std::string filename)
{
   if (!Blast::FileExistenceChecker(filename).exists())
   {
      std::cout << "ScreenManager::load_script: file \"" << filename
                << "\" does not exist and could not be loaded." << std::endl;
      return false;
   }
   std::vector<std::string> script_lines = AllegroFlare::php::file_get_contents_split(filename);
   script = Krampus21::Script(script_lines);
   script.initialize();
   return true;
}

void ScreenManager::start_game()
{
   play_music_track("etherial-ambience-01.wav");
}

void ScreenManager::shutdown_game()
{
   if (!(framework))
      {
         std::stringstream error_message;
         error_message << "ScreenManager" << "::" << "shutdown_game" << ": error: " << "guard \"framework\" not met";
         throw std::runtime_error(error_message.str());
      }
   framework->shutdown_program = true;
   return;
}

void ScreenManager::update_dialog()
{
   if (current_dialog) current_dialog->update();
   return;
}

bool ScreenManager::dialog_is_finished()
{
   if (!current_dialog) return true;
   return current_dialog->get_finished();
}

void ScreenManager::primary_timer_func()
{
   al_clear_to_color(ALLEGRO_COLOR{0, 0, 0, 0});
   update_dialog();
   if (dialog_is_finished())
   {
   }
   else
   {
      Krampus21::DialogBoxRenderer renderer(obtain_font_bin(), current_dialog);
      renderer.render();
   }
   return;
}

void ScreenManager::play_music_track(std::string identifier)
{
   audio_controller.play_music_track_by_identifier(identifier);
   return;
}

void ScreenManager::key_down_func(ALLEGRO_EVENT* ev)
{
   switch (ev->type)
   {
   case ALLEGRO_EVENT_KEY_DOWN:
      switch(ev->keyboard.keycode)
      {
         case ALLEGRO_KEY_ESCAPE:
            shutdown_game();
            break;
         case ALLEGRO_KEY_SPACE:
            // TODO advance dialog
            break;
         case ALLEGRO_KEY_UP:
         case ALLEGRO_KEY_K:
            // TODO move cursor up
            break;
         case ALLEGRO_KEY_DOWN:
         case ALLEGRO_KEY_J:
            // TODO move cursor down
            break;
         case ALLEGRO_KEY_ENTER:
            // TODO submit dialog
            break;
      }
      break;
   }
   return;
}

void ScreenManager::joy_button_down_func(ALLEGRO_EVENT* ev)
{
   switch (ev->joystick.button)
   {
   case 4:
      shutdown_game();
      break;
   case 1:
      // TODO advance dialog
      break;
   }
   return;
}

void ScreenManager::joy_axis_func(ALLEGRO_EVENT* ev)
{
   static float joystick_0_y_state = 0.0;
   static float joystick_1_y_state = 0.0;
   static float joystick_2_y_state = 0.0;

   switch (ev->joystick.stick)
   {
   case 0: // left most stick
      if (ev->joystick.axis == 1) // the up/down axis
      {
         float new_joystick_0_y_state = ev->joystick.pos;
         if (joystick_0_y_state < 0.5 && new_joystick_0_y_state >= 0.5)
         {
            // move cursor down
            // TODO move cursor down
            std::cout << "CURSOR DOWN" << std::endl;
         }
         else if (joystick_0_y_state > -0.5 && new_joystick_0_y_state <= -0.5)
         {
            // move cursor up
            // TODO move cursor down
            std::cout << "CURSOR UP" << std::endl;
         }
         joystick_0_y_state = new_joystick_0_y_state;
      }
      break;
   case 1:
      break;
   case 2: // the hat
      break;
   }
   return;
}

void ScreenManager::user_event_func(ALLEGRO_EVENT* ev)
{
   return;
}

AllegroFlare::FontBin* ScreenManager::obtain_font_bin()
{
   if (!(framework))
      {
         std::stringstream error_message;
         error_message << "ScreenManager" << "::" << "obtain_font_bin" << ": error: " << "guard \"framework\" not met";
         throw std::runtime_error(error_message.str());
      }
   return &framework->get_font_bin_ref();
}
} // namespace Krampus21


