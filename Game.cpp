#include "Game.h"
#include "Window_Manager.h"

//Go and find our instance of Manager_Window
extern Window_Manager manager_instance;

// - - - - - Constructor - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
Game::Game(Point p , int w , int h , const string& name)		//Define our constructor
: Graph_lib::Window(p, w, h, name),
  rectangle_w_h (75),
  back_button{Point {10, 10} , 50 , 30, "back" , cb_back} ,		//define the buttons we want to attach
  menu_button{Point {513, 385} , 175 , 30, "Select the Difficulty Level" , cb_menu_pressed} ,
  select_difficulty_menu{Point {340, 385} , 65 , 30, Menu::horizontal , "Select The Difficulty Level"} , 
  difficulty_3_button(new Button {Point {190, 700} , 50 , 30, "3" , cb_difficulty_3}) , /////////////MENU BUTTONS//////////
  difficulty_4_button(new Button {Point {300, 700} , 50 , 30, "4" , cb_difficulty_4}) ,
  difficulty_5_button(new Button {Point {330, 700} , 50 , 30, "5" , cb_difficulty_5}) ,
  difficulty_6_button(new Button {Point {390, 700} , 50 , 30, "6" , cb_difficulty_6}) ,
  difficulty_7_button(new Button {Point {450, 700} , 50 , 30, "7" , cb_difficulty_7}) ,
  difficulty_8_button(new Button {Point {510, 700} , 50 , 30, "8" , cb_difficulty_8}) ,
  difficulty_9_button(new Button {Point {570, 700} , 50 , 30, "9" , cb_difficulty_9}) ,
  difficulty_10_button(new Button {Point {600, 700} , 50 , 30, "10" , cb_difficulty_10}) ,
  box_1a {Point{163,200} , rectangle_w_h , rectangle_w_h} ,////////////////TOP ROW BOXES////////////////////////////////////
  box_2a {Point{263,200} , rectangle_w_h , rectangle_w_h} ,
  box_3a {Point{363,200} , rectangle_w_h , rectangle_w_h} ,
  box_4a {Point{463,200} , rectangle_w_h , rectangle_w_h} ,
  box_5a {Point{563,200} , rectangle_w_h , rectangle_w_h} ,
  box_6a {Point{663,200} , rectangle_w_h , rectangle_w_h} ,
  box_7a {Point{763,200} , rectangle_w_h , rectangle_w_h} ,
  box_8a {Point{863,200} , rectangle_w_h , rectangle_w_h} ,
  box_9a {Point{963,200} , rectangle_w_h , rectangle_w_h} ,
  box_10a{Point{1063,200} , rectangle_w_h , rectangle_w_h} ,
  box_1b {Point{163,400} , rectangle_w_h , rectangle_w_h} ,////////////////BOTTOM ROW BOXES//////////////////////////////////
  box_2b {Point{263,400} , rectangle_w_h , rectangle_w_h} ,
  box_3b {Point{363,400} , rectangle_w_h , rectangle_w_h} ,
  box_4b {Point{463,400} , rectangle_w_h , rectangle_w_h} ,
  box_5b {Point{563,400} , rectangle_w_h , rectangle_w_h} ,
  box_6b {Point{663,400} , rectangle_w_h , rectangle_w_h} ,
  box_7b {Point{763,400} , rectangle_w_h , rectangle_w_h} ,
  box_8b {Point{863,400} , rectangle_w_h , rectangle_w_h} ,
  box_9b {Point{963,400} , rectangle_w_h , rectangle_w_h} ,
  box_10b {Point{1063,400} , rectangle_w_h , rectangle_w_h} ,
  button_4a{Point {463, 200} , rectangle_w_h , rectangle_w_h, "TEST", cb_button_test} ,		//ISSUE BUTTON ONLY TAKES CONST string& WE NEED IT TO TAKE A CHAR
  button_5a{Point {563, 200} , rectangle_w_h , rectangle_w_h, "TEST" , cb_button_test} ,
  button_6a{Point {663, 200} , rectangle_w_h , rectangle_w_h, "TEST" , cb_button_test}
{
	attach(back_button);	//Attach the back button
	attach(menu_button);	//Attach the menu_button button
			select_difficulty_menu.attach(difficulty_3_button);	//Attach buttons to the menu
			select_difficulty_menu.attach(difficulty_4_button);
			select_difficulty_menu.attach(difficulty_5_button);
			select_difficulty_menu.attach(difficulty_6_button);
			select_difficulty_menu.attach(difficulty_7_button);
			select_difficulty_menu.attach(difficulty_8_button);
			select_difficulty_menu.attach(difficulty_9_button);
			select_difficulty_menu.attach(difficulty_10_button);
	attach(select_difficulty_menu);	//Attach the menu
	dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);	//then hide the menu right away
}
// - - - - - Back Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_back(Address, Address pw)							//Define our call back function
	{
		reference_to<Game>(pw).back_button_function();
	}
	void Game::back_button_function()						//Define our call back function
	{
		dynamic_cast<Game*>(manager_instance.game_window)->menu_button.show();
		manager_instance.game_window->hide();	
		manager_instance.bootup_window->show();							// Run hide() on the member (bootup_window) of manager_instance
		switch (difficulty_level){
			case 1: case 2: case 3:				//For whichever difficulty is pressed hide the boxes we showed upon going back
				detach(box_4a);
				detach(box_5a);
				detach(box_6a);
				detach(box_4b);
				detach(box_5b);
				detach(box_6b);
				break;
			case 4:
				detach(box_4a);
				detach(box_5a);
				detach(box_6a);
				detach(box_7a);
				detach(box_4b);
				detach(box_5b);
				detach(box_6b);
				detach(box_7b);
				break;
			case 5:
				detach(box_3a);
				detach(box_4a);
				detach(box_5a);
				detach(box_6a);
				detach(box_7a);
				detach(box_3b);
				detach(box_4b);
				detach(box_5b);
				detach(box_6b);
				detach(box_7b);
				break;
			case 6:
				detach(box_3a);
				detach(box_4a);
				detach(box_5a);
				detach(box_6a);
				detach(box_7a);
				detach(box_8a);
				detach(box_3b);
				detach(box_4b);
				detach(box_5b);
				detach(box_6b);
				detach(box_7b);
				detach(box_8b);
				break;	
			case 7:
				detach(box_2a);
				detach(box_3a);
				detach(box_4a);
				detach(box_5a);
				detach(box_6a);
				detach(box_7a);
				detach(box_8a);
				detach(box_2b);
				detach(box_3b);
				detach(box_4b);
				detach(box_5b);
				detach(box_6b);
				detach(box_7b);
				detach(box_8b);
				break;	
			case 8:
				detach(box_2a);
				detach(box_3a);
				detach(box_4a);
				detach(box_5a);
				detach(box_6a);
				detach(box_7a);
				detach(box_8a);
				detach(box_9a);
				detach(box_2b);
				detach(box_3b);
				detach(box_4b);
				detach(box_5b);
				detach(box_6b);
				detach(box_7b);
				detach(box_8b);
				detach(box_9b);
				break;
			case 9:
				detach(box_1a);
				detach(box_2a);
				detach(box_3a);
				detach(box_4a);
				detach(box_5a);
				detach(box_6a);
				detach(box_7a);
				detach(box_8a);
				detach(box_9a);
				detach(box_1b);
				detach(box_2b);
				detach(box_3b);
				detach(box_4b);
				detach(box_5b);
				detach(box_6b);
				detach(box_7b);
				detach(box_8b);
				detach(box_9b);
				break;
			case 10:
				detach(box_1a);
				detach(box_2a);
				detach(box_3a);
				detach(box_4a);
				detach(box_5a);
				detach(box_6a);
				detach(box_7a);
				detach(box_8a);
				detach(box_9a);
				detach(box_10a);
				detach(box_1b);
				detach(box_2b);
				detach(box_3b);
				detach(box_4b);
				detach(box_5b);
				detach(box_6b);
				detach(box_7b);
				detach(box_8b);
				detach(box_9b);
				detach(box_10b);
				break;	
				}
		difficulty_level = 0;		
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
	void Game::cb_difficulty_3(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_3_function();
	}
	void Game::difficulty_3_function()
	{
		difficulty_level = 3;
		
		dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
			
		attach(box_4a);		//Attach the rectangles which will contain our buttons
		attach(box_5a);
		attach(box_6a);
		attach(box_4b);
		attach(box_5b);
		attach(box_6b);
		
		attach(button_4a);
		attach(button_5a);
		attach(button_6a);
	
		a_line.resize(difficulty_level);
		b_line.resize(difficulty_level);
		
		a_line[0] = '7';
		a_line[1] = '+';
		a_line[2] = '9';
		
		text_4a = a_line[0];
		text_5a = a_line[1];
		text_6a = a_line[2];		
		
		
	}
// - - - - - Difficulty Level 4 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_difficulty_4(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_4_function();
	}
	void Game::difficulty_4_function()
	{
		difficulty_level = 4;
		dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
			
		attach(box_4a);		//Attach the rectangles which will contain our buttons
		attach(box_5a);
		attach(box_6a);
		attach(box_7a);
		attach(box_4b);
		attach(box_5b);
		attach(box_6b);
		attach(box_7b);
		
	}
// - - - - - Difficulty Level 5 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_difficulty_5(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_5_function();
	}
	void Game::difficulty_5_function()
	{
		difficulty_level = 5;
		dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
		
		attach(box_3a);		//Attach the rectangles which will contain our buttons	
		attach(box_4a);
		attach(box_5a);
		attach(box_6a);
		attach(box_7a);
		attach(box_3b);
		attach(box_4b);
		attach(box_5b);
		attach(box_6b);
		attach(box_7b);
	}
// - - - - - Difficulty Level 6 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_difficulty_6(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_6_function();
	}
	void Game::difficulty_6_function()
	{
		difficulty_level = 6;
		dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
		
		attach(box_3a);		//Attach the rectangles which will contain our buttons	
		attach(box_4a);
		attach(box_5a);
		attach(box_6a);
		attach(box_7a);
		attach(box_8a);		
		attach(box_3b);
		attach(box_4b);
		attach(box_5b);
		attach(box_6b);
		attach(box_7b);
		attach(box_8b);				
	}
// - - - - - Difficulty Level 7 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_difficulty_7(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_7_function();
	}
	void Game::difficulty_7_function()
	{
		difficulty_level = 7;
		dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
		
		attach(box_2a);		//Attach the rectangles which will contain our buttons
		attach(box_3a);		
		attach(box_4a);
		attach(box_5a);
		attach(box_6a);
		attach(box_7a);
		attach(box_8a);	
		attach(box_2b);	
		attach(box_3b);
		attach(box_4b);
		attach(box_5b);
		attach(box_6b);
		attach(box_7b);
		attach(box_8b);
	}
// - - - - - Difficulty Level 8 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_difficulty_8(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_8_function();
	}
	void Game::difficulty_8_function()
	{
		difficulty_level = 8;
		dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
		
		attach(box_2a);		//Attach the rectangles which will contain our buttons
		attach(box_3a);		
		attach(box_4a);
		attach(box_5a);
		attach(box_6a);
		attach(box_7a);
		attach(box_8a);	
		attach(box_9a);	
		attach(box_2b);	
		attach(box_3b);
		attach(box_4b);
		attach(box_5b);
		attach(box_6b);
		attach(box_7b);
		attach(box_8b);
		attach(box_9b);			
	}
// - - - - - Difficulty Level 9 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_difficulty_9(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_9_function();
	}
	void Game::difficulty_9_function()
	{
		difficulty_level = 9;
		dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
		
		attach(box_1a);		//Attach the rectangles which will contain our buttons
		attach(box_2a);	
		attach(box_3a);		
		attach(box_4a);
		attach(box_5a);
		attach(box_6a);
		attach(box_7a);
		attach(box_8a);	
		attach(box_9a);	
		attach(box_1b);
		attach(box_2b);	
		attach(box_3b);
		attach(box_4b);
		attach(box_5b);
		attach(box_6b);
		attach(box_7b);
		attach(box_8b);
		attach(box_9b);	
		
	}
// - - - - - Difficulty Level 10 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_difficulty_10(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_10_function();
	}
	void Game::difficulty_10_function()
	{
		difficulty_level = 9;
		dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
		
		attach(box_1a);		//Attach the rectangles which will contain our buttons
		attach(box_2a);	
		attach(box_3a);		
		attach(box_4a);
		attach(box_5a);
		attach(box_6a);
		attach(box_7a);
		attach(box_8a);	
		attach(box_9a);	
		attach(box_10a);
		attach(box_1b);
		attach(box_2b);	
		attach(box_3b);
		attach(box_4b);
		attach(box_5b);
		attach(box_6b);
		attach(box_7b);
		attach(box_8b);
		attach(box_9b);
		attach(box_10b);		
	}

// - - - - - High Score Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_test(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_test();
	}		
	void Game::button_test()
	{
		cout << "In Button Test\n";
		dynamic_cast<Game*>(manager_instance.game_window)->button_4a.hide();
		
		cout << a_line[0] << '\n';
	}


