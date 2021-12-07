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
    vector<T> data2 = broadcast_data(src2.get_data(), src2.get_dims(), src1.get_dims());
    vector<T> data1 = src1.get_data();
    vector<T> out_data(src1.size());

    for (int i; i < src1.size(); i++){
        out_data[i] = data1[i] + data2[i];
    }   
    dst.set_data(out_data);
    return TMATH_SUCCESS;
};

template TMATH_STATUS tadd<float>(Tensor<float>& src1, Tensor<float>& src2, Tensor<float>& dst);