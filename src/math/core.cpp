#include <cstdlib>
#include <ostream>
#include <iostream>
#include "core.h"
#include "logs.h"
using std::vector;


// Broadcasting

'''
Check that the two input dimension vectors can be broadcasted together.
'''
int check_broadcast_dims(const vector<int> &a, const vector<int> &b){
    // determine which array has more values
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

'''
Check that the tensor multiplication of a * b will work.
'''
int check_multiplication_dims(const vector<int> &a, const vector<int> &b){
    // Both tensors must have a size of at least 2 to be valid
    if (a.size() < 2 | b.size_() < 2){
        return 1;
    }

    // Check that the base two dimensions are valid under matrix multiplication
    if (a.back() != b.end()[-2]){
        return 1;
    }

    // If this is true and either vector has no other dimensions past the first two, then the multiplication is valid. Otherwise, run
    if (a.size() == 2 | b.size() == 2){
        return 0;
    }

    // Otherwise we will run the check dimensions functions on the rest of the dimensions   
    vector<int> new_a = slice<int>(a, 0, a.size()-2);
    vector<int> new_b = slice<int>(b, 0, b.size()-2);

    return check_braodcast_dims(new_a, new_b);


}
vector<int> broadcast_dims(vector<int> &a, vector<int> &b){
    // create the output vector
    vector<int> out(std::max(a.size(), b.size()), 0);

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

// Utility
int vector_product(vector<int> input){
    int out = 1;
    for (size_t i = 0; i < input.size(); i++){
        out = out * input[i];
    }
    return out;
}