#ifndef __RANDOMIZE_IN_PLACE_H_
#define __RANDOMIZE_IN_PLACE_H_

#include <cstdlib>

template<typename T>
void randomizeInPlace(T *array, int len) {
	for(int i = 0; i < len; i++) {
		int k = (((double)rand()/RAND_MAX) * (len-i))+i;
		T tmp = array[i];
		array[i] = array[k];
		array[k] = tmp;
	}
}

#endif
