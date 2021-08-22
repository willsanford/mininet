#ifndef TENSOR_MATH_H
#define TENSOR_MATH_H

#include "tensor.h"

enum TMATH_STATUS{
    TMATH_FAILURE = 0,
    TMATH_SUCCESS = 1
};


/*
    Math library functions
*/
TMATH_STATUS tensor_mult  (Tensor *src1, Tensor *src2, Tensor *dst);
TMATH_STATUS tensor_add(Tensor *src, int add, bool mask, Tensor *mask_val = nullptr);


#endif