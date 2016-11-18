#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "Window.h"
#include "GUI.h"

using namespace Graph_lib;

class Tutorial : public Graph_lib::Window	//Extend Tutorial from Graph_lib::Window
{
	private:
		Button quit_button;
		Button back_button;											// Declare our button and text
		Button move_to_game_button;
		Button move_to_highscores_button;
		Text first_line;
		Text second_line;
		Text third_line;
		Text fourth_line;
		Text fifth_line;
		Text sixth_line;
		Text seventh_line;
		Rectangle outline_text;
	public:
		Tutorial(Point p , int w , int h , const string& name);		//Declare our constructor
		
		static void cb_back(Address , Address);						//Declare our callback function
		static void cb_move_to_game(Address , Address);
		static void cb_move_to_highscores(Address , Address);
		static void cb_quit(Address , Address);
		
		
		void back_button_function();
		void show_game();
		void show_highscores();
};

#endif