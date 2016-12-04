#ifndef BOOTUP_H
#define BOOTUP_H
#include "GUI.h"
#include "Window.h"


using namespace Graph_lib;

class Bootup : public Graph_lib::Window	//Extend Bootup from Graph_lib::Window
{
	private:
		Button quit_button;											// Declare our buttons and text
		Button move_to_tutorial_button;
		Button move_to_game_button;
		Button move_to_highscores_button;
		
		Text game_name;
		Text team_number;
		Text team_kyle;
		Text team_reed;
		Text team_sam;
		
		Image japanese_wave;
		
		
	public:
		Bootup(Point p , int w , int h , const string& name);		//Declare our constructor
		
		static void cb_quit(Address , Address);						//Declare our callback function
		static void cb_move_to_tutorial(Address , Address);
		static void cb_move_to_game(Address , Address);
		static void cb_move_to_highscores(Address , Address);
		
		void show_tutorial();
		void show_game();
		void show_highscores();
};

#endif