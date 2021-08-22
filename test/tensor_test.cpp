#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "tensor.h"
#include "tensor_math.h"

using std::vector;
class TENSOR_UNITTEST : public ::testing::Test{
	protected:
		virtual void SetUp(){
			// Define the 3x3x3 matrix used in testing
			vector<int> *dims = new vector<int>(tensor_1_num_dims);
			dims->assign(tensor_1_num_dims, tensor_1_single_dim);

			tensor1 = new Tensor(dims);

			for (int i = 0; i < tensor1->get_data()->size(); i++){

			}
			for(auto element  = tensor1->get_data()->begin(); element  != tensor1->get_data()->end(); ++element){
				// Make all three batches of the 3x3 tensors the same values
				int index = element - tensor1->get_data()->begin();
				*element = tensor_1_values[index % 9];
			}

		}
		virtual void TearDown(){
			delete tensor1;
		}
	
	Tensor *tensor1;
	int tensor_1_num_el = 27;
	int tensor_1_single_dim = 3;
	int tensor_1_num_dims = 3;
	float tensor_1_values[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
};	

TEST_F(TENSOR_UNITTEST, VALUES){

	// Check that the getters work properly
	ASSERT_EQ(tensor1->get_num_dims(), 3);
	ASSERT_EQ(tensor1->get_num_el(), tensor_1_num_el);
	for(auto element = tensor1->get_dims()->begin(); element != tensor1->get_dims()->end(); ++element){
		ASSERT_EQ(*element, tensor_1_single_dim);
	}
	for(auto element = tensor1->get_data()->begin(); element != tensor1->get_data()->end(); ++element){
		int index = element - tensor1->get_data()->begin();
		ASSERT_EQ(*element, tensor_1_values[index%9]);
	}
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

