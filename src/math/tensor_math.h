#ifndef TENSOR_MATH_H
#define TENSOR_MATH_H
#include "tensor.h"

enum TMATH_STATUS{
    TMATH_FAILURE = 0,
    TMATH_SUCCESS = 1
};

enum op_t{
    ADD = 0,
    MULT = 1
};

vector<int> const_dims(1,0);
Tensor NULL_TENSOR = Tensor(const_dims);

/*
    CPU dependant Math library functions
*/
TMATH_STATUS broadcast(Tensor& src1, Tensor& src2, vector<int>& dst, op_t op = ADD);
TMATH_STATUS tmult(Tensor *src1, Tensor *src2, Tensor *dst);
TMATH_STATUS tmult_const(Tensor *src, float add);
TMATH_STATUS tmult_const_mask(Tensor *src, float add, Tensor *mask);
TMATH_STATUS tadd(Tensor& src1, Tensor& src2, Tensor& dst, bool mask_b = false);
TMATH_STATUS tadd_const(Tensor *src, float add);
TMATH_STATUS tensor_mult  (Tensor *src1, Tensor *src2, Tensor *dst);

/*
    CUDE dependant Math library functions
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