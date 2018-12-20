#ifndef __HEAP_SORT_H_
#define __HEAP_SORT_H_

#include "heap.hpp"

template<typename T>
void heapSort(T *array, int len, bool (*compare)(const T&,const T&)) {
	buildHeap(array,len,compare);
	for(int i = len-1; i > 0; i--) {
		T tmp = array[i];
		array[i] = array[0];
		array[0] = tmp;
		len--;
		heapify(array,len,0,compare);
	}
}

#endif
