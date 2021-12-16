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


/*********************************************
Matrix Multiplication Tests
**********************************************/
TEST_F(MATH_UNITTEST, BASIC_MATRIX_MULTIPLICATION_1){
	vector<float> src1 = {1,2,3,4};
	vector<float> src2 = {5,6,7,8};

	vector<float> answer = {19, 22, 43, 50};
	vector<float> output = mmult<float>(src1, src2, 2,2,2);

  ASSERT_EQ(answer, output);
}


/*********************************************
Matrix Multiplication Tests
**********************************************/
TEST_F(MATH_UNITTEST, BASIC_MATRIX_MULTIPLICATION_2){
	vector<float> src1 = {1,2,3,4};
	vector<float> src2 = {1,2,3,4,5,6};

	vector<float> answer = {9,12,15,19,26,33};
	vector<float> output = mmult<float>(src1, src2, 2, 2, 3);
	ASSERT_EQ(answer, output);
}
