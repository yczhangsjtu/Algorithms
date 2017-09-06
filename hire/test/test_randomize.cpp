#include "randomize_in_place.hpp"
#include <gtest/gtest.h>

TEST(InsertionSortTest, Sorted) {
	int array[] =  {1,2,3,4,5,6};
	int sarray[] = {0,0,0,0,0,0};
	int s = sizeof(array)/sizeof(array[0]);
	randomizeInPlace(array,s);
	for(int i = 0; i < s; i++)
		sarray[array[i]-1] = 1;
	for(int i = 0; i < s; i++)
		EXPECT_EQ(sarray[i],1);
}

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
