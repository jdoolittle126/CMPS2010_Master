/*
 * Jonathan Doolittle
 * CMPS 2010
 * Professor Toothman
 * 9/19/2019
 *
 *
 */

#include <sstream>
#include <iostream>
#include <iomanip>

const int TABLE_MAX = 16;

void print_tables(){
	for(int i = 1; i <= TABLE_MAX; i++){
		for(int j = 1; j <= TABLE_MAX; j++){
			std::cout << std::setw(6) << i*j;
		}
        std::cout << std::endl;
	}

}

int main(){
	print_tables();
	return 0;

}

