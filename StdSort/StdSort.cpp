#include <iostream>
#include "StdSort.h"
#include <vector>
#include <algorithm>

void StdSort(int *array, int countElem, int * countSwaps, int *countCompares, bool reversed) {
    std::vector<int> arrayNoPtr;

    for (int i = 0; i < countElem; i++) {
	arrayNoPtr.push_back(*(array + i));
    }

    int sign = (reversed) ? -1 : 1;
    int countSwapsSTD = 0;
    int countComparesSTD = 0;

    std::sort(std::begin(arrayNoPtr), std::end(arrayNoPtr), [&countSwapsSTD, &countComparesSTD, sign]( unsigned int lhs, unsigned int rhs) {countComparesSTD++; if (lhs * sign < rhs * sign) {countSwapsSTD++; return true;} else {return false;}});
    for (int i = 0; i < countElem; i ++) {
	*(array + i) = arrayNoPtr.at(i);
    }

    *countSwaps = countSwapsSTD;
    *countCompares = countComparesSTD;
}
