#include "std_lib_facilities_4.h"
#include "Graph.h"
#include "Window.h"
#include "GUI.h"
using namespace Graph_lib;

class Project_Menu
{
	protected:					// Defining constants for the size of the winodw that will be the base window that we will draw on
		int xmax = 800;
		int ymax = 800;
		Point origin = {0,0};
		String window_name;		//Title of window will be filled in later
		Graph_lib::Window *pointer_to_window;	//Creates a pointer to Window object (We will fill this later)
		void return_window(string window_name);		//Create a fucntion draws our window in free storage
	public:
	//BOOTUP FUNCTIONS AND BUTTONS
		void tutorial();
		void quit();							//Our function for closing the window
		void detach_Bootup_buttons();
};
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//
void Project_Menu::return_window(string window_name)	//Takes the name of the window as an argument
{
	Graph_lib::Window *base_window = new Graph_lib::Window (origin , xmax , ymax , window_name );	//create a pointer to some unnamed window object with these properties
	pointer_to_window = base_window;		//This pointer (and its stored address) will be deleted once we leave this function so we copy it into a pre-declared pinter
}
//- - - BOOTUP FUNCTIONS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//
void Project_Menu::detach_Bootup_buttons()
{
	pointer_to_window -> detach(exit_button);
	pointer_to_window -> detach(tutorial_button);
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//

	void Project_Menu::tutorial()	//Our function for opeining the tutorial screen
	{
		cout << "Called tutorial";
		detach_Bootup_buttons();	//detatches all the buttons
	}
	
	void Project_Menu::quit()	//Our function for quit
	{
		cout << "Called exit";
		//pointer_to_window -> hide();	//delete the window
	}