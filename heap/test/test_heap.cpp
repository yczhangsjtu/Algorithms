#include "heap.hpp"
#include <gtest/gtest.h>

bool compare(const int &a, const int &b) {
	return a > b;
}

TEST(BuildHeapTest, Sorted) {
	int array[] =  {6,5,4,3,2,1};
	int sarray[] = {6,5,4,3,2,1};
	int s = sizeof(array)/sizeof(array[0]);
	buildHeap(array,s,compare);
	for(int i = 0; i < s; i++)
		ASSERT_EQ(array[i],sarray[i]);
}

TEST(BuildHeapTest, Normal) {
	int array[] =  {4,1,3,2,16,9,10,14,8,7};
	int sarray[] = {16,14,10,8,7,9,3,2,4,1};
	int s = sizeof(array)/sizeof(array[0]);
	buildHeap(array,s,compare);
	for(int i = 0; i < s; i++)
		ASSERT_EQ(array[i],sarray[i]);
}

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
