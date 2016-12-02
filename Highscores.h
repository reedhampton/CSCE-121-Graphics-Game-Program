#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include "Window.h"
#include "GUI.h"

using namespace Graph_lib;

class Highscores : public Graph_lib::Window	//Extend Tutorial from Graph_lib::Window
{
	private:
		int difficulty_level;
		
		Text select_diff;
		Text box_title;
		stringstream st;
		string line;
		
		Button back_button;			// Declare our button
		Button difficulty_3_highscores;
		Button difficulty_4_highscores;
		Button difficulty_5_highscores;
		Button difficulty_6_highscores;
		Button difficulty_7_highscores;
				
		//Out box for printing the scores		
		Out_box show_scores;
		
	public:
		Highscores(Point p , int w , int h , const string& name);		//Declare our constructor
		
		static void cb_back(Address , Address);						//Declare our callback function
		void back_button_function();
		
		//static void cb_menu_pressed(Address , Address);		//Declare our callback function
		//void hs_menu_pressed();
		
		static void cb_difficulty_3(Address , Address);		//Declare our callback function
		void highscores_3_function();
		
		static void cb_difficulty_4(Address , Address);		//Declare our callback function
		void highscores_4_function();
		
		static void cb_difficulty_5(Address , Address);		//Declare our callback function
		void highscores_5_function();
		
		static void cb_difficulty_6(Address , Address);		//Declare our callback function
		void highscores_6_function();
		
		static void cb_difficulty_7(Address , Address);		//Declare our callback function
		void highscores_7_function();
};

#endif