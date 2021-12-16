#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "logs.h"
#include "core.h"
#include "tensor.h"
#include "tensor_math.h"

using std::vector;

template<class T>
TMATH_STATUS tmult(Tensor<T> &src1, Tensor<T> &src2, Tensor<T> &dst){
    //  Check if we can multiply these vectors
    if(!check_multiplication_dims(src1.get_dims(), src2.get_dims())){
        return TMATH_FAILURE;
    }
    
    // Different cases based on the dimensionality of the tensors
    // CASE 1: Both tensors are matrices
    int src1_dims = src1.get_dims().size();
    int src2_dims = src2.get_dims().size();
    if (src1_dims == 2 & src2_dims == 2){
        vector<T> out_data = mmult<T>(src1.get_data(), src2.get_data(), src1.get_dims()[0], src1.get_dims()[1], src2.get_dims()[1]);
        dst.set_data(out_data);
        return TMATH_SUCCESS;
    }

    // Both case two and three will create two tensors where the last two dimensions are multiplicable and all other dimensions match
    // Both will create a left multiply and a right multiply that are src1 and src2, but properly broadcasted
    Tensor<T> left_mult;
    Tensor<T> right_mult;

    // CASE 2: One input is tensor and the other is a matrix. Broadcast the dimensions of the matrix to the tensor to make it a case 3
    if ((src1_dims > 2 & src2_dims == 2) | (src2_dims > 2 & src1_dims == 2)){
        // Create temporary tensor and matrix labels
        Tensor<T> m;
        Tensor<T> t;
        if (src1_dims == 2){
            m = src1;
            t = src2;
        }else{
            t = src1;
            m = src2;
        }

        // Get all dims that are not the multiplication dims in the larger tensor
        vector<int> b_dims = slice<int>(t.get_dims(), 0, t.get_dims().size()-3);

        // Add these to the multiplication dims in the smaller tensor to get the new dimensions
        vector<int> new_dims = b_dims.insert(b_dims.end(), m.get_dims().begin(), m.get_dims().end());
        
        // Broadcast the data from the matrix into the new tensor
        vector<T> new_data = broadcast_data(m.get_data(), m.get_dims(), new_dims);

        if (src1_dims == 2){
            left_mult = Tensor(new_dims, new_data);
            right_mult = t;
        }else{
            right_mult = Tensor(new_dims, new_data);
            left_mult = t
        }
    
    }else if(src1.get_dims().size() > 2 & src2.get_dims()){
        // Figure this out
    }

    // Get the broadcastable dimensions of both tensors
    vector<int> slice(src1.get_dims(), 0 src.get_dims().end()[-2])
    vector<int> slice(src2.get_dims(),)
    // Broadcast both Tenosrs up to the highest dimensions. If a tensor is already as high as neededm, nothing will happen.

    // Get base multiplication dimensions
    int m = left_mult.get_dims().end[-2];
    int n = left_mult.get_dims().end[-1]; 
    int p = rigth_mult.get_dims().end()[-1];

    int left_size = left_mult.get_dims()[-2] *  left_mult.get_dims()[-1];
    int right_size = right_mult.get_dims()[-2] *  right_mult.get_dims()[-1];

    return TMATH_SUCCESS;       
}



template<class T> 
TMATH_STATUS tadd(Tensor<T>& in1, Tensor<T>& in2, Tensor<T>& dst){
    Tensor<T> src1;
    Tensor<T> src2;
    if (check_broadcast_dims(in1.get_dims(), in2.get_dims())){
        src1 = in1;
        src2 = in2;
    }else if(check_broadcast_dims(in2.get_dims(), in1.get_dims())){
        src1 = in2;
        src2 = in1;
    }else{
        return TMATH_FAILURE;
    }
    
    vector<T> data2 = broadcast_data(src2.get_data(), src2.get_dims(), src1.get_dims());
    vector<T> data1 = src1.get_data();
    vector<T> out_data(src1.size());

    for (int i = 0; i < src1.size(); i++){
        out_data[i] = data1[i] + data2[i];
    }   
    dst.set_data(out_data);
    return TMATH_SUCCESS;
};


// Template Declarations
template TMATH_STATUS tadd(Tensor<float>& src1, Tensor<float>& src2, Tensor<float>& dst);
template TMATH_STATUS tmult(Tensor<float> &src1, Tensor<float> &src2, Tensor<float> &dst);
