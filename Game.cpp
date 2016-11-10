#include "Game.h"
#include "Window_Manager.h"

//Go and find our instance of Manager_Window
extern Window_Manager manager_instance;

// - - - - - Constructor - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
Game::Game(Point p , int w , int h , const string& name)		//Define our constructor
: Graph_lib::Window(p, w, h, name),
  back_button{Point {10, 10} , 50 , 30, "back" , cb_back} ,		//define the buttons we want to attach
  menu_button{Point {400, 385} , 175 , 40, "Select the Difficulty Level" , cb_menu_pressed} ,
  select_difficulty_menu{Point {455, 480} , 75 , 30, Menu::horizontal , "Select The Difficulty Level"} , 
  difficulty_3_button(new Button {Point {455, 700} , 50 , 30, "3" , cb_select_difficulty})
{
	attach(back_button);	//Attach the button
	attach(menu_button);
			select_difficulty_menu.attach(difficulty_3_button);
	attach(select_difficulty_menu);
	dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
}
// - - - - - Back Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_back(Address, Address pw)							//Define our call back function
	{
		reference_to<Game>(pw).back_button_function();
	}
	void Game::back_button_function()						//Define our call back function
	{
		dynamic_cast<Game*>(manager_instance.game_window)->menu_button.show();
		dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
		manager_instance.game_window->hide();	
		manager_instance.bootup_window->show();							// Run hide() on the member (bootup_window) of manager_instance
	}
// - - - - - High Score Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_menu_pressed(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).menu_pressed();
	}
	void Game::menu_pressed()
	{
		dynamic_cast<Game*>(manager_instance.game_window)->menu_button.hide();
		dynamic_cast<Game*>(manager_instance.game_window)->attach(select_difficulty_menu);
	}
// - - - - - Difficulty Level 3 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_select_difficulty(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).select_difficulty_button_function();
	}
	void Game::select_difficulty_button_function()
	{
		cout << "In difficulty selector";
		
	}
// - - - - - High Score Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //



