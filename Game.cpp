#include "Game.h"
#include "Window_Manager.h"

//Go and find our instance of Manager_Window
extern Window_Manager manager_instance;

// - - - - - Constructor - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
Game::Game(Point p , int w , int h , const string& name)		//Define our constructor
: Graph_lib::Window(p, w, h, name),
  rectangle_w_h (75),
  c_digits(0),
  c_operands(0),
  back_button{Point {10, 10} , 50 , 30, "back" , cb_back} ,		//define the buttons we want to attach
  menu_button{Point {513, 385} , 175 , 30, "Select the Difficulty Level" , cb_menu_pressed} ,
  select_difficulty_menu{Point {463, 385} , 65 , 30, Menu::horizontal , "Select The Difficulty Level"} , 
  difficulty_3_button(new Button {Point {190, 700} , 50 , 30, "3" , cb_difficulty_3}) , /////////////MENU BUTTONS//////////
  difficulty_4_button(new Button {Point {300, 700} , 50 , 30, "4" , cb_difficulty_4}) ,
  difficulty_5_button(new Button {Point {330, 700} , 50 , 30, "5" , cb_difficulty_5}) ,
  difficulty_6_button(new Button {Point {390, 700} , 50 , 30, "6" , cb_difficulty_6}) ,
  difficulty_7_button(new Button {Point {450, 700} , 50 , 30, "7" , cb_difficulty_7}) ,
 ////////////////TOP ROW BOXES////////////////////////////////////
  box_1a {Point{263,200} , rectangle_w_h , rectangle_w_h} ,
  box_2a {Point{363,200} , rectangle_w_h , rectangle_w_h} ,
  box_3a {Point{463,200} , rectangle_w_h , rectangle_w_h} ,
  box_4a {Point{563,200} , rectangle_w_h , rectangle_w_h} ,
  box_5a {Point{663,200} , rectangle_w_h , rectangle_w_h} ,
  box_6a {Point{763,200} , rectangle_w_h , rectangle_w_h} ,
  box_7a {Point{863,200} , rectangle_w_h , rectangle_w_h} ,
////////////////BOTTOM ROW BOXES//////////////////////////////////
  box_1b {Point{263,400} , rectangle_w_h , rectangle_w_h} ,
  box_2b {Point{363,400} , rectangle_w_h , rectangle_w_h} ,
  box_3b {Point{463,400} , rectangle_w_h , rectangle_w_h} ,
  box_4b {Point{563,400} , rectangle_w_h , rectangle_w_h} ,
  box_5b {Point{663,400} , rectangle_w_h , rectangle_w_h} ,
  box_6b {Point{763,400} , rectangle_w_h , rectangle_w_h} ,
  box_7b {Point{863,400} , rectangle_w_h , rectangle_w_h} ,
  button_1a{Point {463, 200} , rectangle_w_h , rectangle_w_h, "1", cb_button_1a} ,		//ISSUE BUTTON ONLY TAKES CONST string& WE NEED IT TO TAKE A CHAR
  button_2a{Point {563, 200} , rectangle_w_h , rectangle_w_h, "2" , cb_button_2a} ,
  button_3a{Point {663, 200} , rectangle_w_h , rectangle_w_h, "3" , cb_button_3a} ,
  button_4a{Point {763, 200} , rectangle_w_h , rectangle_w_h, "4", cb_button_4a} ,		//ISSUE BUTTON ONLY TAKES CONST string& WE NEED IT TO TAKE A CHAR
  button_5a{Point {863, 200} , rectangle_w_h , rectangle_w_h, "5" , cb_button_5a} ,
  button_6a{Point {963, 200} , rectangle_w_h , rectangle_w_h, "6" , cb_button_6a} ,
  button_7a{Point {963, 200} , rectangle_w_h , rectangle_w_h, "7", cb_button_7a} 	//ISSUE BUTTON ONLY TAKES CONST string& WE NEED IT TO TAKE A CHAR

{
	attach(back_button);	//Attach the back button
	attach(menu_button);	//Attach the menu_button button
			select_difficulty_menu.attach(difficulty_3_button);	//Attach buttons to the menu
			select_difficulty_menu.attach(difficulty_4_button);
			select_difficulty_menu.attach(difficulty_5_button);
			select_difficulty_menu.attach(difficulty_6_button);
			select_difficulty_menu.attach(difficulty_7_button);
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
				detach(box_3a);
				detach(box_4a);
				detach(box_5a);
				detach(box_3b);
				detach(box_4b);
				detach(box_5b);
				
				detach(button_1a);
				detach(button_2a);
				detach(button_3a);
				break;
			case 4:
				detach(box_3a);
				detach(box_4a);
				detach(box_5a);
				detach(box_6a);
				detach(box_3b);
				detach(box_4b);
				detach(box_5b);
				detach(box_6b);
				
				detach(button_1a);
				detach(button_2a);
				detach(button_3a);
				detach(button_4a);
				break;
			case 5:
				detach(box_2a);
				detach(box_3a);
				detach(box_4a);
				detach(box_5a);
				detach(box_6a);
				detach(box_2b);
				detach(box_3b);
				detach(box_4b);
				detach(box_5b);
				detach(box_6b);
				
					button_1a.move(100 , 0);
				detach(button_1a);
					button_2a.move(100 , 0);
				detach(button_2a);
					button_3a.move(100 , 0);
				detach(button_3a);
					button_4a.move(100 , 0);
				detach(button_4a);
					button_5a.move(100 , 0);
				detach(button_5a);
		
				break;
			case 6:
				detach(box_2a);
				detach(box_3a);
				detach(box_4a);
				detach(box_5a);
				detach(box_6a);
				detach(box_7a);
				detach(box_2b);
				detach(box_3b);
				detach(box_4b);
				detach(box_5b);
				detach(box_6b);
				detach(box_7b);
				
					button_1a.move(100 , 0);
				detach(button_1a);
					button_2a.move(100 , 0);
				detach(button_2a);
					button_3a.move(100 , 0);
				detach(button_3a);
					button_4a.move(100 , 0);
				detach(button_4a);
					button_5a.move(100 , 0);
				detach(button_5a);
					button_6a.move(100 , 0);
				detach(button_6a);
				break;	
			case 7:
				detach(box_1a);
				detach(box_2a);
				detach(box_3a);
				detach(box_4a);
				detach(box_5a);
				detach(box_6a);
				detach(box_7a);
				detach(box_1b);
				detach(box_2b);
				detach(box_3b);
				detach(box_4b);
				detach(box_5b);
				detach(box_6b);
				detach(box_7b);
				
					button_1a.move(200 , 0);
				detach(button_1a);
					button_2a.move(200 , 0);
				detach(button_2a);
					button_3a.move(200 , 0);
				detach(button_3a);
					button_4a.move(200 , 0);
				detach(button_4a);
					button_5a.move(200 , 0);
				detach(button_5a);
					button_6a.move(200 , 0);
				detach(button_6a);
					button_7a.move(100 , 0);
				detach(button_7a);
				break;	
		}	
			
		difficulty_level = 0;
		c_digits = 0;
		c_operands = 0;
	}
// - - - - - Show Difficulty Menu Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_menu_pressed(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).menu_pressed();
	}
	void Game::menu_pressed()
	{
		dynamic_cast<Game*>(manager_instance.game_window)->menu_button.hide();
		dynamic_cast<Game*>(manager_instance.game_window)->attach(select_difficulty_menu);
	}
// - - - - - Fill a_line vector Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::generate_randomized_vector(vector<char>& a_line)
	{
		int rand_int;
		cout << &a_line << '\n';
		for(int counter = 0; counter < difficulty_level ; ++counter)
		{
			rand_int = rand() % 16;
			cout << "Rand_int number " << counter << " = " <<rand_int << '\n';
			convert_and_insert(a_line , rand_int , counter);
		}
	cout << "There are " << c_digits << "digits, and " << c_operands << " operands\n";
		while (c_digits <= c_operands)
		{
			for(int i = 0 ; i < difficulty_level ; ++i)
			{
				if(!(isdigit(a_line[i])))		//the contents of a_;ine
				{
					int x = rand() % 6 + 10;
					convert_and_insert(a_line , x , i);
					++c_digits;
				}
			}
			
		}
			
	}
// - - - - - Convert and Insert Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::convert_and_insert(vector<char>& a_line , int rand_int , int counter)
	{
		switch (rand_int)												//2 requirements: 1) more digits than operators 2) Balanced Parenthesis
				{
					case 0:
						a_line[counter] = '0';
						++c_digits;
						break;
					case 1:
						a_line[counter] = '1';
						++c_digits;
						break;
					case 2:
						a_line[counter] = '2';
						++c_digits;
						break;
					case 3:
						a_line[counter] = '3';
						++c_digits;
						break;
					case 4:
						a_line[counter] = '4';
						++c_digits;
						break;
					case 5:
						a_line[counter] = '5';
						++c_digits;
						break;
					case 6:
						a_line[counter] = '6';
						++c_digits;
						break;
					case 7:
						a_line[counter] = '7';
						++c_digits;
						break;
					case 8:
						a_line[counter] = '8';
						++c_digits;
						break;
					case 9:
						a_line[counter] = '9';
						++c_digits;
						break;
					case 10:
						a_line[counter] = '+';
						++c_operands;
						break;
					case 11:
						a_line[counter] = '-';
						++c_operands;
						break;
					case 12:
						a_line[counter] = '*';
						++c_operands;
						break;
					case 13:
						a_line[counter] = '/';
						++c_operands;
						break;
					case 14:
						a_line[counter] = '(';
						++c_operands;
						break;
					case 15:
						a_line[counter] = ')';
						++c_operands;
						break;		
				}
	}
		
// - - - - - Difficulty Level 3 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_difficulty_3(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_3_function();
	}
	void Game::difficulty_3_function()
	{
		difficulty_level = 3;
			
		a_line.resize(difficulty_level);
		
		cout << &a_line << '\n';
		generate_randomized_vector(a_line);
		
		dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
			
		attach(box_3a);		//Attach the rectangles which will contain our buttons
		attach(box_4a);
		attach(box_5a);
		attach(box_3b);
		attach(box_4b);
		attach(box_5b);
		
		attach(button_1a);
		attach(button_2a);
		attach(button_3a);		
		
		for(int i = 0 ; i < difficulty_level ; ++i)
		{
			cout << a_line[i] << '\n';
		}
	}
// - - - - - Difficulty Level 4 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_difficulty_4(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_4_function();
	}
	void Game::difficulty_4_function()
	{
		difficulty_level = 4;
		
		a_line.resize(difficulty_level);
		
		dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
			
		attach(box_3a);		//Attach the rectangles which will contain our buttons
		attach(box_4a);
		attach(box_5a);
		attach(box_6a);
		attach(box_3b);
		attach(box_4b);
		attach(box_5b);
		attach(box_6b);
		
		attach(button_1a);
		attach(button_2a);
		attach(button_3a);
		attach(button_4a);
		
	}
// - - - - - Difficulty Level 5 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_difficulty_5(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_5_function();
	}
	void Game::difficulty_5_function()
	{
		difficulty_level = 5;
		a_line.resize(difficulty_level);
		
		dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
		
		attach(box_2a);		//Attach the rectangles which will contain our buttons	
		attach(box_3a);
		attach(box_4a);
		attach(box_5a);
		attach(box_6a);
		attach(box_2b);
		attach(box_3b);
		attach(box_4b);
		attach(box_5b);
		attach(box_6b);
		
		attach(button_1a);
			button_1a.move(-100 , 0);
		attach(button_2a);
			button_2a.move(-100 , 0);
		attach(button_3a);
			button_3a.move(-100 , 0);
		attach(button_4a);
			button_4a.move(-100 , 0);
		attach(button_5a);
			button_5a.move(-100 , 0);
	}
// - - - - - Difficulty Level 6 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_difficulty_6(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_6_function();
	}
	void Game::difficulty_6_function()
	{
		difficulty_level = 6;
		a_line.resize(difficulty_level);
		
		dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
		
		attach(box_2a);		//Attach the rectangles which will contain our buttons	
		attach(box_3a);
		attach(box_4a);
		attach(box_5a);
		attach(box_6a);
		attach(box_7a);		
		attach(box_2b);
		attach(box_3b);
		attach(box_4b);
		attach(box_5b);
		attach(box_6b);
		attach(box_7b);		

		attach(button_1a);
			button_1a.move(-100 , 0);
		attach(button_2a);
			button_2a.move(-100 , 0);
		attach(button_3a);
			button_3a.move(-100 , 0);
		attach(button_4a);
			button_4a.move(-100 , 0);
		attach(button_5a);
			button_5a.move(-100 , 0);
		attach(button_6a);
			button_6a.move(-100 , 0);
	}
// - - - - - Difficulty Level 7 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_difficulty_7(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_7_function();
	}
	void Game::difficulty_7_function()
	{
		difficulty_level = 7;
		a_line.resize(difficulty_level);
		
		dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
		
		attach(box_1a);		//Attach the rectangles which will contain our buttons
		attach(box_2a);		
		attach(box_3a);
		attach(box_4a);
		attach(box_5a);
		attach(box_6a);
		attach(box_7a);	
		attach(box_1b);	
		attach(box_2b);
		attach(box_3b);
		attach(box_4b);
		attach(box_5b);
		attach(box_6b);
		attach(box_7b);
		
		attach(button_1a);
			button_1a.move(-200 , 0);
		attach(button_2a);
			button_2a.move(-200 , 0);
		attach(button_3a);
			button_3a.move(-200 , 0);
		attach(button_4a);
			button_4a.move(-200 , 0);
		attach(button_5a);
			button_5a.move(-200 , 0);
		attach(button_6a);
			button_6a.move(-200 , 0);
		attach(button_7a);
			button_7a.move(-100 , 0);
	}
	
// - - - - - Button 1a Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_1a(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_1a();
	}		
	void Game::button_fct_1a()
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_1a.hide();
		
		b_line.push_back(a_line[0]);
	}
// - - - - - Button 2a Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_2a(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_2a();
	}		
	void Game::button_fct_2a()
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_2a.hide();
		
		b_line.push_back(a_line[1]);
	}
// - - - - - Button 3a Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_3a(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_3a();
	}		
	void Game::button_fct_3a()
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_3a.hide();
		
		b_line.push_back(a_line[2]);
	}
// - - - - - Button 4a Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_4a(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_4a();
	}		
	void Game::button_fct_4a()
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_4a.hide();
		
		b_line.push_back(a_line[3]);
	}
// - - - - - Button 5a Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_5a(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_5a();
	}		
	void Game::button_fct_5a()
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_5a.hide();
		
		b_line.push_back(a_line[4]);
	}
// - - - - - Button 6a Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_6a(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_6a();
	}		
	void Game::button_fct_6a()
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_6a.hide();
		
		b_line.push_back(a_line[5]);
	}
// - - - - - Button 7a Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_7a(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_7a();
	}		
	void Game::button_fct_7a()
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_7a.hide();
		
		b_line.push_back(a_line[6]);
	}


