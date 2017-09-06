#ifndef __BUBBLE_SORT_H_
#define __BUBBLE_SORT_H_

template<typename T>
void bubbleSort(T *array, int len) {
	for(int i = 0; i < len; i++) {
		for(int j = len-1; j > i; j--) {
			if(array[j] < array[j-1]) {
				T tmp = array[j];
				array[j] = array[j-1];
				array[j-1] = tmp;
			}
		}
	}
}

#endif
