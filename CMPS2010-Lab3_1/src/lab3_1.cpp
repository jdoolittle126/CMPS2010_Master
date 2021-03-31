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

const float PRICE = 99.00f;
const int ARRAY_SIZE = 7;
int quantity_options[ARRAY_SIZE] = {9, 19, 29, 39, 60, 80, 81};
float price_modifier[ARRAY_SIZE] = {1.0f, 0.90f, 0.85f, 0.80f, 0.70f, 0.60f, 0.50f};

/*
 * A company sells licenses for their software for $99.00, but they offer a discount when buying in bulk:
Quantity	Discount
1-9	0%
10-19	10%
20-29	15%
30-39	20%
40-60	30%
61-80	40%
81 or more	50%
 *
 */



void clear_buffer(){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

float calc_total(int quantity){
	for(int i = 0; i < ARRAY_SIZE-1; i++){
		if(quantity < quantity_options[i]) return quantity * PRICE * price_modifier[i];
	}

	return quantity * PRICE * price_modifier[ARRAY_SIZE - 1];
}

int get_input(){
	int input;
	if(cin >> input && input >= 0){
		clear_buffer();
		return input;
	} else {
		clear_buffer();
		cout << "\nNOT A VALID INPUT!! Try again: ";
		get_input();
	}
}

int main(){
	cout << "Thank you for considering Jon's \'Clippy Remastered!\' Please enter an amount of licenses for an estimate: ";
	printf("Your total is: $%.2f", calc_total(get_input()));
	return 0;
}



