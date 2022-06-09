#include <algorithm>
#include <iostream>

void BubbleSort(int *array, int CountElem, int *countSwaps, int *countCompares, bool reversed = false) {
    bool noSwaps;
    while (true) {
	noSwaps = true;
	if (!reversed) {
	    for (int i = 0; i < CountElem - 1; i ++) {
		*countCompares += 1;
	    	if (*(array + i) > *(array + i + 1)) {
		    std::swap(*(array + i), *(array + i + 1));
		    noSwaps = false;
		    *countSwaps += 1;
		}
	    }

	    if (noSwaps) {
		break;
	    }
	}
	
	else {
	 
            for (int i = 0; i < CountElem - 1; i++) {
	        *countCompares += 1;
		if (*(array + i) < *(array + i + 1)) {
	            noSwaps = false;
		    *countSwaps += 1;
		   
		    std::swap(*(array+i), *(array+i+1));
	        }
             }
             if (noSwaps) {
                break;
            }
	     
	}
	
    }
}
 
