#include <iostream>
#include "MassiveFunc.h"
#include <random>
#include <ctime>
#include <algorithm>

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

void GenerateMassiveHalf(int *array, int countAll) {
    GenerateMassive(array, countAll);
    
    int * randomHalf = new int[countAll / 2];
    for (int i = 0; i < countAll / 2; i ++) {
	*(randomHalf + i) = *(array + countAll / 2 + i);
    }

    std::shuffle(randomHalf, randomHalf + countAll / 2, std::default_random_engine(unsigned(std::time(0))));

    for (int i = 0; i < countAll / 2; i ++) {
    	*(array + i + countAll / 2) = *(randomHalf + i);
    }

}
