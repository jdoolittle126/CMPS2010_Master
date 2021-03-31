/*
 * Jonathan Doolittle
 * CMPS 2010
 * Professor Toothman
 * Homework #2
 *
 * This program displays primes up to 200
 */

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>


const int PRIMES_TO_GEN = 200;

std::list<int> generate_primes(int max_value){
	std::list<int> primes (1, 2);
	bool prime;
	//Evens will never be primes so we can skip those fellas
	for(int i = 3; i < max_value; i+=2){
		prime = false;
		for(std::list<int>::iterator iterator = primes.begin(); iterator != primes.end(); iterator++){
			prime = (i % *iterator != 0);
			if(!prime) break;
		}
		if(prime) primes.push_back(i);
	}
	return primes;
}


int main(){
	std::list<int> p = generate_primes(PRIMES_TO_GEN);
	for (std::list<int>::iterator iterator = p.begin(); iterator != p.end(); iterator++){
		std::cout << *iterator << "\n"; //I could have just printed in the function but I was using this for a prime factorization program
	}
	return 0;
}
