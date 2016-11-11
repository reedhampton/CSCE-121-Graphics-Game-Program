#include "Window_Manager.h"
#include "Bootup.h"
#include "Tutorial.h"
#include "Game.h"
//#include "Highscores.h"


//Define our constructor (creates our windows that we will be manipulating)
	Window_Manager::Window_Manager()	//Initialization list
		: origin{0, 0},
		  window_xmax(1200),
		  window_ymax(800),
		  bootup_window(new Bootup(origin , window_xmax , window_ymax , "Bootup Window")),
		  game_window(new Game(origin , window_xmax , window_ymax , "Game Window")),
		  tutorial_window(new Tutorial(origin , window_xmax , window_ymax , "Tutorial Window")),
		  highscores_window(new Bootup(origin , window_xmax , window_ymax , "Highscores Window"))
{
	tutorial_window->hide();	//hide everything but our bootup window
	highscores_window->hide();
	game_window->hide();
}

//define our destructor that deletes all the window pointers once we leave scope
	Window_Manager::~Window_Manager()
	{
		delete bootup_window;
		delete tutorial_window;
		delete highscores_window;
		delete game_window;
	}
