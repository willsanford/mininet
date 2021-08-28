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

TEST_F(TENSOR_UNITTEST, VALUES){
	// Create a 3x3 tensor and define its values as 1...9
	vector<int> dims = {3,3};
	Tensor tensor = Tensor(&dims);
	
	vector<float> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	tensor.set_data(&data);

	// Check that the getters work properly
	ASSERT_EQ(tensor.get_num_dims(), 2);
	ASSERT_EQ(tensor.get_num_el(), data.size());
	ASSERT_EQ(*tensor.get_dims(), dims);
	ASSERT_EQ(*tensor.get_data(), data);
	

	// Change values with the setters and see if the data updates correctly
	vector<float> new_data(9, 0);
	tensor.set_data(&new_data);
	ASSERT_EQ(*tensor.get_data(), new_data);
}

TEST_F(TENSOR_UNITTEST, BROADCASTING){
	ASSERT_EQ(1,1);
}		
// TEST_F(TENSOR_UNITTEST, ADDITION){
// 	ASSERT_EQ(1,1);
// }
// TEST_F(TENSOR_UNITTEST, SCALING){
// 	ASSERT_EQ(1,1);
// }
// TEST_F(TENSOR_UNITTEST, MULTIPLICATION){
// 	ASSERT_EQ(1,1);
// }

