////////////////////////////////////////////////////////////////////////////////
// CMPS 2010
// Professor Toothman
// Jonathan Doolittle
// 9/5/2019
// 
// Homework 1
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
const float incr = 3.3f;
int years[5] = {1, 2, 4, 8, 16};

int main(){
	for(int x : years){
		printf("The sea will have rose %fmm in %i year(s)\n", x*incr, x);
	}
	return 0;
}



