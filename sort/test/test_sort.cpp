#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "bubble_sort.hpp"
#include "quick_sort.hpp"
#include "counting_sort.hpp"
#include "radix_sort.hpp"
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

TEST(MergeSortTest, Sorted) {
	int array[] =  {1,2,3,4,5,6};
	int sarray[] = {1,2,3,4,5,6};
	int s = sizeof(array)/sizeof(array[0]);
	mergeSort(array,s);
	for(int i = 0; i < s; i++)
		ASSERT_EQ(array[i],sarray[i]);
}

TEST(MergeSortTest, Normal) {
	int array[] =  {4,1,3,2,6,5};
	int sarray[] = {1,2,3,4,5,6};
	int s = sizeof(array)/sizeof(array[0]);
	mergeSort(array,s);
	for(int i = 0; i < s; i++)
		ASSERT_EQ(array[i],sarray[i]);
}

TEST(BubbleSortTest, Sorted) {
	int array[] =  {1,2,3,4,5,6};
	int sarray[] = {1,2,3,4,5,6};
	int s = sizeof(array)/sizeof(array[0]);
	bubbleSort(array,s);
	for(int i = 0; i < s; i++)
		ASSERT_EQ(array[i],sarray[i]);
}

TEST(BubbleSortTest, Normal) {
	int array[] =  {4,1,3,2,6,5};
	int sarray[] = {1,2,3,4,5,6};
	int s = sizeof(array)/sizeof(array[0]);
	bubbleSort(array,s);
	for(int i = 0; i < s; i++)
		ASSERT_EQ(array[i],sarray[i]);
}

TEST(QuickSortTest, Sorted) {
	int array[] =  {1,2,3,4,5,6};
	int sarray[] = {1,2,3,4,5,6};
	int s = sizeof(array)/sizeof(array[0]);
	quickSort(array,s);
	for(int i = 0; i < s; i++)
		ASSERT_EQ(array[i],sarray[i]);
}

TEST(QuickSortTest, Normal) {
	int array[] =  {4,1,3,2,6,5};
	int sarray[] = {1,2,3,4,5,6};
	int s = sizeof(array)/sizeof(array[0]);
	quickSort(array,s);
	for(int i = 0; i < s; i++)
		ASSERT_EQ(array[i],sarray[i]);
}

TEST(RQuickSortTest, Sorted) {
	int array[] =  {1,2,3,4,5,6};
	int sarray[] = {1,2,3,4,5,6};
	int s = sizeof(array)/sizeof(array[0]);
	rquickSort(array,s);
	for(int i = 0; i < s; i++)
		ASSERT_EQ(array[i],sarray[i]);
}

TEST(RQuickSortTest, Normal) {
	int array[] =  {4,1,3,2,6,5};
	int sarray[] = {1,2,3,4,5,6};
	int s = sizeof(array)/sizeof(array[0]);
	rquickSort(array,s);
	for(int i = 0; i < s; i++)
		ASSERT_EQ(array[i],sarray[i]);
}

TEST(CountingSortTest, Sorted) {
	int array[] =  {1,2,3,4,5,6};
	int sarray[] = {1,2,3,4,5,6};
	int s = sizeof(array)/sizeof(array[0]);
	countingSort(array,s,7);
	for(int i = 0; i < s; i++)
		ASSERT_EQ(array[i],sarray[i]);
}

TEST(CountingSortTest, Normal) {
	int array[] =  {4,1,3,2,6,5};
	int sarray[] = {1,2,3,4,5,6};
	int s = sizeof(array)/sizeof(array[0]);
	countingSort(array,s,7);
	for(int i = 0; i < s; i++)
		ASSERT_EQ(array[i],sarray[i]);
}

TEST(CountingSortTest, Repetive) {
	int array[] =  {2,5,3,0,2,3,0,3};
	int sarray[] = {0,0,2,2,3,3,3,5};
	int s = sizeof(array)/sizeof(array[0]);
	countingSort(array,s,7);
	for(int i = 0; i < s; i++)
		ASSERT_EQ(array[i],sarray[i]);
}

TEST(RadixSortTest, Normal) {
	int array[] =  {329,457,657,839,436,720,355};
	int sarray[] = {329,355,436,457,657,720,839};
	int s = sizeof(array)/sizeof(array[0]);
	radixSort(array,s,3);
	for(int i = 0; i < s; i++)
		ASSERT_EQ(array[i],sarray[i]);
}

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
