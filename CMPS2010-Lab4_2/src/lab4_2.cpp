/*
 * Jonathan Doolittle
 * CMPS 2010
 * Professor Toothman
 * 9/19/2019
 *
 *
 */

#include <iostream>

void calc_loan(){
	std::cout << "\n------------------\nEnter a balance: ";
	int balance;
    std::cin >> balance;
	while(balance > 0){
		int min = (balance * 0.04f < 1) ? 1 : static_cast<int>(balance * 0.04f);
		std::cout << "Balance is $" << balance << ". Minimum payment is $" << min << ".\nEnter a payment amount: ";
		int payment;
        std::cin >> payment;
		if(payment >= min && payment <= balance) balance -= payment;
		else std::cout << "Incorrect payment. Minimum is $" << min << " and maximum is $" << balance << ".\n";
	}
	std::cout << "\nLoan is paid off.";

}

int main(){
    calc_loan();
	return 0;

}
