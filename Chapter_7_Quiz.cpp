// Binary Search, not very clean, but it works. The unit test is defined in main
// Chris sanchez; 7/24/18
//

#include "stdafx.h"
#include <iostream>

int numberOfElements(int,int, int *array);
int findIndex( int target, int *array);



int binarySearch(int *array, int target, int min, int max) {

	int numElements = max;


	while (numElements > 1) {

		numElements = numberOfElements(min, max, array);

		int midPoint_Index;
		midPoint_Index = numElements / 2; 	

		// If the center element is greater than the target element, discard the top half of the array
		if (array[min + midPoint_Index] > target) {
			max = (min + midPoint_Index) - 1;
		}

		// If the center element is less than the target element, discard the bottom half of the array
		if (array[min + midPoint_Index] < target) {
			min = min + midPoint_Index;
			if (min > target) return -1;
		}
		//if the center element equals the target element, return the index of the center element.
		if (array[min + midPoint_Index] == target) {
			std::cout << "mid point index is " <<  midPoint_Index <<'\n';
			int i = findIndex(target, array);
			//return midPoint_Index;
			return i;
		}

		//if you discard the entire array without finding the target element, return -1
		if (numElements < 1) return -1;
	}


	return -1;
}

int numberOfElements(int min, int max, int *array) {
	// this is how to find the number of elements from the segment of array newly set by min/max
	int countElements = 0;
	for (int i = min; i < max; ++i) {
		if (array[i] >= min) {
			++countElements;
		}
	}
	return countElements;
}

int findIndex(int target, int *array) {
	for (int i = 0; i < 14; ++i) {
		if (array[i] == target) {
			return i;
		}
	}return -1;
}


int main()
{
	int array[] = { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48};

	//test a bunch of values 
	const int numTestValues = 9;
	//the test values
	int testValues[numTestValues] = { 0, 3, 12, 13, 22, 26, 43, 44, 49 };
	//the expected results for each value
	int expectedValues[numTestValues] = { -1, 0, 3, -1, -1, 8, -1, 13, -1 };


	//loop through all of the test values

	for (int count = 0; count < numTestValues; ++count) {
		//see if our test value is in the array
		int index = binarySearch(array, testValues[count], 0, 14);
		//If it matches our expected value, then great!
		if (index == expectedValues[count])
			std::cout << "Test value " << testValues[count] << " passed!\n";
		else //otherwise our binarySearch() function must be broken
			std::cout << "Test value " << testValues[count] << " failed. There's something wrong with your code!\n";
	}
	

    return 0;
}

