#include "Tutorial.h"
#include "Window_Manager.h"

//Go and find our instance of Manager_Window
extern Window_Manager manager_instance;

// - - - - - Constructor - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
Tutorial::Tutorial(Point p , int w , int h , const string& name)		//Define our constructor
: Graph_lib::Window(p, w, h, name),
  quit_button{Point {1125, 05} , 50 , 30, "Quit" , cb_quit}	,
  back_button{Point {10, 10} , 50 , 30, "Back" , cb_back} ,			//define the buttons and text we want to attach
  move_to_game_button{Point {550, 300} , 100 , 50, "Game" , cb_move_to_game} ,
  move_to_highscores_button{Point {550, 400} , 100 , 50, "Highscores" , cb_move_to_highscores},
  
  first_line{Point {100,100} , "The object of the game is to rearrange a certain number of tiles to yield the highest arithmetic value."},
  second_line{Point {100,118} , "After choosing your difficulty level, a corresponding number of tiles will appear."},
  third_line{Point {100,136} , "Select these tiles in the order you wish to play them."},
  fourth_line{Point {100,172} , "EXAMPLES:"},
  fifth_line{Point {150,190} , "'4 + 5' would yield 9"},
  sixth_line{Point {150,208} , "'+ 5 4' would yield 54"},
  seventh_line{Point {150,226} , "'5 4 +' would yield 0, as it is not a valid mathmatical expression"},
  
  outline_text{Point{95,81}, 645, 151}								//Rectangle outlining text
{
	attach(back_button);											//Attach the buttons and text
	attach(quit_button);
	attach(move_to_game_button);
	attach(move_to_highscores_button);
	attach(first_line);
	attach(second_line);
	attach(third_line);
	attach(fourth_line);
	attach(fifth_line);
	attach(sixth_line);
	attach(seventh_line);
	attach(outline_text);
}
// - - - - - Back Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Tutorial::cb_back(Address, Address pw)							//Define our call back function
	{
		reference_to<Tutorial>(pw).back_button_function();
	}
	
	void Tutorial::back_button_function()
	{
		manager_instance.tutorial_window->hide();							
		manager_instance.bootup_window->show();							// Run hide() on the member (bootup_window) of manager_instance		
	}
// - - - - - Quit Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Tutorial::cb_quit(Address, Address pw)							//Define our call back function
	{
		manager_instance.tutorial_window->hide();							// Run hide() on the member (bootup_window) of manager_instance
	}
// - - - - - Game Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Tutorial::cb_move_to_game(Address , Address pw)
	{
		reference_to<Tutorial>(pw).show_game();
	}
	void Tutorial::show_game()
	{
		manager_instance.tutorial_window->hide();
		manager_instance.game_window->show();
	}
// - - - - - High Score Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Tutorial::cb_move_to_highscores(Address , Address pw)
	{
		reference_to<Tutorial>(pw).show_highscores();
	}
	void Tutorial::show_highscores()
	{
		manager_instance.tutorial_window->hide();
		manager_instance.highscores_window->show();
	}