#ifndef CORE_H
#define CORE_H


#include <cstdlib>
#include <vector>

using std::vector;

// Broadcasting functions
int check_broadcast_dims(vector<int> &a, vector<int> &b);
vector<int> broadcast_dims(vector<int> &a, vector<int> &b);
vector<float> broadcast_data(vector<float> input_data, vector<int> input_dims, vector<int> output_dims);

// Utility Functions
int vector_product(vector<int> input);



#endif