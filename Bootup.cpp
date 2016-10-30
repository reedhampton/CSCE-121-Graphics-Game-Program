#include "Project_Menu.h"

class Bootup : Project_Menu		//Define the class for our first menu
{
	private:
		string windowname = "Bootup Menu";		//store the name of this window as a private data field
	protected:
		string get_windowname();	// Declare a public function to acces the private data fields
		void attach_Bootup_buttons();
		
		//CALLBACK FUNCTIONS		
		static void cb_quit(Address , Address);	//Callback for closing the window	
		static void cb_tutorial(Address , Address);	//Callback for switching to the tutorial window
	public:
		Bootup();	//Declare a constructor
		
		//BUTTONS		
			Button tutorial_button {Point {350,260} , 75 , 50 , "Tutorial", cb_tutorial};	//create a button
			Button exit_button {Point {350,200} , 75 , 50 , "Exit", cb_quit};	//create a button
};

//- - CONSTRUCTOR- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//
Bootup::Bootup()	
{
	string menu_name =  get_windowname();	//Retrieves the private data field and stores it in this string
	Project_Menu::return_window(menu_name);	//Calls the function from menu, this creates the POINTER that holds the ADDRESS to our WINDOW

	attach_Bootup_buttons();

	gui_main();	//draw everything
}
//- - GET WINDOW NAME FUNCTION - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//
	string Bootup::get_windowname()	//retrieve the private datafield of the window name
	{
		return windowname;
	}
//- - -ATTACH/DETACH FUCNTIONS- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//
void Bootup::attach_Bootup_buttons()
{
	pointer_to_window -> attach(exit_button);	//Dereferance using structural dereferance and attach our button
	pointer_to_window -> attach(tutorial_button);	//Dereferance using structural dereferance and attach our button
}
//- - - CALLBACK/BOOTUP FUNCTIONS FOR EXIT BUTTON- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//
	void Bootup::cb_quit( Address , Address pw)	//Callback for button "quit" allows us to call our function
	{
		reference_to<Project_Menu>(pw).quit();
	}
//- - - CALLBACK/BOOTUP FUNCTIONS FOR TUTORIAL BUTTON - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//
	void Bootup::cb_tutorial( Address , Address pw)	//Callback for button "quit" allows us to call our function
	{
		reference_to<Project_Menu>(pw).tutorial();
	}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



int main()		//TEST FOR A MAIN FUNCTION
{
	Bootup test;
}

