/*
 * Jonathan Doolittle
 * CMPS 2010
 * Professor Toothman
 * 10/24/2019
 */

#include <iostream>
#include <string>
#define GRADE_QUANTITY 5

/*
Complete the following program. Include comments at the top of your source code files including your name, today's date, and the assignment. Save as lab6_1.cpp
Write a program to sort the grades for a class with 5 assignments.

First, ask for 5 grades between 0 and 100. Store them in an array of ints.
Then ask for 5 weights, also between 0 and 100, and store them in a separate array of ints.
The sum of the weights should add up to 100. If it does not, prompt for the weights again and continue doing so until their total sum is 100. You might use a do-while loop here.
After confirming the sum of the weights is 100, sort the arrays so that they are in descending order according to the weight.
Display the sorted results and the final grade.
 */

//Gets the sum of an array
int get_sum(int e[]){
	int sum = 0;
	for(int i = 0; i < GRADE_QUANTITY; i++){
		sum+= e[i];
	}
	return sum;
}

//Builds the array
void get_array(int e[], bool isWeight) {
	std::string s;
	if(isWeight) s = "weight";
	else s = "grade";

	std::cout << "Please enter " << GRADE_QUANTITY << " " << s << "s between (0-100)!\n";

	for(int i = 0; i < GRADE_QUANTITY; i++){
		std::cout << "Enter " << s << " " << i+1 << ": ";
		std::cin >> e[i];
		while(e[i] < 0 || e[i] > 100) {
			std::cout << "Invalid " << s << "! Must be between (0-100)!\n";
			std::cout << "Enter " << s << " " << i+1 << ": ";
			std::cin >> e[i];
		}
	}

	if(isWeight && get_sum(e) != 100) {
		std::cout << "Sum of weights is " << get_sum(e) << ", but it should be 100. Enter weights again.\n";
		get_array(e, true);
	}

}

void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

//Quicksort! My favorite sorting algorithm
void sort_arrays(int unsorted_weight[GRADE_QUANTITY], int unsorted_grade[GRADE_QUANTITY], int min, int max){
	if(min < max) {
		int x = min;
		for(int i = min; i < max; i++){
			if(unsorted_weight[i] > unsorted_weight[max]) {
				swap(unsorted_weight[x], unsorted_weight[i]);
				swap(unsorted_grade[x], unsorted_grade[i]);
				x++;
			}
		}
		swap(unsorted_weight[x], unsorted_weight[max]);
		swap(unsorted_grade[x], unsorted_grade[max]);
		sort_arrays(unsorted_weight, unsorted_grade, min, x-1);
		sort_arrays(unsorted_weight, unsorted_grade, x+1, max);
	}
}

int main() {
	float total;
	int grades[GRADE_QUANTITY], weights[GRADE_QUANTITY];
	get_array(grades, false);
	get_array(weights, true);
	sort_arrays(weights, grades, 0, GRADE_QUANTITY-1);

	for(int i = 0; i < GRADE_QUANTITY; i++){
		std::cout << "Grade " << i+1 << ": " << grades[i] << " (" << weights[i] << "%)\n";

		total += grades[i] * (weights[i] / 100.0f);
	}

	std::cout << "Final Grade: " << total << "\n";


	return 0;
}
