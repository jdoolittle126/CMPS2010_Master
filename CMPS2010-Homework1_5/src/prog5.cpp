////////////////////////////////////////////////////////////////////////////////
// CMPS 2010
// Professor Toothman
// Jonathan Doolittle
// 9/5/2019
// 
// Homework 1
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <stdio.h>
#include <limits>

using namespace std;

int sizes[4];

void clear_buffer(){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void add_value(int pos, string text){
	cout << "Enter the number of " << text << endl;

	while(true){
		if(cin >> sizes[pos]){
			cout << endl;
			clear_buffer();
			return;
		} else {
			std::cout << "Not a valid value! Try again!: " << endl;
			clear_buffer();
		}
	}
}

int main(){
	add_value(0, "ints");
	add_value(1, "chars");
	add_value(2, "floats");
	add_value(3, "doubles");
	int size = (sizeof(int)*sizes[0]) + (sizeof(char)*sizes[1]) + (sizeof(float)*sizes[2]) + (sizeof(double)*sizes[3]);
	printf("Total Memory: %i bytes, or %f kilobytes", size, size/1024.0f);
	return 0;
}



