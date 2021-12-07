#ifndef CORE_H
#define CORE_H


#include <cstdlib>
#include <vector>
#include "logs.h"

using std::vector;

// Broadcasting functions
int check_broadcast_dims(vector<int> &a, vector<int> &b);

vector<int> broadcast_dims(vector<int> &a, vector<int> &b);

template<class T> 
vector<T> broadcast_data(vector<T> input_data, vector<int> input_dims, vector<int> output_dims);

// Utility Functions
int vector_product(vector<int> input);




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

#endif