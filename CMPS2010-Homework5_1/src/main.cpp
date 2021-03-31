////////////////////////////////////////////////////////////////////////////////
// CMPS 2010
// Professor Toothman
// Jonathan Doolittle
// 12/5/2019
//
// Homework 5 (main.cpp)
////////////////////////////////////////////////////////////////////////////////

#include "CustomArray.h"

int main() {

	std::cout << "Creating 3 CustomArrays, like so:\n\tCustomArray<double> test1;\n\tCustomArray<float> test2(15);\n\tCustomArray<int> test3(5);\n\n";

	CustomArray<double> test1;
	CustomArray<float> test2(15);
	CustomArray<int> test3(5);

	std::cout << "Adding and printing out contents of 3 CustomArrays, in order:\n\n";

	for(int i = 0; i < 20; i++) {
		test2[i] = i; //Does NOT force resize
		test3.add(i); //Does force resize
		std::cout << test1[i] << " " << test2[i] << " " << test3[i] << "\n"; //Empty CustomArray prints out default value

	}

	std::cout << "Using .add(44) on test3, and .resize(40) on test2\n\n";

	test3.add(44);
	test2.resize(40);

	std::cout << "Printing out the new test2 array\n\n";

	for(int i = 0; i < 40; i++) {
		std::cout << test2[i] << std::endl; //Only values inside of original size preserved during resize

	}

	std::cout << "Creating CustomArray test4 like so: \n\tCustomArray<int> test4(test3);\n\n";

	CustomArray<int> test4(test3);

	std::cout << "Printing out the new test4 array\n\n";

	for(int i = 0; i < 21; i++) {
		std::cout << test4[i] << "\n"; //Copies over data

	}

	return 0;
}
