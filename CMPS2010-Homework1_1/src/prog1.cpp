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
using namespace std;

int carl = 50, barry = 100, total;

int main(){
	total = carl + barry;
	cout << "This program stores two variables and adds them together in a variable named total!" << endl
			<< "I hope you enjoy this program! Here is variable one, I named it carl: " + to_string(carl) << endl
			<< "This is the second variable. I named this one barry: " + to_string(barry) << endl
			<< "This is the sum of carl and barry: " + to_string(total) << endl;
	return 0;
}



