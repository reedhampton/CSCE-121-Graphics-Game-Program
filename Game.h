#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "GUI.h"

using namespace Graph_lib;

class Game : public Graph_lib::Window	//Extend Bootup from Graph_lib::Window
{
	private:
		int difficulty_level;						// 3 - 10
	
		Button back_button;											// Declare our button
		Button menu_button;
			Menu select_difficulty_menu;
				Button* difficulty_3_button;
		
	public:
		Game(Point p , int w , int h , const string& name);		//Declare our constructor
		
		static void cb_back(Address , Address);						//Declare our callback function
		void back_button_function();
		
		static void cb_menu_pressed(Address , Address);		//Declare our callback function
		void menu_pressed();
		
		static void cb_select_difficulty(Address , Address);		//Declare our callback function
		void select_difficulty_button_function();
};

#endif