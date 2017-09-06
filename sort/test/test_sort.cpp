#include "insertion_sort.hpp"
#include <gtest/gtest.h>

TEST(InsertionSortTest, Sorted) {
	int array[] =  {1,2,3,4,5,6};
	int sarray[] = {1,2,3,4,5,6};
	int s = sizeof(array)/sizeof(array[0]);
	insertionSort(array,s);
	for(int i = 0; i < s; i++)
		ASSERT_EQ(array[i],sarray[i]);
}

TEST(InsertionSortTest, Normal) {
	int array[] =  {1,4,5,2,3,6};
	int sarray[] = {1,2,3,4,5,6};
	int s = sizeof(array)/sizeof(array[0]);
	insertionSort(array,s);
	for(int i = 0; i < s; i++)
		ASSERT_EQ(array[i],sarray[i]);
}

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
