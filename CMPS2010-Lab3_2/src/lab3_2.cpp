/*
 * Jonathan Doolittle
 * CMPS 2010
 * Professor Toothman
 * 9/12/2019
 *
 */

#include <iostream>
#include <limits>
#include <string>

using namespace std;

void clear_buffer(){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

float get_distance(){
	float input;
	if(cin >> input && input >= 0){
		clear_buffer();
		return input;
	} else {
		clear_buffer();
		cout << "\nEnter a positive distance: ";
		if(cin >> input && input >= 0){
			clear_buffer();
			return input;
		} else {
			exit(0);
		}
	}
}

float get_medium(float distance){
	cout << "Mediums:\nA. Air   (1,100  feet per second)\nB. Water (4,900  feet per second)\nC. Steel (16,400 feet per second)\nChoose a medium: ";
	char input;
	string medium;
	float total;
	if(cin >> input && (input == 'A' || input == 'a' || input == 'B' || input == 'b'  || input == 'C' || input == 'c')){

		input =  toupper(input);

		switch(input){
		case 'A': medium = "air"; total = distance / 1100.0f;
			break;
		case 'B': medium = "water"; total = distance / 4900.0f;
			break;
		case 'C': medium = "steel"; total = distance / 16400.0f;
			break;
		}


		printf("Time to travel %i feet through ", distance);
        cout << medium;
        printf(": %.4f seconds", total);
	} else {
		exit(0);
	}
}


int main(){
	cout << "Enter a distance: ";
	get_medium(get_distance());
	return 0;
}

