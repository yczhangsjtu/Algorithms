#ifndef __INSERTION_SORT_H__
#define __INSERTION_SORT_H__

template<typename T>
void insertionSort(T array[], int len) {
	if(len < 2) return;
	for(int j = 1; j < len; j++) {
		T key = array[j];
		int i;
		for(i = j-1; i >= 0 && array[i] > key; i--) {
			array[i+1] = array[i];
		}
		array[i+1] = key;
	}
}

#endif
