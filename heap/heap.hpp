#ifndef __HEAP_H_
#define __HEAP_H_

#include <cassert>

inline int heap_left(int i) {
	return 2*i+1;
}

inline int heap_right(int i) {
	return 2*i+2;
}

inline int heap_parent(int i) {
	return (i-1)/2;
}

template<typename T>
void heapify(T *heap, int len, int i, bool (*compare)(const T&,const T&)) {
	int l = heap_left(i);
	int r = heap_right(i);
	int largest = i;
	if(l < len && compare(heap[l],heap[largest])) largest = l;
	if(r < len && compare(heap[r],heap[largest])) largest = r;
	if(largest != i) {
		T tmp = heap[i];
		heap[i] = heap[largest];
		heap[largest] = tmp;
		heapify(heap,len,largest,compare);
	}
}

template<typename T>
void buildHeap(T *heap, int len, bool (*compare)(const T&,const T&)) {
	for(int i = len/2-1; i >= 0; i--) {
		heapify(heap,len,i,compare);
	}
}

template<typename T>
T heapExtract(T *heap, int &len, bool (*compare)(const T&,const T&)) {
	assert(len > 0);
	T res = heap[0];
	heap[0] = heap[len-1];
	len--;
	heapify(heap,len,0,compare);
	return res;
}

template<typename T>
T heapIncreaseKey(T *heap, int &len, int i, T key, bool (*compare)(const T&,const T&)) {
	assert(compare(key,heap[i]));
	heap[i] = key;
	while(i > 0 && compare(heap[i],heap[heap_parent(i)])) {
		int p = heap_parent(i);
		T tmp = heap[i];
		heap[i] = heap[p];
		heap[p] = tmp;
		i = p;
	}
}

#endif
