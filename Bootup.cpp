#include "Bootup.h"
#include "Window_Manager.h"

//Go and find our instance of Manager_Window
extern Window_Manager manager_instance;

// - - - - - Constructor - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
Bootup::Bootup(Point p , int w , int h , const string& name)		//Define our constructor
: Graph_lib::Window(p, w, h, name),
  quit_button{Point {840, 05} , 50 , 30, "Quit" , cb_quit}	,		//define the buttons we want to attach
  move_to_tutorial_button{Point {425, 200} , 75 , 50, "Tutorial" , cb_move_to_tutorial} , 
  move_to_game_button{Point {425, 300} , 75 , 50, "Game" , cb_move_to_game}
{
	attach(quit_button);											//Attach the button
	attach(move_to_tutorial_button);
	attach(move_to_game_button);
}
// - - - - - Quit Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Bootup::cb_quit(Address, Address pw)							//Define our call back function
	{
		manager_instance.bootup_window->hide();							// Run hide() on the member (bootup_window) of manager_instance
	}
// - - - - - Tutorial Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Bootup::cb_move_to_tutorial(Address , Address pw)
	{
		reference_to<Bootup>(pw).show_tutorial();
	}
	void Bootup::show_tutorial()
	{
		manager_instance.bootup_window->hide();
		manager_instance.tutorial_window->show();
	}
// - - - - - Game Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Bootup::cb_move_to_game(Address , Address pw)
	{
		reference_to<Bootup>(pw).show_game();
	}
	void Bootup::show_game()
	{
		manager_instance.bootup_window->hide();
		manager_instance.game_window->show();
	}

// - - - - - High Score Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //



