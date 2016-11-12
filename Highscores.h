#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include "Window.h"
#include "GUI.h"

using namespace Graph_lib;

class Highscores : public Graph_lib::Window	//Extend Tutorial from Graph_lib::Window
{
	private:
		Button back_button;											// Declare our button
	public:
		Highscores(Point p , int w , int h , const string& name);		//Declare our constructor
		
		static void cb_back(Address , Address);						//Declare our callback function
		void back_button_function();
};

#endif