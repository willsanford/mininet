#include <cstdlib>
#include <vector>
#include <algorithm>
#include "tensor.h"
#include "tensor_math.h"

using std::vector;
/* Tensors must be of the following shape
    shape(src1) = a_1 x b_1 x c_1 x ... n_1 x dim_1 x dim_2
    shape(src2) = a_2 x b_2 x c_2 x ... n_2 x dim_2 x dim_3
   Where for the x_i dimensions, they must be equal or one of them must be one or non existent. The
     dimension that is one/does not exist will be cast along the other dimension. 
   The output tensor will be of the following shape
    shape(dst) = max(a_1, a_2) x max(b_1, b_2) ... max(n_1, n_2) x dim_1 x dim_3
*/
TMATH_STATUS tensor_mult(Tensor *src1, Tensor *src2, Tensor *dst){
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

/*
    Add a constant to all the elements of a tensor covered by the mast
*/
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