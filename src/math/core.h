#ifndef CORE_H
#define CORE_H


#include <cstdlib>
#include <vector>
#include "logs.h"

using std::vector;

enum OP{
    ADD = 0,
    MULT = 1
};

// Broadcasting functions
int check_broadcast_dims(const vector<int> &a, const vector<int> &b);
vector<int> broadcast_dims(vector<int> &a, vector<int> &b);
template<class T>  vector<T> broadcast_data(vector<T> input_data, vector<int> input_dims, vector<int> output_dims);
int check_multiplication_dims(const vector<int> &a, const vector<int> &b);



// Utility Functions
int vector_product(vector<int> input);
template<class T> vector<T> slice(const vector<T>, int a, int b);
template<class T> vector<T> mmult(const vector<T>& src1, const vector<T>& src2, int m, int n, int p);


// Template Implementations
template<class T>
vector<T> broadcast_data(vector<T> input_data, vector<int> input_dims, vector<int> output_dims){
    if (!check_broadcast_dims(input_dims, output_dims)){
        log("Trying to broadcast data to an incompatible type", ERROR);
    }
    
    int out_size = vector_product(output_dims);
    int in_size = vector_product(input_dims);

    vector<T> output_data(out_size, 0);

    for (int i = 0; i < out_size; i++){
        output_data[i] = input_data[i % in_size];
    } 

    return output_data;
}

template<class T> vector<T> slice(const vector<T>input, int a, int b){
    auto start = input.begin() + a;
    auto end = input.begin() + b + 1;
    
    // Get a vector of the correct size
    vector<T> result(b - a + 1);
 
    // Copy in the data
    std::copy(start, end, result.begin());
 
    return result;
}


/*
 Multiply the matrices src1 and src2, where  src1 = [mxn] and src2 = [nxp]
*/
template<class T> vector<T> mmult(const vector<T> &src1, const vector<T> &src2, int m, int n, int p){
    vector<T> out(m*p, 0);

    // Loop through all the elements in the output
    for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            // calculate the actual index of the output vector
            int c = j + i * p;
            T sum = 0;  
            for (int k = 0; k < n; k++){
                sum += src1[k + i * m] * src2[j + k * p];
            }
            out[c] = sum;
        }
    }

    return out;
}
#endif