#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "core.h"

using std::vector;
class MATH_UNITTEST : public ::testing::Test{
	protected:
		virtual void SetUp(){
		}
		virtual void TearDown(){
		}
};

/*********************************************
Basic math unit tests
**********************************************/
TEST_F(MATH_UNITTEST, SLICE){
  vector<int> a = {0,1,2,3,4,5,6,7,8,9};
  vector<int> ans1 = {0,1,2};
  vector<int> out1 = slice<int>(a,0,2);
  ASSERT_EQ(ans1, out1);

  vector<int> ans2 = {0,1,2,3,4,5,6,7};
  vector<int> out2 = slice<int>(a,0,a.size() - 2 - 1);
  ASSERT_EQ(ans2, out2);
}

