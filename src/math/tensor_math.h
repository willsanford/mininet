#ifndef TENSOR_MATH_H
#define TENSOR_MATH_H

#include "tensor.h"
#include "core.h"

enum TMATH_STATUS{
    TMATH_FAILURE = 1,
    TMATH_SUCCESS = 0
};

/*
    CPU dependant Math library functions
*/
// TMATH_STATUS broadcast(Tensor& src1, Tensor& src2, vector<int>& dst, op_t op = ADD);
template<class T> TMATH_STATUS tmult(Tensor<T> &src1, Tensor<T> &src2, Tensor<T> &dst);
// TMATH_STATUS tmult_const(Tensor *src, float add);
// TMATH_STATUS tmult_const_mask(Tensor *src, float add, Tensor *mask);

template<class T> TMATH_STATUS tadd(Tensor<T>& src1, Tensor<T>& src2, Tensor<T>& dst);

// TMATH_STATUS tadd_const(Tensor *src, float add);
// TMATH_STATUS tensor_mult  (Tensor *src1, Tensor *src2, Tensor *dst);

/*
    CUDA dependant Math library functions
    TODO: enable CUDA compilation
*/
// TMATH_STATUS c_broadcast(Tensor *src1, Tensor *src2, vector<int> *dst, string op = "add");
// TMATH_STATUS c_tmult(Tensor *src1, Tensor *src2, Tensor *dst);
// TMATH_STATUS c_tmult_const(Tensor *src, float add);
// TMATH_STATUS c_tmult_const_mask(Tensor *src, float add, Tensor *mask);
// TMATH_STATUS c_tadd(Tensor* src1, Tensor *src2);
// TMATH_STATUS c_tadd_const(Tensor *src, float add);
// TMATH_STATUS c_tadd_const_mask(Tensor *src, float add, Tensor *mask);
// TMATH_STATUS c_tensor_mult  (Tensor *src1, Tensor *src2, Tensor *dst);
// TMATH_STATUS c_tensor_add(Tensor *src, int add, bool mask, Tensor *mask_val = nullptr);
#endif
