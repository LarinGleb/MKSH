#include <iostream>
#include "GnomeSort.h"

void GnomeSort(int *array, int countElem, int *countSwaps, int *countCompares, bool reversed) {
    int sign = (reversed) ? -1 : 1;
    int index = 0;

    while (index < countElem) {
	if (index == 0) index ++;
	*countCompares += 1;
	if (*(array + index) * sign >= *(array + index - 1) * sign) index ++;
   	else {
	    std::swap(*(array + index), *(array + index - 1));
	    index --;
	    *countSwaps += 1;
	}
    }
}
