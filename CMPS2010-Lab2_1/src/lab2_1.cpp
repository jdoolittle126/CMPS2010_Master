/*
 * Jonathan Doolittle
 * CMPS 2010
 * Professor Toothman
 * 9/5/2019
 *
 * Content of Lab 2 split into functions
 *
 */

#include <iostream>
#include <limits>
#include <string>

using namespace std;

int user_input_int;
float user_input_float;

void clear_buffer(){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void program_base(){
	cout << "Please input an Integer: " << endl;
	while(true){
		if(cin >> user_input_int){
			cout << endl;
			clear_buffer();
			break;
		} else {
			std::cout << "Not a valid integer! Please enter a valid integer: " << endl;
			clear_buffer();
		}
	}

	cout << "Thank you! Now please input a float: " << endl;
	while(true){
		if(cin >> user_input_float){
			cout << endl;
			clear_buffer();
			break;
		} else {
			std::cout << "Not a valid float! Please enter a valid float: " << endl;
			clear_buffer();
		}
	}
}

/* program1()
 * Write a program that asks the user to enter an integer and then a float.
 * Read what the user types into variables, then echo the contents of the variables to the screen.
 * Finally, calculate the sum of the two numbers and print the results to the screen
 */

void program1(){
	program_base();
	cout << "You have entered " + to_string(user_input_int) + " as an integer and " + to_string(user_input_float) + " as a float!" << endl;
	cout << "int + float = " + to_string(user_input_int + user_input_float) +
			"\nint - float = " + to_string(user_input_int - user_input_float) +
			"\nint / float = " + to_string(user_input_int / user_input_float) +
			"\nint * float = " + to_string(user_input_int * user_input_float) + "\n" << endl;
}

/*
 * Run the program a few times (repeat the ./lab2_1 command) and experiment with giving
 * different input such as entering a float instead of an integer for prompt 1 and an integer
 * instead of a float for prompt 2. Also try entering both numbers at once with just a space
 * between them instead of hitting enter after each number.
 */

void program2(){
	program_base();
	cout << "\n" + to_string((user_input_int<user_input_float)?user_input_float:user_input_int) + " is larger or of equal value" << endl;
}

int main(){
	program1();
	return 0;
}



