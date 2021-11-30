#include "core.h"

using std::vector;

int check_broadcast(vector<int> &a, vector<int> &b){
    // Get the length of the smaller array and larger array
    vector<int> small;
    vector<int> large;
    if (a.size() > b.size()){
        large = a;
        small = b
    }else{
        large = b;
        small = a;
    }

    // Loop through the elements of the smaller array and right most elements of the larger array
    for (int i = 0; i < small.size(); i++){
        // Check if everything these arrays check out.
    }
    // Fill in the dimesnions of the smaller array with ones
    std::vector<int> out(std::max(a.size(), b.size()), 0);


    
    int dif = a.size() - b.size();
    if (dif > 0){
        // Fill in non existent dimensions of temp2 with 1s
        for(int c = 0; c < dif; c++){
            b.insert(b.begin(), 1);
        }
    }else if (dif < 0){
        // Fill in non existent dimensions of src1 with 1s
        for(int c = 0; c < -dif; c++){
            a.insert(a.begin(), 1);
        }
    }

    // Check if the arrays are compatable
}
vector<int> broadcast(vector<int> &a, vector<int> &b){
    // create the output vector
    std::vector<int> out(std::max(a.size(), b.size()), 0);

    // Fill in the dimensions of the smaller array with ones
    int dif = a.size() - b.size();
    if (dif > 0){
        // Fill in non existent dimensions of temp2 with 1s
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
