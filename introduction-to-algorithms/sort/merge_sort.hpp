#ifndef __MERGE_SORT_H_
#define __MERGE_SORT_H_

#include <iostream>

template<typename T>
void merge(T *array, int p, int q, int r) {
	int n1 = q-p+1;
	int n2 = r-q;
	T *L = new T[n1];
	T *R = new T[n2];
	for(int i = 0; i < n1; i++)
		L[i] = array[p+i];
	for(int i = 0; i < n2; i++)
		R[i] = array[q+i+1];
	int i = 0, j = 0;
	for(int k = p; k <= r; k++) {
		if(j >= n2 || (i < n1 && L[i] <= R[j]))
			array[k] = L[i++];
		else
			array[k] = R[j++];
	}
	delete []L,R;
}

template<typename T>
void mergeSort(T *array, int len) {
	if(len < 2) return;
	mergeSort(array,len/2);
	mergeSort(array+len/2,len-len/2);
	merge(array,0,len/2-1,len-1);
}

#endif
