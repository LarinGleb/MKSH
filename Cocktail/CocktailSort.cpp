#include <iostream>
#include "CocktailSort.h"

void CocktailSort(int *array, int countElem, int *countSwaps, int *countCompares, bool reversed) {
    int left = 0;
    int right = countElem - 1;
    bool swapped = false;
    int sign = (reversed) ? -1: 1;

    while (true) {
	swapped = false;
	for (int i = left; i < right; i++) {
	    *countCompares += 1;
  	    if (*(array + i) * sign > *(array + i + 1) * sign) {
		*countSwaps += 1;
	 	swapped = true;
		std::swap(*(array + i), *(array + i + 1));
	    }
	}

	if (!swapped) break;

	right--;

	swapped = false;

	for (int i = right - 1; i >= left; i--) {
	    *countCompares += 1;
	    if (*(array + i) * sign > *(array + i + 1) * sign) {
	    	*countSwaps += 1;
		swapped = true;
		std::swap(*(array + i), *(array + i + 1));
            }
	}
	if (!swapped) break;

	left++;
    }
}

