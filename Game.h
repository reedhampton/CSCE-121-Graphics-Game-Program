#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "GUI.h"

using namespace Graph_lib;

class Highscore_Values
{
	public:
		string initials;
		double score;
	public:
		Highscore_Values();	
		void set_initials(string);
		void set_score(double);
		bool operator > (const Highscore_Values& str) const
		{
			return (score > str.score);
		}
};


class Game : public Graph_lib::Window	//Extend Bootup from Graph_lib::Window
{
	private:
		int rectangle_w_h;
		int difficulty_level;						// 3 - 7
		int c_digits;
		int c_operands;
		int c_left_parenthesis;
		int c_right_parenthesis;
		
		string user_initials;
		
		vector <char> a_line;
		vector <char> b_line;
		
		string button_1a_content;
		string button_2a_content;
		string button_3a_content;
		string button_4a_content;
		string button_5a_content;
		string button_6a_content;
		string button_7a_content;
		
		string button_1b_content;
		string button_2b_content;
		string button_3b_content;
		string button_4b_content;
		string button_5b_content;
		string button_6b_content;
		string button_7b_content;
		
		string final_score_text;
		
		int b_line_counter;
		
		stringstream st;
		
		vector<Highscore_Values> highscores_vector;
		
		string equation_result_string;
		
		void generate_randomized_vector(vector<char>&);		//0-16 as int values, each representing a character
		void convert_and_insert(vector<char>& , int , int);
	
		Button back_button;											// Declare our button
		Button menu_button;
			Menu select_difficulty_menu;
				Button* difficulty_3_button;
				Button* difficulty_4_button;
				Button* difficulty_5_button;
				Button* difficulty_6_button;
				Button* difficulty_7_button;	

		Out_box game_screen_outbox;
				string string_to_outbox;
	//Rectangle containers for the top row
		Rectangle box_1a;
		Rectangle box_2a;
		Rectangle box_3a;
		Rectangle box_4a;
		Rectangle box_5a;
		Rectangle box_6a;
		Rectangle box_7a;
		
	//Rectangle containers for the bottom row
		Rectangle box_1b;
		Rectangle box_2b;
		Rectangle box_3b;
		Rectangle box_4b;
		Rectangle box_5b;
		Rectangle box_6b;
		Rectangle box_7b;
	//Buttons to fill the top row	
		Nonconst_Button button_1a;	
		Nonconst_Button button_2a;
		Nonconst_Button button_3a;
		Nonconst_Button button_4a;
		Nonconst_Button button_5a;
		Nonconst_Button button_6a;
		Nonconst_Button button_7a;
	//Buttons to fill the bottom row	
		Nonconst_Button button_1b;					
		Nonconst_Button button_2b;
		Nonconst_Button button_3b;
		Nonconst_Button button_4b;
		Nonconst_Button button_5b;
		Nonconst_Button button_6b;
		Nonconst_Button button_7b;
		
		Button evaluate;
		
		Rectangle score_box;
		Nonconst_Text final_score;
		Button move_to_highscores_button;
		
			static void cb_move_to_highscores(Address , Address);
			void show_highscores();
		
		void write_to_highscores();
		
	public:
		Game(Point p , int w , int h , const string& name);		//Declare our constructor
		
		static void cb_back(Address , Address);						//Declare our callback function
		void back_button_function();
		
		static void cb_menu_pressed(Address , Address);		//Declare our callback function
		void menu_pressed();
		
		static void cb_difficulty_3(Address , Address);		//Declare our callback function
		void difficulty_3_function();
		
		static void cb_difficulty_4(Address , Address);		//Declare our callback function
		void difficulty_4_function();
		
		static void cb_difficulty_5(Address , Address);		//Declare our callback function
		void difficulty_5_function();
		
		static void cb_difficulty_6(Address , Address);		//Declare our callback function
		void difficulty_6_function();
		
		static void cb_difficulty_7(Address , Address);		//Declare our callback function
		void difficulty_7_function();
		
		
		static void cb_button_1a(Address , Address);	//Declare our callback function
		void button_fct_1a();
		
		static void cb_button_2a(Address , Address);	//Declare our callback function
		void button_fct_2a();
		
		static void cb_button_3a(Address , Address);	//Declare our callback function
		void button_fct_3a();
		
		static void cb_button_4a(Address , Address);	//Declare our callback function
		void button_fct_4a();
		
		static void cb_button_5a(Address , Address);	//Declare our callback function
		void button_fct_5a();
		
		static void cb_button_6a(Address , Address);	//Declare our callback function
		void button_fct_6a();
		
		static void cb_button_7a(Address , Address);	//Declare our callback function
		void button_fct_7a();
		
		//BOTTOM ROW BUTTONS FUNCTIONS AND CALLBACKS
			static void cb_button_1b(Address , Address);	//Declare our callback function
			void button_fct_1b();
			
			static void cb_button_2b(Address , Address);	//Declare our callback function
			void button_fct_2b();
			
			static void cb_button_3b(Address , Address);	//Declare our callback function
			void button_fct_3b();
			
			static void cb_button_4b(Address , Address);	//Declare our callback function
			void button_fct_4b();
			
			static void cb_button_5b(Address , Address);	//Declare our callback function
			void button_fct_5b();
			
			static void cb_button_6b(Address , Address);	//Declare our callback function
			void button_fct_6b();
			
			static void cb_button_7b(Address , Address);	//Declare our callback function
			void button_fct_7b();
			
		static void cb_evaluate(Address , Address);
		void evaluate_fct();
		
		double calculate_equation_fct();
		
		
		void detach_b_row_buttons(int);
		void b_row_copy(int);
		
		double equation_result;
};

//				 Define Class Token for the calculator

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//				Define class Token_stream for the calculator

class Token_stream
{
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};
#endif