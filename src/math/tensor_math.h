#ifndef TENSOR_MATH_H
#define TENSOR_MATH_H

#include "tensor.h"
#include "core.h"

/*! 
 * \file tensor_math.h
 * \brief Functions for performing operations on tensors
 * Details.
*/


/*! 
* \brief TMATH_STATUS
* An enumeration retruned by tensor math functions to demonstrate if the operation was successful or not
*/
enum TMATH_STATUS{
    TMATH_FAILURE = 1,
    TMATH_SUCCESS = 0
};



/*! \brief Tensor Multiplication
 * @param src1 Left side of the tensor multiplication 
 * @param src2 Right side of the tensor multiplication
 * @param dst Output of the tensor multiplication src1 * src2
 * @returns TMATH_STATUS If the operation is successful, TMATH_SUCCESS is returned, otherwise return TMATH_FAILURE
 * ## Runs the tensor multiplication of src1 * src2 = dst. Assumes
 * ### Notes
 * - Assumes a constructed dst Tensor. This can be set with a default Tensor().
 * - Another note about the function. This is latex $e_{12}$
 * 
 * \f[
 *   |I_2|=\left| \int_{0}^T \psi(t) 
 *            \left\{ 
 *               u(a,t)-
 *               \int_{\gamma(t)}^a 
 *               \frac{d\theta}{k(\theta,t)}
 *               \int_{a}^\theta c(\xi)u_t(\xi,t)\,d\xi
 *            \right\} dt
 *         \right|
 * \f]
 */
template<class T> TMATH_STATUS tmult(Tensor<T> &src1, Tensor<T> &src2, Tensor<T> &dst);



/*! \brief Tensor Addition
 * @param src1 First operand of the addition
 * @param src2 Second operand of the addition
 * @param dst Destination tensor of the sum of the input tensors
  * @returns TMATH_STATUS If the operation is successful, TMATH_SUCCESS is returned, otherwise return TMATH_FAILURE
 *  Runs the operation src1 + src2 = dst. Assumes a constructed dst Tensor. This can be set with a default Tensor().
 */
template<class T> TMATH_STATUS tadd(Tensor<T>& src1, Tensor<T>& src2, Tensor<T>& dst);



// TO Implement
// TMATH_STATUS tmult_const(Tensor *src, float add);
// TMATH_STATUS tmult_const_mask(Tensor *src, float add, Tensor *mask);
// TMATH_STATUS tadd_const(Tensor *src, float add);
// TMATH_STATUS tensor_mult  (Tensor *src1, Tensor *src2, Tensor *dst);

// TODO: enable CUDA compilation

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
