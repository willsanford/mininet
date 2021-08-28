#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
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
    vector<int>* dims1 = src1.get_dims();
    int dim1 = src1.get_num_dims();
    vector<int>* dims2 = src2.get_dims();
    int dim2 = src2.get_num_dims();
    // Create the output vector that is the max of the other vectors
    vector<int> dst_dims(std::max(dim1, dim2), 0);

    switch(op){
        case add:
            for (int dim: dst_dims){
                dim = 4;
            }
            for (int dim: dst_dims){
                printf("%d\n", dim);
            }
            // for (int i = 0; i < dst_dims_n; i++){
            //     // This dimenstion does not exist in 1
            //     if ((dst_dims_n - i) > dim1){  
            //         dst_dims[i] = dims2[i];
            //     // This dimension does not exist in 2
            //     }else if((dst_dims_n - i) > dim2){
            //         dst_dims[i] = dims1[i];
            //     // The dimensions are equal
            //     }else if(dims1[i] == dims2[i]){
            //         dst_dims[i] = dims1[i];
            //     // The first dimension is 1, so broadcast the other
            //     }else if(dims1[i] == 1){
            //         dst_dims[i] = dims2[i];
            //     // The second dimention is 1, so broadcast the other
            //     }else if(dims2[i] == 1){
            //         dst_dims[i] = dims1[i];
            //     }else{
            //         return TMATH_FAILURE;
            //     }
            // }
            break;

        case mult:
            break;
    }
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
    Add two tensors.
*/
TMATH_STATUS tadd(Tensor* src1, Tensor *src2){
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
// TODO : Update to use std::vector
TMATH_STATUS tensor_add(Tensor *src, int add, bool mask, Tensor *mask_val){
    // If mask if true, check that the tensor pointer is not null
    if (mask && (mask_val = nullptr)) return TMATH_FAILURE;
    // Check if the mask is valid
    if (mask && (src->get_num_el() != mask_val->get_num_el())) return TMATH_FAILURE;
    
    // Loop through the elements in the soruce tensor
    float* src_addr = &src->get_data()->front();
    float* mask_addr = nullptr;
    if (mask) mask_addr = &mask_val->get_data()->front();
    
    // Run the addition differently depending on if there is a mask
    if (mask){
        for (int i = 0; i < src->get_num_el(); i++){
            if (*mask_addr) *src_addr += add;
            src_addr++;
            mask_addr++;
    }
    }else{
        for (int i = 0; i < src->get_num_el(); i++){
            *src_addr += add;
            src_addr++;
    }
    }
    
    return TMATH_SUCCESS;
}