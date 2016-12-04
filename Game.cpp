#include "Game.h"
#include "Window_Manager.h"

//Go and find our instance of Manager_Window
extern Window_Manager manager_instance;

// The Highscore_Values type has to be declared prior to the constructor so that it can be used in the Game.cpp class functions
Highscore_Values::Highscore_Values()
	{
		initials = "";	//set values for fields to empty and 0
		score = 0;
	}
	void Highscore_Values::set_initials(string x)	//create a set_function to set the individual field values. This is for Initials.
	{
		initials = x;
	}
	void Highscore_Values::set_score(double x)		//create a set_function to set the individual field values. This is for Initials.
	{
		score = x;
	}
	
	
// - - - - - Constructor - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
Game::Game(Point p , int w , int h , const string& name)		//Define our constructor
: Graph_lib::Window(p, w, h, name),
  ////////////////DEFINE ALL OF OUR CONSTANTS STRING AND NUMERICAL//////////////////////////////////
  rectangle_w_h (75),
  highscore_label("Highscores:") , 
  string_to_outbox("") , 
  difficulty_level(0) , 
  c_digits(0),
  c_operands(0),
  c_left_parenthesis(0) , 
  c_right_parenthesis(0) ,
  equation_result(0) , 
  equation_result_string("Your score is: ") ,
  user_initials("UNK") ,
  b_line_counter(-1) ,
  remove_initials_box (false) ,
  remove_score_elements (false) ,
 ////////////////INITIAL STRING VALUES IN ALL BUTTONS//////////////////////////////////
  button_1a_content("") ,
  button_2a_content("") , 
  button_3a_content("") ,
  button_4a_content("") ,
  button_5a_content("") ,
  button_6a_content("") ,
  button_7a_content("") ,
  button_1b_content("") ,
  button_2b_content("") , 
  button_3b_content("") ,
  button_4b_content("") ,
  button_5b_content("") ,
  button_6b_content("") ,
  button_7b_content("") ,
  final_score_text("Your score is: "),
////////////////INITIAL BUTTONS TO ATTACH//////////////////////////////////
  back_button{Point {10, 10} , 50 , 30, "back" , cb_back} ,		
  menu_button{Point {513, 385} , 175 , 30, "Select the Difficulty Level" , cb_menu_pressed} ,
  select_difficulty_menu{Point {463, 385} , 65 , 30, Menu::horizontal , "Select The Difficulty Level"} , 
  box_for_initials{Point {513, 285} , 175 , 20, "Please enter your intials:"} , 
////////////////HIGHSCORE OUTPUT TO ATTACH//////////////////////////////////
  game_screen_highscore_label{Point{1000 , 30},highscore_label} ,
  game_screen_scores_1{Point{1000 , 50},string_to_outbox} , 
  game_screen_scores_2{Point{1000 , 70},string_to_outbox} , 
  game_screen_scores_3{Point{1000 , 90},string_to_outbox} , 
  game_screen_scores_4{Point{1000 , 110},string_to_outbox} , 
  game_screen_scores_5{Point{1000 , 130},string_to_outbox} , 
////////////////MENU BUTTONS TO ATTACH//////////////////////////////////
  difficulty_3_button(new Button {Point {190, 700} , 50 , 30, "3" , cb_difficulty_3}) , 
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
////////////////TOP ROW BUTTONS////////////////////////////////
  button_1a{Point {463, 200} , rectangle_w_h , rectangle_w_h, button_1a_content, cb_button_1a} ,		
  button_2a{Point {563, 200} , rectangle_w_h , rectangle_w_h, button_2a_content , cb_button_2a} ,
  button_3a{Point {663, 200} , rectangle_w_h , rectangle_w_h, button_3a_content , cb_button_3a} ,
  button_4a{Point {763, 200} , rectangle_w_h , rectangle_w_h, button_4a_content, cb_button_4a} ,		
  button_5a{Point {863, 200} , rectangle_w_h , rectangle_w_h, button_5a_content , cb_button_5a} ,
  button_6a{Point {963, 200} , rectangle_w_h , rectangle_w_h, button_6a_content , cb_button_6a} ,
  button_7a{Point {963, 200} , rectangle_w_h , rectangle_w_h, button_7a_content, cb_button_7a} ,
////////////////BOTTOM ROW BUTTONS////////////////////////////////
  button_1b{Point {463, 400} , rectangle_w_h , rectangle_w_h, button_1b_content, cb_button_1b} ,		
  button_2b{Point {563, 400} , rectangle_w_h , rectangle_w_h, button_2b_content , cb_button_2b} ,
  button_3b{Point {663, 400} , rectangle_w_h , rectangle_w_h, button_3b_content , cb_button_3b} ,
  button_4b{Point {763, 400} , rectangle_w_h , rectangle_w_h, button_4b_content, cb_button_4b} ,		
  button_5b{Point {863, 400} , rectangle_w_h , rectangle_w_h, button_5b_content , cb_button_5b} ,
  button_6b{Point {963, 400} , rectangle_w_h , rectangle_w_h, button_6b_content , cb_button_6b} ,
  button_7b{Point {963, 400} , rectangle_w_h , rectangle_w_h, button_7b_content, cb_button_7b} ,
////////////////ATTACH ALL GUI AND GRAPH ELEMENTS FOR THE SCORE OUTPUT//////////////////////////////// 
  evaluate{Point {1000, 700} , (2*rectangle_w_h) , rectangle_w_h, "Evaluate", cb_evaluate} ,
  score_box {Point{100,500} , (4*rectangle_w_h) , (3*rectangle_w_h)},
  final_score{Point{140 , 570 } , equation_result_string} ,
  move_to_highscores_button{Point{100 , 650} , (4*rectangle_w_h) , rectangle_w_h, "Click to see the Highscores!" , cb_move_to_highscores}

{
	attach(back_button);	//Attach the back button
	
	attach(game_screen_highscore_label);	//Attach all of the highscore output text objects for the game screen
	attach(game_screen_scores_1);
	attach(game_screen_scores_2);
	attach(game_screen_scores_3);
	attach(game_screen_scores_4);
	attach(game_screen_scores_5);
	
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
	void Game::back_button_function()						//Define our function that is called through the callback
	{
		dynamic_cast<Game*>(manager_instance.game_window)->menu_button.show();	//show the menu_button so that when we come back to this screen it is there
		manager_instance.game_window->hide();							// Hide our Game window
		manager_instance.bootup_window->show();							// Show our Bootup window

		switch (difficulty_level)		//For whichever difficulty is pressed hide the boxes we showed upon going back
		{
			case 0:	//No difficulty level selected		
				dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
				break;
			case 1: case 2: case 3:	// Difficulty levels 1-3			
				detach(box_3a);
				detach(box_4a);
				detach(box_5a);
				detach(box_3b);
				detach(box_4b);
				detach(box_5b);
				
				detach(button_1a);
				detach(button_2a);
				detach(button_3a);
				detach(button_1b);
				detach(button_2b);
				detach(button_3b);
				break;
			case 4:					//Difficulty level 4
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
				detach(button_1b);
				detach(button_2b);
				detach(button_3b);
				detach(button_4b);
				break;
			case 5:				//Difficulty level 5
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
					button_1b.move(100 , 0);
				detach(button_1b);
					button_2b.move(100 , 0);
				detach(button_2b);
					button_3b.move(100 , 0);
				detach(button_3b);
					button_4b.move(100 , 0);
				detach(button_4b);
					button_5b.move(100 , 0);
				detach(button_5b);
				break;
			case 6:					//Difficulty level 6
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
					button_1b.move(100 , 0);
				detach(button_1b);
					button_2b.move(100 , 0);
				detach(button_2b);
					button_3b.move(100 , 0);
				detach(button_3b);
					button_4b.move(100 , 0);
				detach(button_4b);
					button_5b.move(100 , 0);
				detach(button_5b);
					button_6b.move(100 , 0);
				detach(button_6b);
				break;	
			case 7:					//Difficulty level 7
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
					button_1b.move(200 , 0);
				detach(button_1b);
					button_2b.move(200 , 0);
				detach(button_2b);
					button_3b.move(200 , 0);
				detach(button_3b);
					button_4b.move(200 , 0);
				detach(button_4b);
					button_5b.move(200 , 0);
				detach(button_5b);
					button_6b.move(200 , 0);
				detach(button_6b);
					button_7b.move(100 , 0);
				detach(button_7b);
				break;	
		}	
		/////////////////RESETTING ALL VARIABLES TO THEIR INITIAL STATES AFTER EACH RUN/////////////////////////	
		c_digits = 0;
		c_operands = 0;
		c_left_parenthesis = 0;
		c_right_parenthesis = 0;
		equation_result = 0;
		equation_result_string = "Your score is: ";
		b_line_counter = -1;
		user_initials = "UNK";
		
		button_1a_content = "";			//Clear the top row button contents
		button_2a_content = ""; 
		button_3a_content = "";
		button_4a_content = "";
		button_5a_content = "";
		button_6a_content = "";
		button_7a_content = "";
		
		button_1b_content = "";			//Clear the bottom row button contents
		button_2b_content = ""; 
		button_3b_content = "";
		button_4b_content = "";
		button_5b_content = "";
		button_6b_content = "";
		button_7b_content = "";
		
		string clear = "";				//Clear the highscore label text objects
			game_screen_scores_1.set_label(clear);
			game_screen_scores_2.set_label(clear);
			game_screen_scores_3.set_label(clear);
			game_screen_scores_4.set_label(clear);
			game_screen_scores_5.set_label(clear);
		highscore_label = "Highscores: ";
			game_screen_highscore_label.set_label(highscore_label);
		
		if(difficulty_level != 0)		//If we never selected a difficulty level these would never have been attached so we do this to avoid segemntation faults
		{
			detach(evaluate);
		}
		if(difficulty_level != 0 && remove_score_elements == true)		//If we selected a difficulty level but didnt press evaluate these wouldnt have been attached
		{
			detach(score_box);
			detach(final_score);
			detach(move_to_highscores_button);
		}
		if (difficulty_level == 0 && remove_initials_box == true)
		{
			detach(box_for_initials);							//Detach the inbox
		}
			
		a_line.clear();			//clear our vectors and streams
		b_line.clear();
		highscores_vector.clear();
		st.str("");
		//These must be reset after all tests for removing buttons and objects to their intial states
		remove_initials_box = false;
		remove_score_elements = false;
		difficulty_level = 0;
		
	}
// - - - - - Show Difficulty Menu Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_menu_pressed(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).menu_pressed();
	}
	void Game::menu_pressed()		//Hides the menu button and displayes the difficulty level options
	{
			//attach the intials inbox
				attach(box_for_initials);
				remove_initials_box = true;
		dynamic_cast<Game*>(manager_instance.game_window)->menu_button.hide();
		dynamic_cast<Game*>(manager_instance.game_window)->attach(select_difficulty_menu);
	}
// - - - - - Fill a_line vector Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::generate_randomized_vector(vector<char>& a_line)
	{
		int rand_int;	//declare a temporary integer
		for(int counter = 0; counter < difficulty_level ; ++counter)	// create as many random ints as we our difficulty level dictates
		{
			rand_int = rand() % 16;		// generate a random int
			convert_and_insert(a_line , rand_int , counter);	//pass that random int to this function which will match it with the corresponding mathematcal term
		}
		
	int double_check = 0;	// create a temporary counter variable
		while (double_check < 5)	//loop this 5 times to be sure there are no mistakes
		{
				for(int i = 0 ; i < difficulty_level ; ++i)		//Checks to be sure operands exists in the expression
					{
						if(c_operands == 0)		//If there are no operands in the expression
							{
								int x = rand() % 4 + 10;	//generate a random operand
								
								/////////MAKE SURE WE DONT REPLACE ANYTHING ELSE THAT IS VITAL IE: ANOTHER OPERAND OR A LEFT OR RIGHT PARENTHESIS
								if(isdigit(a_line[i]))		
									--c_digits;
								else if(!isdigit(a_line[i]) && (a_line[i] != '(' && a_line[i] != ')'))
									--c_operands;
								else if(a_line[i] == '(')
									--c_left_parenthesis;
								else if (a_line[i] == ')')
									--c_right_parenthesis;
								
								convert_and_insert(a_line , x , i);		// Add it to the expression
							}
					}
		
				for(int i = 0 ; i < difficulty_level ; ++i)		//Checks for more operands than digits and then corrects it by replacing an operand with a digit
					{
						if(c_digits <= c_operands && !(isdigit(a_line[i])))		//turning operators into digits
							{
								int x = rand() % 10;		//generate a random operand
								
								/////////MAKE SURE WE DONT REPLACE ANYTHING ELSE THAT IS VITAL IE: ANOTHER OPERAND OR A LEFT OR RIGHT PARENTHESIS
								if(isdigit(a_line[i]))
									--c_digits;
								else if(!isdigit(a_line[i]) && a_line[i] != '(' && a_line[i] != ')')
									--c_operands;
								else if(a_line[i] == '(')
									--c_left_parenthesis;
								else if (a_line[i] == ')')
									--c_right_parenthesis;
								
								convert_and_insert(a_line , x , i);	// Add it to the expression
							}
					}

				for(int i = 0 ; i < difficulty_level ; ++i)		//Checks for matching parenthesis
					{
						if(a_line[i] == '(' && c_right_parenthesis < c_left_parenthesis)	//Are the contents of a_line at i a left parenthesis?
							{
								int right_parenthesis = 15;
								int x = rand() % difficulty_level ;
									while (x == i || (!isdigit(a_line[x])))
										x = rand() % difficulty_level ;
								
								/////////MAKE SURE WE DONT REPLACE ANYTHING ELSE THAT IS VITAL IE: ANOTHER OPERAND OR A LEFT OR RIGHT PARENTHESIS								
								if(isdigit(a_line[x]))
									--c_digits;
								else if(!isdigit(a_line[x]) && (a_line[x] != '(' || a_line[x] != ')'))
									--c_operands;
								else if(a_line[x] == '(')
									--c_left_parenthesis;
								else if (a_line[x] == ')')
									--c_right_parenthesis;
								
								convert_and_insert(a_line , right_parenthesis , x);
								
								i = 0;
								-- i;
							}
						
						else if(a_line[i] == ')' && c_right_parenthesis > c_left_parenthesis)		//Are the contents of a_line at i a right parenthesis?
							{
								int left_parenthesis = 14;
								int x = rand() % difficulty_level ;
									while (x == i || (!isdigit(a_line[x])))
											x = rand() % difficulty_level ;
								
								/////////MAKE SURE WE DONT REPLACE ANYTHING ELSE THAT IS VITAL IE: ANOTHER OPERAND OR A LEFT OR RIGHT PARENTHESIS
								if(isdigit(a_line[x]))
									--c_digits;
								else if(!isdigit(a_line[x]) && (a_line[x] != '(' || a_line[x] != ')'))
									--c_operands;
								else if(a_line[x] == '(')
									--c_left_parenthesis;
								else if (a_line[x] == ')')
									--c_right_parenthesis;
								
								convert_and_insert(a_line , left_parenthesis , x);

								i = 0;
								-- i;
							}
					}
			++double_check;		// add one to our while loop, we want to make sure this expression is computable
		}			
			
	}
// - - - - - Convert and Insert Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::convert_and_insert(vector<char>& a_line , int rand_int , int counter)		//The function we call to add our terms
	{
		switch (rand_int)												//2 requirements: 1) more digits than operators 2) Balanced Parenthesis
				{
					case 0:								//CONVERTS OUR RANDOM INTEGERS INTO MATEMATICAL TERMS
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
						++c_left_parenthesis;
						break;
					case 15:
						a_line[counter] = ')';
						++c_right_parenthesis;
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
		////////// READING THE HIGHSCORES FOR DIFFICULTY 3 ONTO THE GAME SCREEN///////////////////////////////
		highscore_label = "Difficulty 3 Highscores: ";
			game_screen_highscore_label.set_label(highscore_label);
		
		ifstream ifs("Difficulty_3_Output.txt");
			string score;
			string initial;

			ifs >> score;
			ifs >> initial;
				string_to_outbox = "1)  " + score + '\n' + initial;
		game_screen_scores_1.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "2)  " + score + '\n' + initial;
		game_screen_scores_2.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "3)  " + score + '\n' + initial;
		game_screen_scores_3.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "4)  " + score + '\n' + initial;
		game_screen_scores_4.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "5)  " + score + '\n' + initial;
		game_screen_scores_5.set_label(string_to_outbox);
		/////////////POPULATING VECTOR AND TILES FOR THE TOP LINE/////////////////////////////////////////
		
		user_initials = box_for_initials.get_string();		//Get the string in the in_box and change the user_intials
		detach(box_for_initials);							//Detach the inbox
		
		difficulty_level = 3;
			
		a_line.resize(difficulty_level);
			generate_randomized_vector(a_line);
		
		dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
			
		attach(box_3a);		//Attach the rectangles which will contain our buttons
		attach(box_4a);
		attach(box_5a);
		attach(box_3b);
		attach(box_4b);
		attach(box_5b);
		////////// ADD THE CONTENTS OF THE A_LINE TO THE BUTTON_NUMBER_CONTENT
			button_1a_content.push_back(a_line[0]);
			button_2a_content.push_back(a_line[1]);
			button_3a_content.push_back(a_line[2]);
		///////////SET THE STRINGS IN OUR BUTTONS TO REFLECT THE RANDOMIZED TERMS
			button_1a.set_label(button_1a_content);
			button_2a.set_label(button_2a_content);
			button_3a.set_label(button_3a_content);
		////////// ATTACH OUR BUTTONS
		attach(button_1a);
		attach(button_2a);
		attach(button_3a);
		attach(button_1b);
		attach(button_2b);
		attach(button_3b);
		//ATTACH THE EVALUATE BUTTON AND DETACH THE B_ROW BUTTONS
		attach(evaluate);
		detach_b_row_buttons( difficulty_level);
	}
// - - - - - Difficulty Level 4 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_difficulty_4(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_4_function();
	}
	void Game::difficulty_4_function()
	{
		////////// READING THE HIGHSCORES FOR DIFFICULTY 4 ONTO THE GAME SCREEN///////////////////////////////
		highscore_label = "Difficulty 4 Highscores: ";
			game_screen_highscore_label.set_label(highscore_label);
		ifstream ifs("Difficulty_4_Output.txt");
			string score;
			string initial;

			ifs >> score;
			ifs >> initial;
				string_to_outbox = "1)  " + score + '\n' + initial;
		game_screen_scores_1.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "2)  " + score + '\n' + initial;
		game_screen_scores_2.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "3)  " + score + '\n' + initial;
		game_screen_scores_3.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "4)  " + score + '\n' + initial;
		game_screen_scores_4.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "5)  " + score + '\n' + initial;
		game_screen_scores_5.set_label(string_to_outbox);
		/////////////POPULATING VECTOR AND TILES FOR THE TOP LINE/////////////////////////////////////////
		
		user_initials = box_for_initials.get_string();		//Get the string in the in_box and change the user_intials
		detach(box_for_initials);							//Detach the inbox
		
		difficulty_level = 4;
		
		a_line.resize(difficulty_level);
			generate_randomized_vector(a_line);		
		dynamic_cast<Game*>(manager_instance.game_window)->detach(select_difficulty_menu);
			
		attach(box_3a);		//Attach the rectangles which will contain our buttons
		attach(box_4a);
		attach(box_5a);
		attach(box_6a);
		attach(box_3b);
		attach(box_4b);
		attach(box_5b);
		attach(box_6b);
		////////// ADD THE CONTENTS OF THE A_LINE TO THE BUTTON_NUMBER_CONTENT
			button_1a_content.push_back(a_line[0]);
			button_2a_content.push_back(a_line[1]);
			button_3a_content.push_back(a_line[2]);
			button_4a_content.push_back(a_line[3]);
		///////////SET THE STRINGS IN OUR BUTTONS TO REFLECT THE RANDOMIZED TERMS	
			button_1a.set_label(button_1a_content);
			button_2a.set_label(button_2a_content);
			button_3a.set_label(button_3a_content);
			button_4a.set_label(button_4a_content);
		////////// ATTACH OUR BUTTONS
		attach(button_1a);
		attach(button_2a);
		attach(button_3a);
		attach(button_4a);
		attach(button_1b);
		attach(button_2b);
		attach(button_3b);
		attach(button_4b);
		//ATTACH THE EVALUATE BUTTON AND DETACH THE B_ROW BUTTONS
		attach(evaluate);
		detach_b_row_buttons( difficulty_level);
	}
// - - - - - Difficulty Level 5 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_difficulty_5(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_5_function();
	}
	void Game::difficulty_5_function()
	{
		////////// READING THE HIGHSCORES FOR DIFFICULTY 5 ONTO THE GAME SCREEN///////////////////////////////
		highscore_label = "Difficulty 5 Highscores: ";
			game_screen_highscore_label.set_label(highscore_label);
		ifstream ifs("Difficulty_5_Output.txt");
			string score;
			string initial;

			ifs >> score;
			ifs >> initial;
				string_to_outbox = "1)  " + score + '\n' + initial;
		game_screen_scores_1.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "2)  " + score + '\n' + initial;
		game_screen_scores_2.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "3)  " + score + '\n' + initial;
		game_screen_scores_3.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "4)  " + score + '\n' + initial;
		game_screen_scores_4.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "5)  " + score + '\n' + initial;
		game_screen_scores_5.set_label(string_to_outbox);
		/////////////POPULATING VECTOR AND TILES FOR THE TOP LINE/////////////////////////////////////////
		
		user_initials = box_for_initials.get_string();		//Get the string in the in_box and change the user_intials
		detach(box_for_initials);							//Detach the inbox
		
		difficulty_level = 5;
		
		a_line.resize(difficulty_level);
			generate_randomized_vector(a_line);
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
		////////// ADD THE CONTENTS OF THE A_LINE TO THE BUTTON_NUMBER_CONTENT
			button_1a_content.push_back(a_line[0]);
			button_2a_content.push_back(a_line[1]);
			button_3a_content.push_back(a_line[2]);
			button_4a_content.push_back(a_line[3]);
			button_5a_content.push_back(a_line[4]);
		///////////SET THE STRINGS IN OUR BUTTONS TO REFLECT THE RANDOMIZED TERMS		
			button_1a.set_label(button_1a_content);
			button_2a.set_label(button_2a_content);
			button_3a.set_label(button_3a_content);
			button_4a.set_label(button_4a_content);
			button_5a.set_label(button_5a_content);
		////////// ATTACH OUR BUTTONS, THESE MUST BE MOVED ALSO TO BE SURE THE ORDER OF THE RANDOMIZED TERMS STAYS CORRECT
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
			
		attach(button_1b);
			button_1b.move(-100 , 0);
		attach(button_2b);
			button_2b.move(-100 , 0);
		attach(button_3b);
			button_3b.move(-100 , 0);
		attach(button_4b);
			button_4b.move(-100 , 0);
		attach(button_5b);
			button_5b.move(-100 , 0);
		//ATTACH THE EVALUATE BUTTON AND DETACH THE B_ROW BUTTONS	
		attach(evaluate);
		detach_b_row_buttons( difficulty_level);
	}
// - - - - - Difficulty Level 6 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_difficulty_6(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_6_function();
	}
	void Game::difficulty_6_function()
	{
		////////// READING THE HIGHSCORES FOR DIFFICULTY 6 ONTO THE GAME SCREEN///////////////////////////////
		highscore_label = "Difficulty 6 Highscores: ";
			game_screen_highscore_label.set_label(highscore_label);
		ifstream ifs("Difficulty_6_Output.txt");
			string score;
			string initial;

			ifs >> score;
			ifs >> initial;
				string_to_outbox = "1)  " + score + '\n' + initial;
		game_screen_scores_1.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "2)  " + score + '\n' + initial;
		game_screen_scores_2.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "3)  " + score + '\n' + initial;
		game_screen_scores_3.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "4)  " + score + '\n' + initial;
		game_screen_scores_4.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "5)  " + score + '\n' + initial;
		game_screen_scores_5.set_label(string_to_outbox);
		/////////////POPULATING VECTOR AND TILES FOR THE TOP LINE/////////////////////////////////////////
		
		user_initials = box_for_initials.get_string();		//Get the string in the in_box and change the user_intials
		detach(box_for_initials);							//Detach the inbox
		
		difficulty_level = 6;
		
		a_line.resize(difficulty_level);
			generate_randomized_vector(a_line);
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
		////////// ADD THE CONTENTS OF THE A_LINE TO THE BUTTON_NUMBER_CONTENT
			button_1a_content.push_back(a_line[0]);
			button_2a_content.push_back(a_line[1]);
			button_3a_content.push_back(a_line[2]);
			button_4a_content.push_back(a_line[3]);
			button_5a_content.push_back(a_line[4]);
			button_6a_content.push_back(a_line[5]);
		///////////SET THE STRINGS IN OUR BUTTONS TO REFLECT THE RANDOMIZED TERMS		
			button_1a.set_label(button_1a_content);
			button_2a.set_label(button_2a_content);
			button_3a.set_label(button_3a_content);
			button_4a.set_label(button_4a_content);
			button_5a.set_label(button_5a_content);
			button_6a.set_label(button_6a_content);
		////////// ATTACH OUR BUTTONS, THESE MUST BE MOVED ALSO TO BE SURE THE ORDER OF THE RANDOMIZED TERMS STAYS CORRECT
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
			
		attach(button_1b);
			button_1b.move(-100 , 0);
		attach(button_2b);
			button_2b.move(-100 , 0);
		attach(button_3b);
			button_3b.move(-100 , 0);
		attach(button_4b);
			button_4b.move(-100 , 0);
		attach(button_5b);
			button_5b.move(-100 , 0);
		attach(button_6b);
			button_6b.move(-100 , 0);
		//ATTACH THE EVALUATE BUTTON AND DETACH THE B_ROW BUTTONS		
		attach(evaluate);
		detach_b_row_buttons( difficulty_level);
	}
// - - - - - Difficulty Level 7 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::cb_difficulty_7(Address , Address pw)				//Define our callback function
	{
		reference_to<Game>(pw).difficulty_7_function();
	}
	void Game::difficulty_7_function()
	{
		////////// READING THE HIGHSCORES FOR DIFFICULTY 7 ONTO THE GAME SCREEN///////////////////////////////
		highscore_label = "Difficulty 7 Highscores: ";
			game_screen_highscore_label.set_label(highscore_label);
		ifstream ifs("Difficulty_7_Output.txt");
			string score;
			string initial;

			ifs >> score;
			ifs >> initial;
				string_to_outbox = "1)  " + score + '\n' + initial;
		game_screen_scores_1.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "2)  " + score + '\n' + initial;
		game_screen_scores_2.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "3)  " + score + '\n' + initial;
		game_screen_scores_3.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "4)  " + score + '\n' + initial;
		game_screen_scores_4.set_label(string_to_outbox);
		
			ifs >> score;
			ifs >> initial;
				string_to_outbox = "5)  " + score + '\n' + initial;
		game_screen_scores_5.set_label(string_to_outbox);
		/////////////POPULATING VECTOR AND TILES FOR THE TOP LINE/////////////////////////////////////////
	
		user_initials = box_for_initials.get_string();		//Get the string in the in_box and change the user_intials
		detach(box_for_initials);							//Detach the inbox
		
		difficulty_level = 7;
		
		a_line.resize(difficulty_level);
			generate_randomized_vector(a_line);
			
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
		////////// ADD THE CONTENTS OF THE A_LINE TO THE BUTTON_NUMBER_CONTENT
			button_1a_content.push_back(a_line[0]);
			button_2a_content.push_back(a_line[1]);
			button_3a_content.push_back(a_line[2]);
			button_4a_content.push_back(a_line[3]);
			button_5a_content.push_back(a_line[4]);
			button_6a_content.push_back(a_line[5]);
			button_7a_content.push_back(a_line[6]);
		///////////SET THE STRINGS IN OUR BUTTONS TO REFLECT THE RANDOMIZED TERMS		
			button_1a.set_label(button_1a_content);
			button_2a.set_label(button_2a_content);
			button_3a.set_label(button_3a_content);
			button_4a.set_label(button_4a_content);
			button_5a.set_label(button_5a_content);
			button_6a.set_label(button_6a_content);
			button_7a.set_label(button_7a_content);
		////////// ATTACH OUR BUTTONS, THESE MUST BE MOVED ALSO TO BE SURE THE ORDER OF THE RANDOMIZED TERMS STAYS CORRECT
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
			
		attach(button_1b);
			button_1b.move(-200 , 0);
		attach(button_2b);
			button_2b.move(-200 , 0);
		attach(button_3b);
			button_3b.move(-200 , 0);
		attach(button_4b);
			button_4b.move(-200 , 0);
		attach(button_5b);
			button_5b.move(-200 , 0);
		attach(button_6b);
			button_6b.move(-200 , 0);
		attach(button_7b);
			button_7b.move(-100 , 0);
		//ATTACH THE EVALUATE BUTTON AND DETACH THE B_ROW BUTTONS		
		attach(evaluate);
		detach_b_row_buttons( difficulty_level);
	}
	
// - - - - - Button 1a Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_1a(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_1a();
	}		
	void Game::button_fct_1a()		//PRESS THE FIRST BUTTON
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_1a.hide();		//Hide the button
		
		b_line.push_back(a_line[0]);	//Add the first element of a_line to b_line
			++b_line_counter;			//Increment this counter (used later)

		b_row_copy(b_line_counter);		//Pass that counter to this function (used later)				ALL OF THIS IS CONTINUED FOR BUTTONS 2-7
	}
// - - - - - Button 2a Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_2a(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_2a();
	}		
	void Game::button_fct_2a()		//PRESS THE SECOND BUTTON
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_2a.hide();		
		
		b_line.push_back(a_line[1]);	
			++b_line_counter;			
			
		b_row_copy(b_line_counter);		
	}
// - - - - - Button 3a Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_3a(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_3a();
	}		
	void Game::button_fct_3a()		//PRESS THE THIRD BUTTON
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_3a.hide();		
		
		b_line.push_back(a_line[2]);	
			++b_line_counter;			
		
		b_row_copy(b_line_counter);		
	}
// - - - - - Button 4a Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_4a(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_4a();
	}		
	void Game::button_fct_4a()		//PRESS THE FOURTH BUTTON
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_4a.hide();		
		
		b_line.push_back(a_line[3]);		
			++b_line_counter;				
		
		b_row_copy(b_line_counter);			
	}
// - - - - - Button 5a Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_5a(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_5a();
	}		
	void Game::button_fct_5a()		//PRESS THE FIFTH BUTTON
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_5a.hide();	
		
		b_line.push_back(a_line[4]);		
			++b_line_counter;				
		
		b_row_copy(b_line_counter);			
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
			++b_line_counter;
		
		b_row_copy(b_line_counter);
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
			++b_line_counter;
		
		b_row_copy(b_line_counter);
	}

// - - - - - Button 1b Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_1b(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_1b();
	}		
	void Game::button_fct_1b()
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_1b.hide();			//hIDE THIS BUTTON!       SAME FOR BUTTONS 2-7B
	}
// - - - - - Button 2b Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_2b(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_2b();
	}		
	void Game::button_fct_2b()
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_2b.hide();
	}
// - - - - - Button 3b Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_3b(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_3b();
	}		
	void Game::button_fct_3b()
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_3b.hide();
	}
// - - - - - Button 4b Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_4b(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_4b();
	}		
	void Game::button_fct_4b()
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_4b.hide();
	}
// - - - - - Button 5b Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_5b(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_5b();
	}		
	void Game::button_fct_5b()
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_5b.hide();
	}
// - - - - - Button 6b Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_6b(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_6b();
	}		
	void Game::button_fct_6b()
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_6b.hide();
	}
// - - - - - Button 7b Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_button_7b(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).button_fct_7b();
	}		
	void Game::button_fct_7b()
	{
		dynamic_cast<Game*>(manager_instance.game_window)->button_7b.hide();
	}
// - - - - - Evaluate Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_evaluate(Address , Address pw)	//Define our callback function
	{
		reference_to<Game>(pw).evaluate_fct();
	}

	void Game::evaluate_fct()
	{
		equation_result = calculate_equation_fct();		//calculate our b_line elements and sotre in this function
			stringstream stream;
			stream << fixed << setprecision(2) << equation_result;
			string s = stream.str();
		equation_result_string.append(s);	//add this double to our existing string
		
		if (equation_result == 0)	//Specialize output for a score of 0
		{
			equation_result_string = "That's no Good!! You got a score of 0...";
		}
		final_score.set_label(equation_result_string);	//set the label of the score out put to reflect our score
		///////ATTACH ALL THE OBJECTS ASSOCIATED WITH SCORE OUTPUT/////////
		attach(score_box);	
		attach(final_score);
		attach(move_to_highscores_button);
		dynamic_cast<Game*>(manager_instance.game_window)->evaluate.hide();		//Hide the evaluate button (this is really done to update and redraw the screen)
		remove_score_elements = true;
		
	}
// - - - - - Move to Highscores Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::cb_move_to_highscores(Address , Address pw)
	{
		reference_to<Game>(pw).show_highscores();
	}
	void Game::show_highscores()
	{
		write_to_highscores();	//call the function that will write to the highscore page
		
			manager_instance.game_window->hide();	//hide game window
			manager_instance.highscores_window->show();	//show the highscore window
			//Have to include this here because we added an if statement to avoid segfaults in the back function
				detach(evaluate);
				detach(score_box);
				detach(final_score);
				detach(move_to_highscores_button);
			
			back_button_function();	//reset everything
			manager_instance.bootup_window->hide();	//hide the bootup window
	}
// - - - - - Write to Highscores Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::write_to_highscores()		//Function used to write to the highscore sheet
	{
			fstream write_scores;	//declare our two streams
			fstream output;
		
			double score_value;	//initialize temporary values
			string initials_value;
			
			auto count = 0;		//intialize counters to 0
			auto five_lines_test = 0;
			int c;
			string trash;
			Highscore_Values value;		//create a Highscore_Values object
			
		switch(difficulty_level)		//Same process for each difficulty level the ony thing different is the file name. Only "Difficulty_3" will be commented
		{
			case(3):
			
				write_scores.open("Difficulty_3_All_scores.txt" , ios_base::app);		//open the file that stores every score to the very end
					write_scores << endl << equation_result << '\t' << user_initials;	// add the new score
				write_scores.close();	//close teh file
				
				write_scores.open("Difficulty_3_All_scores.txt");	//reopen the file from the beginning

					while (true)		// do this until eof
					{
						write_scores >> score_value;	//store the score in the score_value variable
						write_scores >> initials_value;	//store the initial in the initials_value variable
						//Set the felds of our Highscore_Values object
							value.set_score(score_value);
							value.set_initials(initials_value);
						highscores_vector.push_back(value);	//Add that object to a vector
							
						if(write_scores.eof())	//do this until end of file
							break;
					}
				write_scores.close();	//close the file
				
				sort(highscores_vector.begin(), highscores_vector.end(),greater<Highscore_Values>());	//Redefined sort function that sorts the objects by their numerical score from greatest to least
				
				write_scores.open("Difficulty_3_All_scores.txt");	//open the all score page with the now sorted vector

					while(count < highscores_vector.size())		//add the scores on the allscores page now that they are sorted
					{
						write_scores << highscores_vector[count].score << '\t' << highscores_vector[count].initials << endl;	
						++count;
					}
				write_scores.close();		//close the file
					
////////////////////READ THE TOP 5 LINES TO OUTPUT FILE//////////////////////////////////////////////////////////////////////////////
					output.open("Difficulty_3_Output.txt", fstream::out);
					write_scores.open("Difficulty_3_All_scores.txt");					
					
					while (five_lines_test < 5)
					{
						output << highscores_vector[five_lines_test].score << '\t' << highscores_vector[five_lines_test].initials << endl;
							++five_lines_test;

						write_scores >> trash >> trash;
								write_scores.seekg(1, ios_base::cur);
						c = write_scores.peek();  // peek character
							if ( c == EOF )
									break;
					}
					output.close();
					write_scores.close();
					
				break;		//THIS IS REPEATED FOR 4-7 BUT WITH DIFFERENT FILE NAMES
			case(4):
				write_scores.open("Difficulty_4_All_scores.txt" , ios_base::app);
					write_scores << endl << equation_result << '\t' << user_initials;
				write_scores.close();
				
				write_scores.open("Difficulty_4_All_scores.txt");

					while (true)	
					{
						write_scores >> score_value;
						write_scores >> initials_value;
							value.set_score(score_value);
							value.set_initials(initials_value);
						highscores_vector.push_back(value);
						
						if(write_scores.eof())
							break;
					}
				write_scores.close();
				
				sort(highscores_vector.begin(), highscores_vector.end(),greater<Highscore_Values>());
				
				write_scores.open("Difficulty_4_All_scores.txt");

					while(count < highscores_vector.size())
					{
						write_scores << highscores_vector[count].score << '\t' << highscores_vector[count].initials << endl;
						++count;
					}
				write_scores.close();	
					
////////////////////READ THE TOP 5 LINES TO OUTPUT FILE//////////////////////////////////////////////////////////////////////////////
					output.open("Difficulty_4_Output.txt", fstream::out);
					write_scores.open("Difficulty_4_All_scores.txt");					
					
					while (five_lines_test < 5)
					{
						output << highscores_vector[five_lines_test].score << '\t' << highscores_vector[five_lines_test].initials << endl;
							++five_lines_test;

						write_scores >> trash >> trash;
								write_scores.seekg(1, ios_base::cur);
						c = write_scores.peek();  // peek character
							if ( c == EOF )
									break;
					}
					output.close();
					write_scores.close();
				break;
			case(5):
				write_scores.open("Difficulty_5_All_scores.txt" , ios_base::app);
					write_scores << endl << equation_result << '\t' << user_initials;
				write_scores.close();
				
				write_scores.open("Difficulty_5_All_scores.txt");

					while (true)	
					{
						write_scores >> score_value;
						write_scores >> initials_value;
							value.set_score(score_value);
							value.set_initials(initials_value);
						highscores_vector.push_back(value);
						
						if(write_scores.eof())
							break;
					}
				write_scores.close();
				
				sort(highscores_vector.begin(), highscores_vector.end(),greater<Highscore_Values>());
				
				write_scores.open("Difficulty_5_All_scores.txt");

					while(count < highscores_vector.size())
					{
						write_scores << highscores_vector[count].score << '\t' << highscores_vector[count].initials << endl;
						++count;
					}
				write_scores.close();	
					
////////////////////READ THE TOP 5 LINES TO OUTPUT FILE//////////////////////////////////////////////////////////////////////////////
					output.open("Difficulty_5_Output.txt", fstream::out);
					write_scores.open("Difficulty_5_All_scores.txt");					
					
					while (five_lines_test < 5)
					{
						output << highscores_vector[five_lines_test].score << '\t' << highscores_vector[five_lines_test].initials << endl;
							++five_lines_test;

						write_scores >> trash >> trash;
								write_scores.seekg(1, ios_base::cur);
						c = write_scores.peek();  // peek character
							if ( c == EOF )
									break;
					}
					output.close();
					write_scores.close();
				break;
			case(6):
				write_scores.open("Difficulty_6_All_scores.txt" , ios_base::app);
					write_scores << endl << equation_result << '\t' << user_initials;
				write_scores.close();
				
				write_scores.open("Difficulty_6_All_scores.txt");

					while (true)	
					{
						write_scores >> score_value;
						write_scores >> initials_value;
							value.set_score(score_value);
							value.set_initials(initials_value);
						highscores_vector.push_back(value);
						
						if(write_scores.eof())
							break;
					}
				write_scores.close();
				
				sort(highscores_vector.begin(), highscores_vector.end(),greater<Highscore_Values>());
				
				write_scores.open("Difficulty_6_All_scores.txt");

					while(count < highscores_vector.size())
					{
						write_scores << highscores_vector[count].score << '\t' << highscores_vector[count].initials << endl;
						++count;
					}
				write_scores.close();	
					
////////////////////READ THE TOP 5 LINES TO OUTPUT FILE//////////////////////////////////////////////////////////////////////////////
					output.open("Difficulty_6_Output.txt", fstream::out);
					write_scores.open("Difficulty_6_All_scores.txt");					
					
					while (five_lines_test < 5)
					{
						output << highscores_vector[five_lines_test].score << '\t' << highscores_vector[five_lines_test].initials << endl;
							++five_lines_test;

						write_scores >> trash >> trash;
								write_scores.seekg(1, ios_base::cur);
						c = write_scores.peek();  // peek character
							if ( c == EOF )
									break;
					}
					output.close();
					write_scores.close();
				break;
			case(7):
				write_scores.open("Difficulty_7_All_scores.txt" , ios_base::app);
					write_scores << endl << equation_result << '\t' << user_initials;
				write_scores.close();
				
				write_scores.open("Difficulty_7_All_scores.txt");

					while (true)	
					{
						write_scores >> score_value;
						write_scores >> initials_value;
							value.set_score(score_value);
							value.set_initials(initials_value);
						highscores_vector.push_back(value);
						
						if(write_scores.eof())
							break;
					}
				write_scores.close();
				
				sort(highscores_vector.begin(), highscores_vector.end(),greater<Highscore_Values>());
				
				write_scores.open("Difficulty_7_All_scores.txt");

					while(count < highscores_vector.size())
					{
						write_scores << highscores_vector[count].score << '\t' << highscores_vector[count].initials << endl;
						++count;
					}
				write_scores.close();	
					
////////////////////READ THE TOP 5 LINES TO OUTPUT FILE//////////////////////////////////////////////////////////////////////////////
					output.open("Difficulty_7_Output.txt", fstream::out);
					write_scores.open("Difficulty_7_All_scores.txt");					
					
					while (five_lines_test < 5)
					{
						output << highscores_vector[five_lines_test].score << '\t' << highscores_vector[five_lines_test].initials << endl;
							++five_lines_test;

						write_scores >> trash >> trash;
								write_scores.seekg(1, ios_base::cur);
						c = write_scores.peek();  // peek character
							if ( c == EOF )
									break;
					}
					output.close();
					write_scores.close();
						
		}
	}

// - - - - - Detach b_row Buttons Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Game::detach_b_row_buttons(int difficulty_level)	//JUST A HELPER FUNCTION THAT DETACHES THE APPROPRIATE NUMBER OF B_ROW BUTTONS ACCORDING TO THE PASSED DIFFICULTY_LEVEL
	{
		switch(difficulty_level)
		{
			case (3):
				detach(button_1b);
				detach(button_2b);
				detach(button_3b);
				break;
			case (4):
				detach(button_1b);
				detach(button_2b);
				detach(button_3b);
				detach(button_4b);
				break;
			case (5):
				detach(button_1b);
				detach(button_2b);
				detach(button_3b);
				detach(button_4b);
				detach(button_5b);
				break;
			case (6):
				detach(button_1b);
				detach(button_2b);
				detach(button_3b);
				detach(button_4b);
				detach(button_5b);
				detach(button_6b);
				break;
			case (7):
				detach(button_1b);
				detach(button_2b);
				detach(button_3b);
				detach(button_4b);
				detach(button_5b);
				detach(button_6b);
				detach(button_7b);
				break;
		}
	}
// - - - - - Copy a_row into b_row Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Game::b_row_copy(int b_line_counter)	//THIS COPYS THEA_ROW ELEMENTS INTO THE B_ROW ELEMENTS INT HE PROPER ORDER
	{
		switch(b_line_counter)
		{
			case (0):
				button_1b_content.push_back(b_line[b_line_counter]);
				button_1b.set_label(button_1b_content);
				attach(button_1b);
				break;
			case (1):
				button_2b_content.push_back(b_line[b_line_counter]);
				button_2b.set_label(button_2b_content);
				attach(button_2b);
				break;
			case (2):
				button_3b_content.push_back(b_line[b_line_counter]);
				button_3b.set_label(button_3b_content);
				attach(button_3b);
				break;
			case (3):
				button_4b_content.push_back(b_line[b_line_counter]);
				button_4b.set_label(button_4b_content);
				attach(button_4b);
				break;
			case (4):
				button_5b_content.push_back(b_line[b_line_counter]);
				button_5b.set_label(button_5b_content);
				attach(button_5b);
				break;
			case (5):
				button_6b_content.push_back(b_line[b_line_counter]);
				button_6b.set_label(button_6b_content);
				attach(button_6b);
				break;
			case (6):
				button_7b_content.push_back(b_line[b_line_counter]);
				button_7b.set_label(button_7b_content);
				attach(button_7b);
				break;
		}
	}
	
// - - - - - Functions associated with the calculator - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    } 

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/': 
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
   case '+': case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
       error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
	break;
        case '/':
            {    
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) 
    {    
        switch(t.kind) 
	{
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

// - - - - - Calculator Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
double Game::calculate_equation_fct()
{
	try
	{
		stringstream st(string(b_line.begin(), b_line.end()));
		
		 cout<<st.str()<<endl;
		 
		st.seekp(0, std::ios::end);
		st << '=';
		
		streambuf *backup = cin.rdbuf(); // back up cin's streambuf
		streambuf *b_line = st.rdbuf(); // get file's streambuf
		cin.rdbuf(b_line); // assign streambuf to cin
		
	
			double val;
		while (cin) {
			Token t = ts.get();

			if (t.kind == 'x') break; // 'x' for quit
			if (t.kind == '=')        // '=' for "print now"
			{
				cout << "=" << val << '\n';
				return val;
			}
			else
				ts.putback(t);
			val = expression();
		}
			keep_window_open();
			
	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << '\n'; 
		keep_window_open();
		return 0;
	}
	catch (...) 
	{
		cerr << "Oops: unknown exception!\n"; 
		keep_window_open();
		return 0;
	}
	
	
}
//------------------------------------------------------------------------