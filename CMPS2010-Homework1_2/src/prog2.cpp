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

float value;
using namespace std;

int main(){
	printf("%s \n", "Enter a float: ");
	cin >> value;
	printf("%s $%.2f %s $%.2f", "Sales tax of", value, "is", value*0.0725f);
	return 0;
}


