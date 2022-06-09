#include <iostream>
#include "MassiveFunc.h"

void printM(int *array, int countElem) {
    for (int i = 0; i < countElem; i ++) {
    	printf("%d ", *(array + i));
	
    }
    printf("\n");
}

void GenerateMassive(int *array, int countElem) { 
    for (int i = 0; i < countElem; i ++) {
        *(array + i) = i + 1;
    }
}

