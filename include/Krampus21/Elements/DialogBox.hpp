#pragma once




namespace Krampus21
{
   namespace Elements
   {
      class DialogBox
      {
      private:
         float width;
         float height;
         bool in_finished_state;
         bool draw_next_action_cursor;

      public:
         DialogBox();
         ~DialogBox();

         float get_width();
         float get_height();
         bool get_in_finished_state();
         bool get_draw_next_action_cursor();
         void render();
      };
   }
}



