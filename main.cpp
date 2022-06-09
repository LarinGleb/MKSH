#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include "main.h"
#include "Bubble/BubbleSort.h"
#include "MassiveFunc/MassiveFunc.h"
#include <chrono>
#include <unistd.h>
#include <vector>
#include <cmath> 

#define COUNT_TESTS 3
#define FIRST_TEST (int)pow(2, 9)
#define SECOND_TEST (int)pow(2, 12)
#define THIRD_TEST (int)pow(2, 15)


int tests[COUNT_TESTS] = {FIRST_TEST, SECOND_TEST, THIRD_TEST};
std::vector<int*> massives;

void TestMassive(std::string nameSort,  void(*sortFunc)(int*, int, int*, int*, bool)) {
    for (int i = 0; i < COUNT_TESTS; i ++) {
	massives.push_back(new int[tests[i]]);
    }	

    std::cout << "-------------------------" << nameSort << "-------------------------" << std::endl;
    for (int i = 0; i < COUNT_TESTS; i ++) {
        int countElem = tests[i];	
    	GenerateMassive(massives[i], countElem);
    	std::shuffle(massives[i], massives[i] + countElem, std::default_random_engine(unsigned(std::time(0))));
    
    	int countCompares = 0;
    	int countSwaps = 0;
	int countReversedCompares = 0;
	int countReversedSwaps = 0;

    	auto start = std::chrono::steady_clock::now();
    	sortFunc(massives[i], countElem, &countSwaps, &countCompares, false); 
    	auto end = std::chrono::steady_clock::now();
	auto difference = std::chrono::duration<double, std::milli>(end - start).count();

	start = std::chrono::steady_clock::now();
        sortFunc(massives[i], countElem, &countReversedSwaps, &countReversedCompares, true);
        end = std::chrono::steady_clock::now();
	auto differenceReversed = std::chrono::duration<double, std::milli>(end - start).count();
	std::cout << "Count elements: " << countElem << std::endl;
	
	std::cout << "For sort reversed = false: " << std::endl;
	std::cout << "    1) Time: " << difference << " ms" << std::endl;
	std::cout << "    2) Count swaps: " << countSwaps << std::endl;
	std::cout << "    3) Count compares: " << countCompares << std::endl;

	std::cout << "For sort reversed = true: " << std::endl;
        std::cout << "    1) Time: " << differenceReversed << " ms" << std::endl;
        std::cout << "    2) Count swaps: " << countReversedSwaps << std::endl;
        std::cout << "    3) Count compares: " << countReversedCompares << std::endl;

	std::cout << std::endl;
    }   

}

int main() {
    TestMassive("Bubble Sort", *BubbleSort);
    return 0;
}
