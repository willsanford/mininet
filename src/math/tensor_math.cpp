#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "logs.h"
#include "tensor.h"
#include "tensor_math.h"

using std::vector;
using std::string;
/**
    Broadcast the dimensions of two tensors to a destination. Casting will be different for multiplication and addition operations.
    Broadcasting general
        broadcasting two tensors of shape
            t1 = a_n x a_n-1 x .. x a_2 x a_1
            t2 = b_n x b_n-1 x .. x b_2 x b_1
        will produce a tensor of shape
            t3 = max(a_n, b_n) x ... x max(a_1, b_1)
        Only three cases are valid. Either a_n and b_n are equal, or one (or both)
        are 1, or one of them does not exist

        Examples
        t1 = 3x3x3
        t2 = 1x3
        t3 = 3x3x3

        t1 = 3x2x3
        t2 = 1x3x3
        t3 = ERROR
    Breaodcasting Multiplication
*/

TMATH_STATUS broadcast(Tensor& src1, Tensor& src2, vector<int>& dst, op_t op){
    vector<int> src1_dims = *src1.get_dims();
    vector<int> src2_dims = *src2.get_dims();
    int src1_n = src1.get_num_dims();
    int src2_n = src2.get_num_dims();

    // Create the output vector that is the max of the other vectors
    vector<int> dst_dims(std::max(src1_n, src2_n), 0);
    
    // create two temporary vectors to be used in calculation
    vector<int> temp1 = src1_dims;
    vector<int> temp2 = src2_dims;

    // Ensure that the number of dimensions in either array is the same
    if (src1_n - src2_n > 0){
        // Fill in non existent dimensions of temp2 with 1s
        for(int c = 0; c < src1_n - src2_n; c++){
            temp2.insert(temp2.begin(), 1);
        }
    }else if (src1_n - src2_n < 0){
        // Fill in non existent dimensions of src1 with 1s
        for(int c = 0; c < src2_n - src1_n; c++){
            temp1.insert(temp1.begin(), 1);
        }
    }

    switch(op){
        case ADD:
            for (int i = 0; i < dst_dims.size(); i++){ 
                if (temp1[i] == 1){
                    dst_dims[i] = temp2[i];
                }else if (temp2[i] == 1){
                    dst_dims[i] = temp1[i];
                }else if (temp1[i] != temp2[i]){
                    #ifdef LOGGING
                    log("Trying to broadcast tensors of incompatable sizes", ERROR);
                    #endif
                    return TMATH_FAILURE;
                }else{
                    dst_dims[i] = temp1[i];
                }
            }
            break;

        case MULT:
            break;
    }
    dst = dst_dims;
    return TMATH_SUCCESS;
}
/**
    @brief Tensors must be of the following shape
    shape(src1) = a_1 x b_1 x c_1 x ... n_1 x dim_1 x dim_2
    shape(src2) = a_2 x b_2 x c_2 x ... n_2 x dim_2 x dim_3
   Where for the x_i dimensions, they must be equal or one of them must be one or non existent. The
     dimension that is one/does not exist will be cast along the other dimension. 
   The output tensor will be of the following shape
    shape(dst) = max(a_1, a_2) x max(b_1, b_2) ... max(n_1, n_2) x dim_1 x dim_3
*/
TMATH_STATUS tmult(Tensor *src1, Tensor *src2, Tensor *dst){
    // Dimension preprocessing 
    /* Casting types
        0 : Even dimensions
        1 : Cast 1 to 2
        2 : Cast 2 to 1
        3 : Cast 1 to 2 and treat 1 (does not exist) as 1
        4 : Cast 2 to 1 and treat 2 (does not exist) as 2
    */

    // Create casting information and output matrix dimensions
    // int dst_num_dims = max(src1->get_num_dims(), src2->get_num_dims());
    
    // int* casting = (int *) malloc()
    return TMATH_SUCCESS;
}
/**
    Multiply every value in a tensor by
*/
TMATH_STATUS tmult_const(Tensor *src, float add){
    return TMATH_SUCCESS;
} 
/**
    Add a single constant to all the elements of a tensor that correspond to non zero elements in the mask tensor
*/  
TMATH_STATUS tmult_const_mask(Tensor *src, float add, Tensor *mask){
    return TMATH_SUCCESS;
}
/**
    Add two tensors. Broadcast src2 onto src1 to create dst
*/
TMATH_STATUS tadd(Tensor& src1, Tensor& src2, Tensor& dst){
    // Get the output dimensions
    vector<int> dst_dims;
    // Broadcast
    if (!broadcast(src1, src2, dst_dims, ADD)){
        return TMATH_FAILURE;
    }
    Tensor output_tensor = Tensor(dst_dims);

    vector<float> src1_d = *src1.get_data();
    vector<float> src2_d = *src2.get_data();
    vector<float> dst_data = *dst.get_data();

    // Get the number of elements in the broadcasted tensor. Will be used to loop
    int max_el = src1.get_num_el();
    int count = 0;

    for (size_t i = 0; i < dst_data.size(); i++){
        std::cout << dst_data[i] << std::endl;
    }

        // // Add the values and move the pointers forward
        // std::cout << *src1_p << std::endl;

        // std::cout << "hesdlkjshkj" << std::endl;

        // *dst_p = *src1_p + *src2_p;

        // dst_p++;
        // src1_p++;
        // src2_p++;
        // // Reset the loop if need be.
        // if (count++ >= max_el) {
        //     src2_p = src2.get_first_p();
        //     count = 0;
        // }

    dst.set_data(dst_data);
    return TMATH_SUCCESS;
}
/**
    Add a single constant to all the elements of a tensor
*/
TMATH_STATUS tadd_const(Tensor *src, float add){

    return TMATH_SUCCESS;
} 
/**
    Add a single constant to all the elements of a tensor that correspond to non zero elements in the mask tensor
*/  
TMATH_STATUS tadd_const_mask(Tensor *src, float add, Tensor *mask){
    return TMATH_SUCCESS;
}