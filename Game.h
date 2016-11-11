#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "GUI.h"

using namespace Graph_lib;

class Game : public Graph_lib::Window	//Extend Bootup from Graph_lib::Window
{
	private:
		int rectangle_w_h;
		int difficulty_level;						// 3 - 10
	
		Button back_button;											// Declare our button
		Button menu_button;
			Menu select_difficulty_menu;
				Button* difficulty_3_button;
				Button* difficulty_4_button;
				Button* difficulty_5_button;
				Button* difficulty_6_button;
				Button* difficulty_7_button;
				Button* difficulty_8_button;
				Button* difficulty_9_button;
				Button* difficulty_10_button;
				
		Rectangle box_1a;
		Rectangle box_2a;
		Rectangle box_3a;
		Rectangle box_4a;
		Rectangle box_5a;
		Rectangle box_6a;
		Rectangle box_7a;
		Rectangle box_8a;
		Rectangle box_9a;
		Rectangle box_10a;
		
		Rectangle box_1b;
		Rectangle box_2b;
		Rectangle box_3b;
		Rectangle box_4b;
		Rectangle box_5b;
		Rectangle box_6b;
		Rectangle box_7b;
		Rectangle box_8b;
		Rectangle box_9b;
		Rectangle box_10b;
		
	public:
		Game(Point p , int w , int h , const string& name);		//Declare our constructor
		
		static void cb_back(Address , Address);						//Declare our callback function
		void back_button_function();
		
		static void cb_menu_pressed(Address , Address);		//Declare our callback function
		void menu_pressed();
		
		static void cb_difficulty_3(Address , Address);		//Declare our callback function
		void difficulty_3_function();
		
		static void cb_difficulty_4(Address , Address);		//Declare our callback function
		void difficulty_4_function();
		
		static void cb_difficulty_5(Address , Address);		//Declare our callback function
		void difficulty_5_function();
		
		static void cb_difficulty_6(Address , Address);		//Declare our callback function
		void difficulty_6_function();
		
		static void cb_difficulty_7(Address , Address);		//Declare our callback function
		void difficulty_7_function();
		
		static void cb_difficulty_8(Address , Address);		//Declare our callback function
		void difficulty_8_function();
		
		static void cb_difficulty_9(Address , Address);		//Declare our callback function
		void difficulty_9_function();
		
		static void cb_difficulty_10(Address , Address);	//Declare our callback function
		void difficulty_10_function();
};

#endif