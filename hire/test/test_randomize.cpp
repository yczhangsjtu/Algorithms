#include "randomize_in_place.hpp"
#include "inline_hire.hpp"
#include <gtest/gtest.h>
#include <cstdlib>
#include <ctime>

TEST(RandomizeInPlace, Sorted) {
	int array[] =  {1,2,3,4,5,6};
	int sarray[] = {0,0,0,0,0,0};
	int s = sizeof(array)/sizeof(array[0]);
	randomizeInPlace(array,s);
	for(int i = 0; i < s; i++)
		sarray[array[i]-1] = 1;
	for(int i = 0; i < s; i++)
		EXPECT_EQ(sarray[i],1);
}

TEST(InlineHire, Sorted) {
	int array[] =  {1,2,3,4,5,6};
	int s = sizeof(array)/sizeof(array[0]);
	int count = 0;
	for(int i = 0; i < 1000; i++) {
		int res = inlineHire(array,s);
		if(res == 6) count++;
	}
	EXPECT_GE(count,300);
	EXPECT_LE(count,500);
}


int main(int argc, char *argv[]) {
	srand((unsigned)time(0));
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
