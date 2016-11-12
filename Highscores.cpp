#include "Highscores.h"
#include "Window_Manager.h"

//Go and find our instance of Manager_Window
extern Window_Manager manager_instance;

// - - - - - Constructor - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
Highscores::Highscores(Point p , int w , int h , const string& name)		//Define our constructor
: Graph_lib::Window(p, w, h, name),
  back_button{Point {10, 10} , 50 , 30, "Back" , cb_back} 			//define the buttons we want to attach
{
	attach(back_button);											//Attach the button
}
// - - - - - Back Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
	void Highscores::cb_back(Address, Address pw)							//Define our call back function
	{
		reference_to<Highscores>(pw).back_button_function();
	}
	
	void Highscores::back_button_function()
	{
		manager_instance.highscores_window->hide();							
		manager_instance.bootup_window->show();							// Run hide() on the member (bootup_window) of manager_instance		
	}
// - - - - - Tutorial Button Callback and Function - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

