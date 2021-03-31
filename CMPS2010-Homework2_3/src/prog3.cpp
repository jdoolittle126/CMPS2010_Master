/*
 * Jonathan Doolittle
 * CMPS 2010
 * Professor Toothman
 * Homework #2
 *
 * This program displays a menu with various functions, further detailed in the code and prompts
 */

#include <iostream>
#include <fstream>
#define FILE "/home/fac/nick/public/2010/hw2_prog3_list.txt"

bool running = true;

// --- MULTIPLY TWO INTS -- //
void menu_1(){
	int n1, n2;
	std::cout << "You selected Menu Option 1\nThis program will multiply two integers!\nEnter Integer 1: ";
	std::cin >> n1;
	std::cout << "\nEnter Integer 2: ";
	std::cin >> n2;
	std::cout << "\nThe result of your inputs is: " << n1*n2 << "\n";
}

// --- DIVIDE TWO INTS -- //
void menu_2(){
	int n1, n2;
	std::cout << "You selected Menu Option 2\nThis program will divide two integers in the format (int 1 / int 2)!\nEnter Integer 1: ";
	std::cin >> n1;
	std::cout << "\nEnter Integer 2: ";
	std::cin >> n2;
	std::cout << "\nThe result of your inputs is: " << static_cast<float>(n1)/n2 << "\n";
}

// --- CHECK IN RANGE -- //
void menu_3(){
	int n1;
	std::cout << "You selected Menu Option 3\nThis program will check if your input is between 10 and 20!\nEnter an Integer: ";
	std::cin >> n1;
	std::cout << "\nYour input is ";
	if(!(n1 <= 20 && n1 >= 10)) std::cout << "not ";
	std::cout << "between 10 and 20!\n";
}

// --- LARGEST IN FILE -- //
void menu_4(){
	std::cout << "You selected Menu Option 4\nThis program will file the largest int in " << FILE << "\n";
	std::ifstream f;
	f.open(FILE);
	if (f) {
		int cur, max;
		f >> max;
		while (f >> cur) {
			if(cur > max) max = cur;
		}
		std::cout << max << "\n";
		f.close();
	} else {
		std::cout << "File not found!\n";
	}
}

// --- SHOW THE MENU IN LOOP --- //
void display_menu(){
	while(running){
		int input;
		std::cout << "Welcome to the CMPS 2010 HW 2 Menu\n==================================\n1.  Multiply two integers\n2.  Divide two integers\n" <<
					"3.  Check if a number is within the range 10-20\n4.  Find the largest integer in a file\n\n0.  Exit\n==================================\nEnter selection:  ";
		std::cin >> input;
		switch(input){
			case 0: running = false; break;
			case 1: menu_1(); break;
			case 2: menu_2(); break;
			case 3: menu_3(); break;
			case 4: menu_4(); break;
			default: std::cout << "\nInvalid Input! Try again!\n"; break;
		}
	}
}

int main(){
	display_menu();
	return 0;
}
