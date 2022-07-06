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
bool check_broadcast_dims(const vector<int> &a, const vector<int> &b);
vector<int> broadcast_dims(const vector<int> &input1, const vector<int> &input2);
template<class T>  vector<T> broadcast_data(vector<T> input_data, vector<int> input_dims, vector<int> output_dims);
bool check_multiplication_dims(const vector<int> &a, const vector<int> &b);


// Utility Functions
int vector_product(vector<int> input);
template<class T> vector<T> slice(const vector<T>, int a, int b);
template<class T> void mmult(const vector<T>& src1, const vector<T>& src2, vector<T>& dst, int m, int n, int p);

// Template Implementations
template<class T>
vector<T> broadcast_data(vector<T> input_data, vector<int> input_dims, vector<int> output_dims){
    if (!check_broadcast_dims(input_dims, output_dims)){
        log("Broadcast Data Failied", ERROR);
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

/**
 * @brief Matrix Multiplication
 *
 * @tparam T Input type
 * @param src1 Left Operand
 * @param src2 Right Operand
 * @param m Rows of left Operand
 * @param n Columns of left operand
 * @param p Columns of right operand
 * @return vector<T> Result of the matrix multiplication
 */

// dst[j + i * p] = dst[i][j]
// src1[k + i * m] = dst[i][k]
// src2[j + k * p] = dst[k][j
#define BLOCK 16
template<class T>
vector<T> mmult(const vector<T> &src1, const vector<T> &src2, int m, int n, int p){
    vector<T> out(m*p, 0);
    // Loop through all the elements in the output
    for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            T sum = 0;
            for (int k = 0; k < n; k++){
                sum += src1[k + i * m] * src2[j + k * p];
            }
            out[j + i * p] += sum;
        }
    }
    return out;
}

/*
 * Generic template
template<class T>
vector<T> mmult(const vector<T> &src1, const vector<T> &src2, int m, int n, int p){
    vector<T> out(m*p. 0);

    return out;

}
*/


/*
 * V1: Fully n^3 with no concept of memory or caches
 * Time for 1000x1000: 5701377390
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
*/
// template<class T> void mmult(const vector<T>& src1, const vector<T>& src2, vector<T>& dst, int m, int n, int p){


/*
 * V2: no sum no memory
 * time: 9666941542

template<class T>
vector<T> mmult(const vector<T> &src1, const vector<T> &src2, int m, int n, int p){
    vector<T> out(m*p, 0);

    // Loop through all the elements in the output
    for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            // calculate the actual index of the output vector
            // T sum = 0;
            for (int k = 0; k < n; k++){
                int dst_ind = j + i * p;
                int src1_ind = k + i * m;
                int src2_ind = j + k * p;
                out[dst_ind] += src1[src1_ind] * src2[src2_ind];
            }
        }
    }
    return out;
}
 */
// }

#endif
