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
		
		vector <char> a_line;
		vector <char> b_line;
		
		char text_1a;
		char text_2a;
		char text_3a;
		char text_4a;
		char text_5a;
		char text_6a;
		char text_7a;
		char text_8a;
		char text_9a;
		char text_10a;
		
		char text_1b;
		char text_2b;
		char text_3b;
		char text_4b;
		char text_5b;
		char text_6b;
		char text_7b;
		char text_8b;
		char text_9b;
		char text_10b;
	
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
				
		Rectangle box_1a;					//Rectangle containers for the top row
		Rectangle box_2a;
		Rectangle box_3a;
		Rectangle box_4a;
		Rectangle box_5a;
		Rectangle box_6a;
		Rectangle box_7a;
		Rectangle box_8a;
		Rectangle box_9a;
		Rectangle box_10a;
		
		Rectangle box_1b;					// rectangle containers for the bottom row
		Rectangle box_2b;
		Rectangle box_3b;
		Rectangle box_4b;
		Rectangle box_5b;
		Rectangle box_6b;
		Rectangle box_7b;
		Rectangle box_8b;
		Rectangle box_9b;
		Rectangle box_10b;
		
		Button button_1a;					//Buttons to fill the top row
		Button button_2a;
		Button button_3a;
		Button button_4a;
		Button button_5a;
		Button button_6a;
		Button button_7a;
		Button button_8a;
		Button button_9a;
		Button button_10a;
		/*
		Button button_1b;					//Buttons to fill the bottom row
		Button button_2b;
		Button button_3b;
		Button button_4b;
		Button button_5b;
		Button button_6b;
		Button button_7b;
		Button button_8b;
		Button button_9b;
		Button button_10b;*/
		
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
		
		static void cb_button_1a(Address , Address);	//Declare our callback function
		void button_fct_1a();
		
		static void cb_button_2a(Address , Address);	//Declare our callback function
		void button_fct_2a();
		
		static void cb_button_3a(Address , Address);	//Declare our callback function
		void button_fct_3a();
		
		static void cb_button_4a(Address , Address);	//Declare our callback function
		void button_fct_4a();
		
		static void cb_button_5a(Address , Address);	//Declare our callback function
		void button_fct_5a();
		
		static void cb_button_6a(Address , Address);	//Declare our callback function
		void button_fct_6a();
		
		static void cb_button_7a(Address , Address);	//Declare our callback function
		void button_fct_7a();
		
		static void cb_button_8a(Address , Address);	//Declare our callback function
		void button_fct_8a();
		
		static void cb_button_9a(Address , Address);	//Declare our callback function
		void button_fct_9a();
		
		static void cb_button_10a(Address , Address);	//Declare our callback function
		void button_fct_10a();
};

#endif