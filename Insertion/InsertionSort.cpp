#include <iostream>
#include "InsertionSort.h"

void InsertionSort(int *array, int countElem, int *countSwaps, int *countCompares, bool reversed) {
    int sign = (reversed) ? -1: 1;

    for (int i = 1; i < countElem; i ++) {
    	for(int j= i; j > 0; j --) {
	    *countCompares += 1;
	    if (*(array + j - 1) * sign > *(array + j) * sign) {
	   	*countSwaps += 1;
            	std::swap(*(array + j - 1), *(array + j));
	    }
	}
    }







}	
