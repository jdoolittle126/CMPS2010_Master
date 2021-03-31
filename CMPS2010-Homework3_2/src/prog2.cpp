/*
 * Jonathan Doolittle
 * CMPS 2010
 * Professor Toothman
 * Homework #3
 *
 * Mimics the 'cat' command function
 */

#include <iostream>
#include <fstream>

int main(int argc, char ** argv) {
	std::ifstream fs;
	fs.open(argv[1]);
	if(fs) {

		char c;
		while (fs.get(c)) {
			std::cout << c;
		}
	} else {
		std::cout << "File not found!";
	}

    return 0;
}
