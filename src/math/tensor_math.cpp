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

// ASSUMES A PROPERLY BROADCASTED DEST TENSOR
template<class T> 
TMATH_STATUS tadd(Tensor<T>& src1, Tensor<T>& src2, Tensor<T>& dst){

    // Check which order the tensors should be broadcasted in

    // src2 braodcasted to src1
    if (check_broadcast_dims(src1.get_dims(), src2.get_dims())){
        vector<T> data2 = broadcast_data(src2.get_data(), src2.get_dims(), src1.get_dims());
        vector<T> data1 = src1.get_data();
        vector<T> out_data(src1.size());


        for (int i = 0; i < src1.size(); i++){
            out_data[i] = data1[i] + data2[i];
        }   
        dst.set_data(out_data);
        return TMATH_SUCCESS;

    // src1 broadcasted to src2
    }else if(check_broadcast_dims(src2.get_dims(), src1.get_dims())){
        vector<T> data1= broadcast_data(src1.get_data(), src1.get_dims(), src2.get_dims());
        vector<T> data2 = src2.get_data();
        vector<T> out_data(src2.size());

        for (int i = 0; i < src2.size(); i++){
            out_data[i] = data1[i] + data2[i];
        }   

        dst.set_data(out_data);
        return TMATH_SUCCESS;
    }else{
        return TMATH_FAILURE;
    }
};

// template TMATH_STATUS tadd<float>(Tensor<float>& src1, Tensor<float>& src2, Tensor<float>& dst);
template TMATH_STATUS tadd(Tensor<float>& src1, Tensor<float>& src2, Tensor<float>& dst);
template TMATH_STATUS tadd(Tensor<int>& src1, Tensor<int>& src2, Tensor<int>& dst);