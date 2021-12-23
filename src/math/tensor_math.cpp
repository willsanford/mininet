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
    // Check if we can multiply these vectors
    if(!check_multiplication_dims(src1.get_dims(), src2.get_dims())){
        return TMATH_FAILURE;
    }

    // Take the case where there are no broadcastable dimensions and run the matrix multiplication
    if ((src1.get_dims().size() == 2) & (src2.get_dims().size() == 2)){
        vector<T> out_data = mmult<T>(src1.get_data(), src2.get_data(), src1.get_dims()[0], src1.get_dims()[1], src2.get_dims()[1]);
        dst.set_data(out_data);
        return TMATH_SUCCESS;
    }

    // Get the size of the broadcastable dimensions of the inputs and outputs
    vector<int> bdims_out = slice<int>(dst.get_dims(), 0, dst.get_dims().size()-3);
    int factor_out = vector_product(bdims_out);

    int factor_1 = 1;
    int factor_2 = 1;


    if (src1.get_dims().size() > 2){
        vector<int> bdims_1 = slice<int>(src1.get_dims(), 0, src1.get_dims().size()-3);
        factor_1 = vector_product(bdims_1);
    }


    if (src2.get_dims().size() > 2){
        vector<int> bdims_2 = slice<int>(src2.get_dims(), 0, src2.get_dims().size()-3);
        factor_2 = vector_product(bdims_2);
    }

    // Get base multiplication dimensions
    int m = src1.get_dims().end()[-2];
    int n = src1.get_dims().end()[-1];
    int p = src2.get_dims().end()[-1];


    // Get the size of the multiplication dimensions
    int left_size = m * n;
    int right_size = n * p;
    int out_size = m * p;

    vector<T> data1 = src1.get_data();
    vector<T> data2 = src2.get_data();

    // Declare the output vector
    vector<T> output_data(vector_product(dst.get_dims()));
    // Run all the matrix multriplications
    for (int i = 0; i < factor_out; i++){
        // Get the appropirate slices of the inputs that will correspond to this matrix in the output
        int left_index = i % factor_1;
        int left_start = left_index * left_size;
        int left_end = (left_index + 1) * left_size - 1;
        vector<T> left_slice = slice<T>(data1, left_start, left_end);

        int right_index = i % factor_2;
        int right_start = right_index * right_size;
        int right_end = (right_index + 1) * right_size - 1;
        vector<T> right_slice = slice<T>(data2, right_start, right_end);

        // Run the matrix multiplication
        vector<T> out_section = mmult<T>(left_slice, right_slice, m, n, p);
        // Transcribe this data into the correct part of the output
        for (int j = 0; j < out_section.size(); j++){
            output_data[(i * out_size) + j] = out_section[j];
        }
    }

    dst.set_data(output_data);
    return TMATH_SUCCESS;
}


template<class T>
TMATH_STATUS tadd(Tensor<T>& src1, Tensor<T>& src2, Tensor<T>& dst){
    // Check that the tensors are able to be broadcast and determine the output dimension

    if (!check_broadcast_dims(src1.get_dims(), src2.get_dims())){
        return TMATH_FAILURE;
    }

    vector<int> output_dims = broadcast_dims(src1.get_dims(), src2.get_dims());
    int output_size = vector_product(output_dims);
    vector<T> output_data(output_size);

    int src1_size = src1.size();
    int src2_size = src2.size();

    vector<T> src1_data = src1.get_data();
    vector<T> src2_data = src2.get_data();

    for (int i = 0; i < output_size; i++){
        output_data[i] = src1_data[i % src1_size] + src2_data[i % src2_size];
    }

    dst.set_data(output_data, output_dims);
    return TMATH_SUCCESS;
}

template<class T>
TMATH_STATUS tconst_op(Tensor<T>& src, T operand, OP op, bool inplace, Tensor<T>& dst){
    vector<T> src_data = src.get_data();
    vector<T> new_data(src.size(), 0);
    for (int i = 0; i < src.size(); i++){
        switch(op){
            case ADD:
                new_data[i] = src_data[i] + operand;
                break;
            case MULT:
                new_data[i] = src_data[i] * operand;
                break;

            // Default to addition for now
            default:
                new_data[i] = src_data[i] + operand;
                break;
        }
    }
    // Place the new data where it is supposed to go
    if (inplace){
        src.set_data(new_data);
    }else{
        dst.set_data(new_data, src.get_dims());
    }
    return TMATH_SUCCESS;
}

template<class T>
TMATH_STATUS telwise_op(Tensor<T>& src1, Tensor<T>& src2, OP op, bool inplace, Tensor<T>& dst){
    return TMATH_SUCCESS;

}

// Template Declarations
template TMATH_STATUS tadd(Tensor<float> &src1, Tensor<float>& src2, Tensor<float>& dst);
template TMATH_STATUS tmult(Tensor<float> &src1, Tensor<float> &src2, Tensor<float> &dst);
template TMATH_STATUS tconst_op(Tensor<float>& src, float operand, OP op, bool inplace, Tensor<float>& dst);
template TMATH_STATUS telwise_op(Tensor<float>& src, Tensor<float>& src2, OP op, bool inplace, Tensor<float>& dst);
