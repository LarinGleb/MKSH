#include <algorithm>
#include <iostream>
#include "BubbleSort.h"
void BubbleSort(int *array, int countElem, int* countSwaps, int* countCompares, bool reversed) {
    bool noSwaps;
    int sign = (reversed) ? -1: 1;

    while (true) {
        noSwaps = true;
        for (int i = 0; i < countElem - 1; i ++) {
	    *countCompares += 1;
    	    if (*(array + i) * sign > *(array + i + 1) * sign) {
	        std::swap(*(array + i), *(array + i + 1));
	        noSwaps = false;
	        *countSwaps += 1;
	    }
        }

        if (noSwaps) {
 	    break;
	
        }
    }
}
 
