#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "tensor.h"
#include "core.h"
// #include "tensor_math.h"

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
	vector<float> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	Tensor tensor = Tensor(dims, data);


	// Check that the getters work properly
	ASSERT_EQ(tensor.get_num_dims(), 2);
	ASSERT_EQ(tensor.size(), data.size());
	ASSERT_EQ(tensor.get_dims(), dims);
	ASSERT_EQ(tensor.get_data(), data);


	// Change values with the setters and see if the data updates correctly
	vector<float> new_data(9, 0);
	tensor.set_data(new_data);
	ASSERT_EQ(tensor.get_data(), new_data);
}


// /*********************************************
//  * Broadcasting tests
//  * ******************************************/

/*********************************************
Check that the following broadcasting behaviour works
(3x3x3) + (3x3x3) = (3x3x3)
**********************************************/
TEST_F(TENSOR_UNITTEST, BROADCASTING_1){

	vector<int> dims1 = {3,3,3};
	vector<int> dims2 = {3,3,3};

	vector<int> dst = broadcast_dims(dims1, dims2);

	ASSERT_EQ(dst, dims2);
}

/*********************************************
Check that the following broadcasting behaviour works
(3x1x3) + (3x3x3) = (3x3x3)
*********************************************/
TEST_F(TENSOR_UNITTEST, BROADCASTING_2){

	vector<int> dims1 = {3,1,3};
	vector<int> dims2 = {3,3,3};

	vector<int> dst = broadcast_dims(dims1, dims2);

	ASSERT_EQ(dst, dims2);
}

/*********************************************
Check that the following broadcasting behaviour works
(3x3) + (3x3x3) = (3x3x3)
*****************************************    std::cout << out << std::endl;
*****/
TEST_F(TENSOR_UNITTEST, BROADCASTING_3){

	vector<int> dims1 = {3,3};
	vector<int> dims2 = {3,3,3};

	vector<int> dst = broadcast_dims(dims1, dims2);

	ASSERT_EQ(dst, dims2);
}

/*********************************************
Check that the following broadcasting behaviour works
(1x3x3) + (3x3x3) = (3x3x3)
**********************************************/
TEST_F(TENSOR_UNITTEST, BROADCASTING_4){

	vector<int> dims1 = {1,3,3};
	vector<int> dims2 = {3,3,3};

	vector<int> dst = broadcast_dims(dims1, dims2);

	ASSERT_EQ(dst, dims2);
}

/*********************************************
Check that the following broadcasting behaviour fails
(2x3x3) + (3x3x3) = ERROR
**********************************************/
TEST_F(TENSOR_UNITTEST, BROADCASTING_5){

	vector<int> dims1 = {2,3,3};
	vector<int> dims2 = {3,3,3};

	vector<int> dst = broadcast_dims(dims1, dims2);
	ASSERT_EQ(check_broadcast_dims(dims1, dims2), 1);
	// ASSERT_EQ(dst, dims2);
}

/*********************************************
Check that the following broadcasting behaviour works
				 |-                       -|
[1 2 3]          | [1 2 3] [1 2 3] [1 2 3] |
[4 5 6] (3x3) -> | [4 5 6] [4 5 6] [4 5 5] |  (3X3X3)
[7 8 9]          | [7 8 9] [7 8 9] [7 8 9] |
				 |-                       -|
**********************************************/
TEST_F(TENSOR_UNITTEST, BROADCASTING_6){
	
	vector<int> dims1 = {3,3};
	vector<int> dims2 = {3,3,3};
	vector<float> data1 = {1,2,3,4,5,6,7,8,9};
	vector<float> data2 = {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9};

	ASSERT_EQ(data2, broadcast_data(data1, dims1, dims2));
}



/*********************************************
Check that the following broadcasting behaviour works
				 |-                       -|
[1 2 3]          | [1 2 3] [1 2 3] [1 2 3] |
[4 5 6] (3x3) -> | [4 5 6] [4 5 6] [4 5 5] |  (3X3X3)
[7 8 9]          | [7 8 9] [7 8 9] [7 8 9] |
				 |-                       -|
**********************************************/
TEST_F(TENSOR_UNITTEST, Addition_1){
	
	vector<int> dims1 = {1};
	vector<int> dims2 = {3,3};
	vector<float> data1 = {1};
	vector<float> data2 = {1,2,3,4,5,6,7,8,9};

	vector<float> out_data = {2,3,4,5,6,7,8,9,10};
	Tensor ten1 = Tensor(dims1, data1);
	Tensor ten2 = Tensor(dims2, data2);
	Tensor ten3 = ten2 + ten1;
	ASSERT_EQ(out_data, ten3.get_data());
}