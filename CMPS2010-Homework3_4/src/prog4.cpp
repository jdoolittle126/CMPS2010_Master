/*
 * Jonathan Doolittle
 * CMPS 2010
 * Professor Toothman
 * Homework #3
 *
 */

// This function changes the values of characters in the array. It only affects
// characters between the start and size parameters, and it advances through
// the array by (stride) elements at a time.
void transform(char array[], int size, int start, int stride, char c) {
	for(int i = start; i < size; i+=stride){
		array[i] = c;
	}
}
