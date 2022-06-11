#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include "main.h"
#include "Bubble/BubbleSort.h"
#include "Cocktail/CocktailSort.h"
#include "MassiveFunc/MassiveFunc.h"
#include "Insertion/InsertionSort.h"
#include "Gnome/GnomeSort.h"
#include "StdSort/StdSort.h"
#include <chrono>
#include <unistd.h>
#include <vector>
#include <cmath> 

#define COUNT_TESTS 3
#define FIRST_TEST (int)pow(2, 11)
#define SECOND_TEST (int)pow(2, 13)
#define THIRD_TEST (int)pow(2, 15)


int tests[COUNT_TESTS] = {FIRST_TEST, SECOND_TEST, THIRD_TEST};

void TestMassive(std::string nameSort,  void(*sortFunc)(int*, int, int*, int*, bool), bool debug) {
    std::vector<int*> massives; 
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
	
	int countHalfCompares = 0;
	int countHalfSwaps = 0;

    	auto start = std::chrono::steady_clock::now();
	sortFunc(massives[i], countElem, &countSwaps, &countCompares, false); 
    	if (debug) printM(massives[i], countElem);
	
	auto end = std::chrono::steady_clock::now();
	auto difference = std::chrono::duration<double, std::milli>(end - start).count();
	
	std::shuffle(massives[i], massives[i] + countElem, std::default_random_engine(unsigned(std::time(0))));
	
	start = std::chrono::steady_clock::now();
	sortFunc(massives[i], countElem, &countReversedSwaps, &countReversedCompares, true);
        end = std::chrono::steady_clock::now();
	auto differenceReversed = std::chrono::duration<double, std::milli>(end - start).count();

	std::shuffle(massives[i], massives[i] + countElem, std::default_random_engine(unsigned(std::time(0))));
	
	GenerateMassiveHalf(massives[i], countElem);
	
	start = std::chrono::steady_clock::now();
	sortFunc(massives[i], countElem, &countHalfSwaps, &countHalfCompares, false);
	end = std::chrono::steady_clock::now();
	auto differenceHalf = std::chrono::duration<double, std::milli>(end - start).count();

	std::cout << "Count elements: " << countElem << std::endl;
	
	std::cout << "For sort reversed = false: " << std::endl;
	std::cout << "    1) Time: " << difference << " millisec" << std::endl;
	std::cout << "    2) Count swaps: " << countSwaps << std::endl;
	std::cout << "    3) Count compares: " << countCompares << std::endl;

	std::cout << "For sort reversed = true: " << std::endl;
        std::cout << "    1) Time: " << differenceReversed << " millisec" << std::endl;
        std::cout << "    2) Count swaps: " << countReversedSwaps << std::endl;
        std::cout << "    3) Count compares: " << countReversedCompares << std::endl;

	std::cout << "For half sorted massive before start sort:" << std::endl;
	std::cout << "    1) Time: " << differenceHalf << " millisec" << std::endl;
	std::cout << "    2) Count swaps: " << countHalfSwaps << std::endl;
	std::cout << "    3) Count compares: " << countHalfCompares << std::endl;

	std::cout << std::endl;
    }   

}

int main() {
    
    TestMassive("Bubble Sort", *BubbleSort);
    TestMassive("Cocktail Sort", *CocktailSort);
    TestMassive("Insertion Sort", *InsertionSort);
    TestMassive("Gnome Sort", *GnomeSort);
    TestMassive("std::sort", *StdSort);
    std::cout << "Enter to exit" << std::endl;
    std::cin.get();
    return 0;
}
