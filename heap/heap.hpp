#ifndef __HEAP_H_
#define __HEAP_H_

inline int heap_left(int i) {
	return 2*i+1;
}

inline int heap_right(int i) {
	return 2*i+2;
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

#endif
