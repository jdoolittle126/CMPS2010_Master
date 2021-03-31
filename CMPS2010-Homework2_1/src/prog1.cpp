/*
 * Jonathan Doolittle
 * CMPS 2010
 * Professor Toothman
 * Homework #2
 *
 * This program displays the nth Fibonacci number
 */

#include <iostream>

int get_nth_fibonacci(int n){
	if(n <= 1) return n;
	return get_nth_fibonacci(n-1)+get_nth_fibonacci(n-2);
}

void display_menu(){
	int n = -1;
	while(!(n >= 0 && n <= 40)) {
		std::cout << "Enter n (0-40): ";
		std::cin >> n;
	}
	std::cout << "F(" << n << "): " << get_nth_fibonacci(n);

}

int main(){
	display_menu();
	return 0;
}
