#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "tensor.h"
#include "tensor_math.h"

using std::vector;
class TENSOR_UNITTEST : public ::testing::Test{
	protected:
		virtual void SetUp(){
		}
		virtual void TearDown(){
		}
};	




/*********************************************
Check that Tensor getters and setters work
**********************************************/ 
TEST_F(TENSOR_UNITTEST, GETTERS_AND_SETTERS_1){
	// Create a 3x3 tensor and define its values as 1...9
	vector<int> dims = {3,3};
	Tensor tensor = Tensor(dims);
	
	vector<float> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	tensor.set_data(data);

	// Check that the getters work properly
	ASSERT_EQ(tensor.get_num_dims(), 2);
	ASSERT_EQ(tensor.get_num_el(), data.size());
	ASSERT_EQ(*tensor.get_dims(), dims);
	ASSERT_EQ(*tensor.get_data(), data);
	

	// Change values with the setters and see if the data updates correctly
	vector<float> new_data(9, 0);
	tensor.set_data(new_data);
	ASSERT_EQ(*tensor.get_data(), new_data);

	// Check that you can get the pointer to the first value in the data array
	vector<float> new_data_2(9, 10);
	tensor.set_data(new_data_2);

	float* first_el_p = tensor.get_first_p();
	ASSERT_EQ(*first_el_p, new_data_2[0]);
}


/*********************************************
 * Broadcasting tests
 * ******************************************/

/*********************************************
Check that the following broadcasting behaviour works
(3x3x3) + (3x3x3) = (3x3x3)
**********************************************/ 
TEST_F(TENSOR_UNITTEST, BROADCASTING_1){
	
	vector<int> dims1 = {3,3,3};
	vector<int> dims2 = {3,3,3};

	Tensor src1 = Tensor(dims1);
	Tensor src2 = Tensor(dims2);

	vector<int> dst;

	TMATH_STATUS status = broadcast(src1, src2, dst, ADD);

	ASSERT_EQ(status, TMATH_SUCCESS);
	ASSERT_EQ(dst, dims2);
}

/*********************************************
Check that the following broadcasting behaviour works
(3x1x3) + (3x3x3) = (3x3x3)
**********************************************/ 
TEST_F(TENSOR_UNITTEST, BROADCASTING_2){
	
	vector<int> dims1 = {3,1,3};
	vector<int> dims2 = {3,3,3};

	Tensor src1 = Tensor(dims1);
	Tensor src2 = Tensor(dims2);

	vector<int> dst;

	TMATH_STATUS status = broadcast(src1, src2, dst, ADD);

	ASSERT_EQ(status, TMATH_SUCCESS);
	ASSERT_EQ(dst, dims2);
}		

/*********************************************
Check that the following broadcasting behaviour works
(3x3) + (3x3x3) = (3x3x3)
**********************************************/ 
TEST_F(TENSOR_UNITTEST, BROADCASTING_3){
	
	vector<int> dims1 = {3,3};
	vector<int> dims2 = {3,3,3};

	Tensor src1 = Tensor(dims1);
	Tensor src2 = Tensor(dims2);

	vector<int> dst;

	TMATH_STATUS status = broadcast(src1, src2, dst, ADD);

	ASSERT_EQ(status, TMATH_SUCCESS);
	ASSERT_EQ(dst, dims2);
}		

/*********************************************
Check that the following broadcasting behaviour works
(3x3) + (3x3x3) = (3x3x3)
**********************************************/ 
TEST_F(TENSOR_UNITTEST, BROADCASTING_4){
	
	vector<int> dims1 = {1,3,3};
	vector<int> dims2 = {3,3,3};

	Tensor src1 = Tensor(dims1);
	Tensor src2 = Tensor(dims2);

	vector<int> dst;

	TMATH_STATUS status = broadcast(src1, src2, dst, ADD);

	ASSERT_EQ(status, TMATH_SUCCESS);
	ASSERT_EQ(dst, dims2);
}		

/*********************************************
Check that the following broadcasting behaviour fails
(2x3x3) + (3x3x3) = ERROR
**********************************************/ 
TEST_F(TENSOR_UNITTEST, BROADCASTING_5){
	
	vector<int> dims1 = {2,3,3};
	vector<int> dims2 = {3,3,3};

	Tensor src1 = Tensor(dims1);
	Tensor src2 = Tensor(dims2);

	vector<int> dst;

	TMATH_STATUS status = broadcast(src1, src2, dst, ADD);

	ASSERT_EQ(status, TMATH_FAILURE);
}		

/*********************************************
 * Broadcasting tests
 * ******************************************/

 
TEST_F(TENSOR_UNITTEST, ADDITION){
	vector<int> dims1 = {3,3,3};
	vector<int> dims2 = {1};

	Tensor src1 = Tensor(dims1);
	Tensor src2 = Tensor(dims2);

	vector<float> elements = {1};
	src2.set_data(elements);

	vector<int> dims3;
	Tensor dst = Tensor(dims3);

	vector<float> expected_values(3*3*3, 1);

	TMATH_STATUS status = tadd(src1, src2, dst);

	ASSERT_EQ(status, TMATH_SUCCESS);
	// vector<float> temp(27,1);
	// dst.set_data(temp);
	ASSERT_EQ(*dst.get_data(), expected_values);
}
// TEST_F(TENSOR_UNITTEST, SCALING){
// 	ASSERT_EQ(1,1);
// }
// TEST_F(TENSOR_UNITTEST, MULTIPLICATION){
// 	ASSERT_EQ(1,1);
// }

