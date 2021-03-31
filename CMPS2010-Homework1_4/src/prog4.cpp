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

const int len = 5;
float values[len];

void clear_buffer(){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main(){
	int a = 0;
		cout << "You will enter 5 values, press enter between each: " << endl;
		while(true){
			if(cin >> values[a]){
				a++;
				cout << endl;
				clear_buffer();
				if(a == len){
					cout << "Good work!" << endl;
					break;
				} else {
					cout << to_string(len-a) + " more to go!" << endl;
				}
			} else {
				std::cout << "Not a valid value! Try again!: " << endl;
				clear_buffer();
			}
		}
	float total = 0;
	for(float v : values){
		total+=v;
	}
	cout << "The average of your values is " + to_string(total/len) << endl;

	return 0;
}



