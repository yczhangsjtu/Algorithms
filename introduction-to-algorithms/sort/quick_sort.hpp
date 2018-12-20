#ifndef __QUICK_SORT_H_
#define __QUICK_SORT_H_

#include <iostream>
#include <cassert>
#include <cstdlib>

template<typename T>
int partition(T *array, int len) {
	assert(len >= 2);
	T x = array[len-1];
	int i = 0;
	for(int j = 0; j < len-1; j++) {
		if(array[j] <= x) {
			T tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
		}
	}
	T tmp = array[i];
	array[i] = array[len-1];
	array[len-1] = tmp;
	return i;
}

template<typename T>
void quickSort(T *array, int len) {
	if(len < 2) return;
	int q = partition(array,len);
	quickSort(array,q);
	quickSort(array+q+1,len-q-1);
}

template<typename T>
int rpartition(T *array, int len) {
	assert(len >= 2);
	int i = rand()%len;
	T tmp = array[i];
	array[i] = array[len-1];
	array[len-1] = tmp;
	return partition(array,len);
}

template<typename T>
void rquickSort(T *array, int len) {
	if(len < 2) return;
	int q = rpartition(array,len);
	rquickSort(array,q);
	rquickSort(array+q+1,len-q-1);
}

#endif
