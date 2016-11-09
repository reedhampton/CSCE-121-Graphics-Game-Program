#ifndef BOOTUP_H
#define BOOTUP_H

#include "Window.h"
#include "GUI.h"

using namespace Graph_lib;

class Bootup : public Graph_lib::Window	//Extend Bootup from Graph_lib::Window
{
	private:
		Button quit_button;											// Declare our button
		Button move_to_tutorial_button;
		Button move_to_game_button;
	public:
		Bootup(Point p , int w , int h , const string& name);		//Declare our constructor
		
		static void cb_quit(Address , Address);						//Declare our callback function
		static void cb_move_to_tutorial(Address , Address);
		static void cb_move_to_game(Address , Address);

		void show_tutorial();
		void show_game();
};

#endif