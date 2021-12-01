#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "core.h"
// #include "tensor_math.h"

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
TEST_F(MATH_UNITTEST, VECTOR_PRODUCT){
    ASSERT_EQ(6, vector_product({1,2,3}));
}
