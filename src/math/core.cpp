#include <cstdlib>
#include <ostream>
#include <iostream>
#include "core.h"
#include "logs.h"
using std::vector;


// Broadcasting
int check_broadcast_dims(vector<int> &a, vector<int> &b){
    // Get the ltength of the smaller array and larger array
    vector<int> small;
    vector<int> large;
    if (a.size() > b.size()){
        large = a;
        small = b;
    }else{
        large = b;
        small = a;
    }

    // Loop through the elements of the smaller array and right most elements of the larger array
    for (int i = 0; i < small.size(); i++){
       int ind_a = small.size() - 1 - i;
       int ind_b = ind_a + (large.size() - small.size());

       // If any of the conditions are not true, then 
       if (!((a[ind_a] == b[ind_b]) | (a[ind_a] == 1) | (b[ind_b] == 1))){
           return 1;
       }
    }
    return 0;
}

vector<int> broadcast_dims(vector<int> &a, vector<int> &b){
    // create the output vector
    std::vector<int> out(std::max(a.size(), b.size()), 0);

    // Fill in the dimensions of the smaller array with ones
    int dif = a.size() - b.size();
    if (dif > 0){
        // Fill in non exisent dimensions of temp2 with 1s
        for(int c = 0; c < dif; c++){
            b.insert(b.begin(), 1);
        }
    }else if (dif < 0){
        // Fill in non existent dimensions of src1 with 1s
        for(int c = 0; c < -dif; c++){
            a.insert(a.begin(), 1);
        }
    }

    // Broadcast the dimensions into the output vector
    for (int i = 0; i < out.size(); i++){
        if (a[i] == 1) out[i] = b[i];
        else out[i] = a[i];
    }   

    return out;
}

vector<float> broadcast_data(vector<float> input_data, vector<int> input_dims, vector<int> output_dims){
    if (!check_broadcast_dims(input_dims, output_dims)){
        log("Trying to broadcast data to an incompatible type", ERROR);
    }
    
    int out_size = vector_product(output_dims);
    int in_size = vector_product(input_dims);

    vector<float> output_data(out_size, 0);

    for (int i = 0; i < out_size; i++){
        output_data[i] = input_data[i % in_size];
    } 

    return output_data;
}

// Utility
int vector_product(vector<int> input){
    int out = 1;
    for (size_t i = 0; i < input.size(); i++){
        out = out * input[i];
    }
    return out;
}

