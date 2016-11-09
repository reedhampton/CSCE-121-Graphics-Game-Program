#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "GUI.h"

using namespace Graph_lib;

class Game : public Graph_lib::Window	//Extend Bootup from Graph_lib::Window
{
	private:
		Button back_button;											// Declare our button
	public:
		Game(Point p , int w , int h , const string& name);		//Declare our constructor
		
		static void cb_back(Address , Address);						//Declare our callback function
		void back_button_function();
};

#endif