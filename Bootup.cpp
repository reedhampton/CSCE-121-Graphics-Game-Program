#include "Bootup.h"
#include "Window_Manager.h"

//Go and find our instance of Manager_Window
extern Window_Manager manager_instance;

// - - - - - Constructor - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
Bootup::Bootup(Point p , int w , int h , const string& name)		//Define our constructor
: Graph_lib::Window(p, w, h, name),
  quit_button{Point {1125, 05} , 50 , 30, "Quit" , cb_quit}	,		//define the buttons and text we want to attach
  move_to_tutorial_button{Point {796, 200} , 100 , 50, "Tutorial" , cb_move_to_tutorial} , 
  move_to_game_button{Point {796, 300} , 100 , 50, "Game" , cb_move_to_game} ,
  move_to_highscores_button{Point {796, 400} , 100 , 50, "Highscores" , cb_move_to_highscores},
  game_name{Point {726,100} , "THE SUPER ADDER"},
  team_number{Point {572,750} , "Team 19"},
  team_kyle{Point {23,780} , "Kyle Jackson"},
  team_reed{Point {552,780} , "Reed Hampton"},
  team_sam{Point {1107,780} , "Sam Giese"},
  japanese_wave{Point {0,0}, "japanese_wave.jpg"}

  
{
	attach(japanese_wave);
	
	game_name.set_font_size(24);
	attach(game_name);
	attach(team_number);
	attach(team_kyle);
	attach(team_reed);
	attach(team_sam);
	
	attach(quit_button);											//Attach the buttons and text
	attach(move_to_tutorial_button);
	attach(move_to_game_button);
	attach(move_to_highscores_button);
	
	detach(move_to_tutorial_button);
	attach(move_to_tutorial_button);

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
	void Bootup::cb_move_to_highscores(Address , Address pw)
	{
		reference_to<Bootup>(pw).show_highscores();
	}
	void Bootup::show_highscores()
	{
		manager_instance.bootup_window->hide();
		manager_instance.highscores_window->show();
	}



