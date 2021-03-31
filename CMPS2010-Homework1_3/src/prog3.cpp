////////////////////////////////////////////////////////////////////////////////
// CMPS 2010
// Professor Toothman
// Jonathan Doolittle
// 9/5/2019
// 
// Homework 1
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

float tax = 0.07f;
float items[5] = {5.95f, 22.95f, 9.95f, 11.95f, 2.95f};


void print_sale(float f){
	printf("%-10s $%-.2f\t%-10s $%-.2f\t%-10s $%-.2f\t%-10s $%-.2f \n", "Cost ", f, "Subtotal ", f, "Tax", f*tax, "Total", f+(f*tax));
}

int main(){
	for(float f:items){
		print_sale(f);
	}
	return 0;
}
