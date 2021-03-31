/*
 * Jonathan Doolittle
 * CMPS 2010
 * Professor Toothman
 * Homework #1
 *
 * Displays the array of strings in sorted order using heap sort
 */

///////////////////////////////////
//////////// INCLUDES /////////////
///////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

///////////////////////////////////
//////////// DEFINES //////////////
///////////////////////////////////

//Size of array
#define NUM_NAMES 20

//Defines for sorting techniques (max: greatest to least size, a-z, min: least to greatest, z-a)
#define SORT_PREF_MAX 100000
#define SORT_PREF_MIN 100001
#define SORT_TYPE_LEXICOGRAPHICAL_LASTNAME 100010
#define SORT_TYPE_LEXICOGRAPHICAL_FIRSTNAME 100011
#define SORT_TYPE_LEXICOGRAPHICAL_MIDDLENAME 100012
#define SORT_TYPE_LENGTH_LASTNAME 100013
#define SORT_TYPE_LENGTH_FIRSTNAME 100014
#define SORT_TYPE_LENGTH_MIDDLENAME 100015

//Defines for errors
#define ERROR_SORT_TYPE "INVALID SORT TYPE!"
#define ERROR_SORT_PREF "INVALID SORT PREFERENCE!"

///////////////////////////////////
///////////// CONSTANTS ///////////
///////////////////////////////////

//Delimiter for names (If no delimiter exists, string is assumed to be a first name)
const std::string DEL_LAST_FIRST = ",";
const std::string DEL_FIRST_MIDDLE = " ";
const int FORMAT_WIDTH = 25;

//Name array, in format (last, first)
const std::string NAMES[NUM_NAMES] = {"Cooper, Dale", "Truman, Harry", "Martel, Pete",
        "Hurley, James", "Hayward, Donna", "Palmer, Laura", "Gerard, Philip",
        "Horne, Benjamin", "Jones, Dougie", "Briggs, Garland", "Hill, Hawk",
        "Jennings, Norma",  "Horne, Audrey", "Wheeler, John Justice",
        "Moran, Lucy", "Brennan, Andy", "Tremayne, Dick", "BOB", "MIKE", "Judy"
};


///////////////////////////////////
///////////// SORTING FUNCTIONS ///
///////////////////////////////////

void log_error(std::string error) {
	std::cout << error << "\n";
	exit(EXIT_FAILURE);
}

void element_swap(std::string &a, std::string &b) {
	std::string c = a;
	a = b;
	b = c;
}

std::string get_section_by_del(std::string a, std::string del, unsigned int index){
	unsigned int i = 0;
	while(a.find(del) != std::string::npos) {
		if(i == index) return a.substr(0, a.find(del));
	    a.erase(0, a.find(del) + del.length());
	    i++;
	}
	return a;
}

std::string clean_segment(std::string a, std::string discard) {
	return a.substr(a.find_first_not_of(discard), (1 + a.find_last_not_of(discard) - a.find_first_not_of(discard)));
}

std::string clean_string(std::string a) {
	return clean_segment(clean_segment(a, DEL_LAST_FIRST), DEL_FIRST_MIDDLE);
}

std::string get_name_first(std::string a) {
	if(a.find(DEL_LAST_FIRST) == std::string::npos) {
		return clean_string(get_section_by_del(clean_string(a), DEL_FIRST_MIDDLE, 0));
	} else {
		return clean_string(get_section_by_del(clean_string(get_section_by_del(a, DEL_LAST_FIRST, 1)), DEL_FIRST_MIDDLE, 0));
	}
	return "";
}

std::string get_name_last(std::string a) {
	if(a.find(DEL_LAST_FIRST) != std::string::npos) return clean_string(get_section_by_del(a, DEL_LAST_FIRST, 0));
	else return "";
}
std::string get_name_middle(std::string a) {
	if(a.find(DEL_LAST_FIRST) != std::string::npos
			&& clean_string(get_section_by_del(a, DEL_LAST_FIRST, 1)).find(DEL_FIRST_MIDDLE) != std::string::npos) {
		return get_section_by_del(clean_string(get_section_by_del(a, DEL_LAST_FIRST, 1)), DEL_FIRST_MIDDLE, 1);
	}
	else return "";
}

bool compare_lex(std::string a, std::string b, int sort_pref) {
	switch(sort_pref) {
		case SORT_PREF_MAX: {
			if(a.size() == 0) return false;
			else if(b.size() == 0) return true;
			return toupper(a.at(0)) < toupper(b.at(0));
		}
		case SORT_PREF_MIN: {
			if(a.size() == 0) return true;
			else if(b.size() == 0) return false;
			return toupper(a.at(0)) > toupper(b.at(0));
		}
	}
	log_error(ERROR_SORT_TYPE);
	return false;
}

bool compare_len(std::string a, std::string b, int sort_pref) {
	switch(sort_pref) {
		case SORT_PREF_MAX: return a.size() > b.size();
		case SORT_PREF_MIN: return a.size() < b.size();
	}
	log_error(ERROR_SORT_TYPE);
	return false;
}

bool compare(std::string a, std::string b, int sort_pref, int sort_type) {
	switch(sort_type) {
		case SORT_TYPE_LEXICOGRAPHICAL_LASTNAME:
			return compare_lex(get_name_last(a), get_name_last(b), sort_pref);
		case SORT_TYPE_LEXICOGRAPHICAL_FIRSTNAME:
			return compare_lex(get_name_first(a), get_name_first(b), sort_pref);
		case SORT_TYPE_LEXICOGRAPHICAL_MIDDLENAME:
			return compare_lex(get_name_middle(a), get_name_middle(b), sort_pref);
		case SORT_TYPE_LENGTH_LASTNAME:
			return compare_len(get_name_last(a), get_name_last(b), sort_pref);
		case SORT_TYPE_LENGTH_FIRSTNAME:
			return compare_len(get_name_first(a), get_name_first(b), sort_pref);
		case SORT_TYPE_LENGTH_MIDDLENAME:
			return compare_len(get_name_middle(a), get_name_middle(b), sort_pref);
	}
	log_error(ERROR_SORT_PREF);
	return false;
}

int get_parent_index(int index) {
	return std::floor((index-1) / 2);
}

int get_node_left(int index) {
	return index*2 + 1;
}

int get_node_right(int index) {
	return index*2 + 2;
}

void sort_nodes(std::string array[NUM_NAMES], int index_root, int index_last, int sort_pref, int sort_type) {
	int parent_node = index_root;
	int swap_index = index_root;

	//While we still have nodes to the left to process
	while(get_node_left(parent_node) <= index_last) {
		//Start off as planning to swap parent and node
		swap_index = parent_node;

		//We need to do the comparisons backwards and put the smallest at the parent,
		//as the final step will move the smallest elements to the back
		//This is because the 'left' side of the tree is the unsorted side,
		//and the right side is preserved. Therefore, since we are working with the left side,
		//we put the smallest first and let it get moved to the back after

		//If the element at parent node is 'greater' than the left child, we select it as the smaller one
		if(compare(array[swap_index], array[get_node_left(parent_node)], sort_pref, sort_type))
			swap_index = get_node_left(parent_node);

		//If the right child is within range and is smaller than the parent or left child , we now select it
		if(get_node_right(parent_node) <= index_last && compare(array[swap_index], array[get_node_right(parent_node)], sort_pref, sort_type))
			swap_index = get_node_right(parent_node);

		//Make sure we aren't still at the parent node. If this is true, its the smallest and we are finished
		if(swap_index == parent_node)
			break;
		else {
			//If it isn't the smallest perform the swap. This element is the smallest and is set to the parent
			element_swap(array[parent_node], array[swap_index]);
			parent_node = swap_index;
		}
	}
}

//I used heap sort, since you talked about it and it seemed interesting to learn about
void heap_sort(std::string array[NUM_NAMES], int sort_pref, int sort_type) {
	//We start at the parent, which is somewhat in the middle
	int start = get_parent_index(NUM_NAMES-1);
	//Our end is the end of the array
	int end = NUM_NAMES - 1;

	while(start >= 0) {
		//This sets up our heap. It puts the smallest value at the front (later to be moved)
		sort_nodes(array, start, end, sort_pref, sort_type);
		start--;
	}

	while(end > 0) {
		//Since the smallest element is now at the front, we push it to the back
		element_swap(array[end], array[0]);
		//Take one away from the total size to preserve the sorted elements at the end
		end--;
		//Resort the array, again moving the smallest to the front and placing others accordingly
		sort_nodes(array, 0, end, sort_pref, sort_type);
	}

	//Once end is 1, we know the array is fully sorted and the function ends

}

///////////////////////////////////
///////////// PRINTING ////////////
///////////////////////////////////

void print_name_array(std::string array[NUM_NAMES]) {
	for(int i = 0; i < NUM_NAMES; i++) std::cout << array[i] << "\n";
}

void print_table_line(std::string a, std::string b, std::string c) {
	std::cout << std::left << std::setw(FORMAT_WIDTH) << std::setfill(' ') << a;
	std::cout << std::left << std::setw(FORMAT_WIDTH) << std::setfill(' ') << b;
	std::cout << std::left << std::setw(FORMAT_WIDTH) << std::setfill(' ') << c << "\n";
}

void print_name_array_formatted(std::string array[NUM_NAMES]) {
	print_table_line("FIRST NAME", "MIDDLE NAME", "LAST NAME");
	for(int i = 0; i < NUM_NAMES; i++) {
		print_table_line(get_name_first(array[i]), get_name_middle(array[i]), get_name_last(array[i]));
	}
}


///////////////////////////////////
///////////// MAIN ////////////////
///////////////////////////////////


int main() {
	std::string names_modified[NUM_NAMES] = NAMES;
	std::cout << "Unmodified Array:\n";
	print_name_array_formatted(names_modified);

	/*
	PREFERENCES:
	SORT_PREF_MAX							- From greatest to least (long-short, a-z)
	SORT_PREF_MIN							- From least to greatest (short-long, z-a)

	TYPES:
	SORT_TYPE_LEXICOGRAPHICAL_LASTNAME		- A-Z or Z-A order of last names
	SORT_TYPE_LEXICOGRAPHICAL_FIRSTNAME		- A-Z or Z-A order of first names
	SORT_TYPE_LEXICOGRAPHICAL_MIDDLENAME	- A-Z or Z-A order of middle names
	SORT_TYPE_LENGTH_LASTNAME				- Longest-Shortest or Shortest-Longest of last names
	SORT_TYPE_LENGTH_FIRSTNAME				- Longest-Shortest or Shortest-Longest of first names
	SORT_TYPE_LENGTH_MIDDLENAME				- Longest-Shortest or Shortest-Longest of middle names
	*/

	//heap_sort(array, preference, type)

	// DEMO
	heap_sort(names_modified, SORT_PREF_MAX, SORT_TYPE_LEXICOGRAPHICAL_LASTNAME);
	std::cout << "\n\nA-Z, Lexicographical Last Name Array:\n";
	print_name_array_formatted(names_modified);

	heap_sort(names_modified, SORT_PREF_MIN, SORT_TYPE_LEXICOGRAPHICAL_LASTNAME);
	std::cout << "\n\nZ-A, Lexicographical Last Name Array:\n";
	print_name_array_formatted(names_modified);

	heap_sort(names_modified, SORT_PREF_MAX, SORT_TYPE_LEXICOGRAPHICAL_FIRSTNAME);
	std::cout << "\n\nA-Z, Lexicographical First Name Array:\n";
	print_name_array_formatted(names_modified);

	heap_sort(names_modified, SORT_PREF_MIN, SORT_TYPE_LEXICOGRAPHICAL_FIRSTNAME);
	std::cout << "\n\nZ-A, Lexicographical First Name Array:\n";
	print_name_array_formatted(names_modified);

	heap_sort(names_modified, SORT_PREF_MAX, SORT_TYPE_LEXICOGRAPHICAL_MIDDLENAME);
	std::cout << "\n\nA-Z, Lexicographical Middle Name Array:\n";
	print_name_array_formatted(names_modified);

	heap_sort(names_modified, SORT_PREF_MIN, SORT_TYPE_LEXICOGRAPHICAL_MIDDLENAME);
	std::cout << "\n\nZ-A, Lexicographical Middle Name Array:\n";
	print_name_array_formatted(names_modified);

	heap_sort(names_modified, SORT_PREF_MAX, SORT_TYPE_LENGTH_LASTNAME);
	std::cout << "\n\nGreatest-Least, Length of Last Name Array:\n";
	print_name_array_formatted(names_modified);

	heap_sort(names_modified, SORT_PREF_MIN, SORT_TYPE_LENGTH_LASTNAME);
	std::cout << "\n\nLeast-Greatest, Length of Last Name Array:\n";
	print_name_array_formatted(names_modified);

	heap_sort(names_modified, SORT_PREF_MAX, SORT_TYPE_LENGTH_FIRSTNAME);
	std::cout << "\n\nGreatest-Least, Length of First Name Array:\n";
	print_name_array_formatted(names_modified);

	heap_sort(names_modified, SORT_PREF_MIN, SORT_TYPE_LENGTH_FIRSTNAME);
	std::cout << "\n\nLeast-Greatest, Length of First Name Array:\n";
	print_name_array_formatted(names_modified);

	heap_sort(names_modified, SORT_PREF_MAX, SORT_TYPE_LENGTH_MIDDLENAME);
	std::cout << "\n\nGreatest-Least, Length of Middle Name Array:\n";
	print_name_array_formatted(names_modified);

	heap_sort(names_modified, SORT_PREF_MIN, SORT_TYPE_LENGTH_MIDDLENAME);
	std::cout << "\n\nLeast-Greatest, Length of Middle Name Array:\n";
	print_name_array_formatted(names_modified);

    return EXIT_SUCCESS;
}
