#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include "std_lib_facilities_4.h"
#include "Graph.h"
#include "Window.h"
#include "GUI.h"
#include "Point.h"


using namespace Graph_lib;

//INHERITED CLASS

class Window_Manager
{
	private:
		Point origin;
		int window_xmax;
		int window_ymax;
		
		
	public:
		//Declare a Constructor
			Window_Manager();
		//Declare a Destructor 
			~Window_Manager();
		
		//Declare Windows for various Menus
		Graph_lib::Window* bootup_window;
		Graph_lib::Window* tutorial_window;
		Graph_lib::Window* game_window;
		Graph_lib::Window* highscores_window;
};

#endif