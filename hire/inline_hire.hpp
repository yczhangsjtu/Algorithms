#ifndef __INLINE_HIRE_H_
#define __INLINE_HIRE_H_

#include <cmath>
#include "randomize_in_place.hpp"

template<typename T>
T inlineHire(T *array, int len) {
	int k = len/M_E;
	randomizeInPlace(array,len);
	T max = array[0];
	for(int i = 1; i < k; i++) {
		if(array[i] > max)
			max = array[i];
	}
	for(int i = k; i < len; i++) {
		if(array[i] > max) return array[i];
	}
	return array[len-1];
}

#endif
