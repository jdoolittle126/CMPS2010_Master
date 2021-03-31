/*
 * Jonathan Doolittle
 * CMPS 2010
 * Professor Toothman
 * Homework #2
 *
 * Displays a sorted sheet of doubles by sum of each row using merge sort
 */


///////////////////////////////////
//////////// INCLUDES /////////////
///////////////////////////////////

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <iomanip>

///////////////////////////////////
//////////// DEFINES //////////////
///////////////////////////////////

//Size of spreadsheet
#define ROW 5
#define COL 4

//File to be read
#define FILE "/home/fac/nick/public/2010/hw6_prog2_input"

//Formatting for table
#define FORMAT_WIDTH 10

//Defines for sorting techniques (max: greatest to least size, min: least to greatest)
#define SORT_PREF_MAX 100000
#define SORT_PREF_MIN 100001

//Defines for errors
#define ERROR_SORT_PREF "INVALID SORT PREFERENCE!"

///////////////////////////////////
///////////// VARIABLES ///////////
///////////////////////////////////

//The sheet to be sorted
double spreadsheet[ROW][COL];

///////////////////////////////////
///////////// SORTING FUNCTIONS ///
///////////////////////////////////

void log_error(std::string error) {
	std::cout << error << "\n";
	exit(EXIT_FAILURE);
}

double sum_of_row(double array[ROW][COL], int row) {
	double sum = 0;
	for(int i = 0; i < COL; i++) {
		sum += array[row][i];
	}
	return sum;
}

void copy_row(double A[ROW][COL], double B[ROW][COL], int row_a, int row_b) {
	for(int i = 0; i < COL; i++) {
		A[row_a][i] = B[row_b][i];
	}
}

void populate_array(double array[ROW][COL], std::string file_path) {
	std::ifstream f;
	f.open(file_path);
	if(f) {
		for(int r = 0; r < ROW; r++){
			for(int c = 0; c < COL; c++) {
				f >> array[r][c];
			}
		}
		f.close();
	} else {
		std::cout << "File not found!\n";
	}
}

void split_array(double A[ROW][COL], int index_root, int index_last, int sort_pref) {
	//Make a copy
	double B[ROW][COL];
	std::copy(&A[0][0], &A[0][0]+ROW*COL,&B[0][0]);

	//Keep going until the nodes are broken down into the smallest size
	if(index_last - index_root > 1) {
		//Keep splitting left and right arrays
		int index_middle = (index_root + index_last) / 2;
		split_array(B, index_root, index_middle, sort_pref);
		split_array(B, index_middle, index_last, sort_pref);

		int r = index_root;
		int m = index_middle;
		bool p;

		//Choose sort pref
		switch(sort_pref) {
			case SORT_PREF_MAX: {
				p = false;
				break;
			}
			case SORT_PREF_MIN: {
				p = true;
				break;
			}
			default: log_error(ERROR_SORT_PREF);
		}

		//Merge nodes together after they are all broken down
		//This sorts them one section at a time
		for(int i = index_root; i < index_last; i++) {
			//Make sure you are within range and that the two slots you are comparing match the sort preference
			if(r < index_middle && (m >= index_last || (sum_of_row(B, r) <= sum_of_row(B, m)) == p)){
				copy_row(A, B, i, r);
				r++;
			} else {
				copy_row(A, B, i, m);
				m++;
			}
		}
	}

}

void sort_array(double array[ROW][COL], int sort_pref) {
	split_array(array, 0, ROW, sort_pref);
}

///////////////////////////////////
///////////// PRINTING ////////////
///////////////////////////////////

void print_array_formatted(double array[ROW][COL]) {
	char l = 'A';
	std::cout << std::left << std::setw(FORMAT_WIDTH) << std::setfill(' ') << "";
	for(int i = 0; i < COL; i++) {
		std::cout << std::left << std::setw(FORMAT_WIDTH) << std::setfill(' ') << l++;
	}
	std::cout << std::left << std::setw(FORMAT_WIDTH) << std::setfill(' ') << "SUM";
	std::cout << "\n";

	for(int r = 0; r < ROW; r++){
		std::cout << std::left << std::setw(FORMAT_WIDTH) << std::setfill(' ') << r+1;
		for(int c = 0; c < COL; c++) {
			std::cout << std::left << std::setw(FORMAT_WIDTH) << std::setfill(' ') << array[r][c];
		}
		std::cout << std::left << std::setw(FORMAT_WIDTH) << std::setfill(' ') << sum_of_row(array, r) << "\n";

	}
	std::cout << "\n";
}

///////////////////////////////////
///////////// MAIN ////////////////
///////////////////////////////////

int main() {
	//Load array from FILE
	populate_array(spreadsheet, FILE);
	std::cout << "Unmodified Array:\n";
	print_array_formatted(spreadsheet);

	/*
	PREFERENCES:
	SORT_PREF_MAX							- From greatest to least
	SORT_PREF_MIN							- From least to greatest
	*/

	//sort_array(array, preference)

	// DEMO
	std::cout << "Greatest to Least Array:\n";
	sort_array(spreadsheet, SORT_PREF_MAX);
	print_array_formatted(spreadsheet);

	std::cout << "Least to Greatest Array:\n";
	sort_array(spreadsheet, SORT_PREF_MIN);
	print_array_formatted(spreadsheet);

	return EXIT_SUCCESS;
}


