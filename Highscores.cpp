#include "Highscores.h"
#include "Window_Manager.h"

//Go and find our instance of Manager_Window
extern Window_Manager manager_instance;

// - - - - - Constructor - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
Highscores::Highscores(Point p , int w , int h , const string& name)		//Define our constructor
: Graph_lib::Window(p, w, h, name),
  back_button{Point {10, 10} , 50 , 30, "Back" , cb_back} ,  //define the buttons we want to attach
  //hs_menu_button{Point {100, 100} , 175 , 30, "Select the Difficulty Level" , cb_menu_pressed} ,
  //hs_difficulty_menu{Point {50, 100} , 65 , 30, Menu::vertical , "Select The Difficulty Level"} , 
  show_scores{Point{350,100} , 700 , 600 , "" } ,
  select_diff{Point {70,70} , "Select difficulty of highscores to view"} ,
  box_title{Point{630,75} , "Highscores"} ,
  ////////////////MENU BUTTONS TO ATTACH//////////////////////////////////
  difficulty_3_highscores{Point {100, 100} , 150 , 50, "3" , cb_difficulty_3} , 
  difficulty_4_highscores{Point {100, 150} , 150 , 50, "4" , cb_difficulty_4} ,
  difficulty_5_highscores{Point {100, 200} , 150 , 50, "5" , cb_difficulty_5} ,
  difficulty_6_highscores{Point {100, 250} , 150 , 50, "6" , cb_difficulty_6} ,
  difficulty_7_highscores{Point {100, 300} , 150 , 50, "7" , cb_difficulty_7} 
{
	attach(back_button);											//Attach the button
	//attach(hs_menu_button);	//Attach the hs_menu_button button
	attach(select_diff);
	attach(box_title);
	attach(difficulty_3_highscores);	//Attach buttons to the menu
	attach(difficulty_4_highscores);
	attach(difficulty_5_highscores);
	attach(difficulty_6_highscores);
	attach(difficulty_7_highscores);
	//attach(hs_difficulty_menu);
	attach(show_scores);
	//dynamic_cast<Highscores*>(manager_instance.highscores_window)->detach(hs_difficulty_menu);	//then hide the menu right away
}
// - - - - - Back Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Highscores::cb_back(Address, Address pw)							//Define our call back function
	{
		reference_to<Highscores>(pw).back_button_function();
	}
	
	void Highscores::back_button_function()
	{
		//dynamic_cast<Highscores*>(manager_instance.highscores_window)->hs_menu_button.show();
		manager_instance.highscores_window->hide();							
		manager_instance.bootup_window->show();							// Run hide() on the member (bootup_window) of manager_instance		
	}


// - - - - - Difficulty Level 3 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Highscores::cb_difficulty_3(Address , Address pw)				//Define our callback function
	{
		reference_to<Highscores>(pw).highscores_3_function();
	}
	
	void Highscores::highscores_3_function()
	{
		difficulty_level = 3;
		
		
		//Print Highscores of difficulty 3
		
		
	}

// - - - - - Difficulty Level 4 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Highscores::cb_difficulty_4(Address , Address pw)				//Define our callback function
	{
		reference_to<Highscores>(pw).highscores_4_function();
	}	
	
	void Highscores::highscores_4_function()
	{
		difficulty_level = 4;
		
		
		//Print Highscores of difficulty 4
		
	}
	
// - - - - - Difficulty Level 5 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Highscores::cb_difficulty_5(Address , Address pw)				//Define our callback function
	{
		reference_to<Highscores>(pw).highscores_5_function();
	}	
	
	void Highscores::highscores_5_function()
	{
		difficulty_level = 5;
		
		
		//Print Highscores of difficulty 5
		
	}
	
// - - - - - Difficulty Level 6 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Highscores::cb_difficulty_6(Address , Address pw)				//Define our callback function
	{
		reference_to<Highscores>(pw).highscores_6_function();
	}	
	
	void Highscores::highscores_6_function()
	{
		difficulty_level = 6;
		
		
		//Print Highscores of difficulty 6
		
	}
	
// - - - - - Difficulty Level 7 Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //	
	void Highscores::cb_difficulty_7(Address , Address pw)				//Define our callback function
	{
		reference_to<Highscores>(pw).highscores_7_function();
	}	
	
	void Highscores::highscores_7_function()
	{
		difficulty_level = 7;
		
		
		//Print Highscores of difficulty 7
		
	}
	
	
	
	
	