/*
 * tensor.cpp
 *
 *  Basic tensor class.
 *
 * Author: Will Sanford
 * Date: Aug 19, 2021
 */
#include <cstdlib>
#include <iostream>
#include <vector>
#include "tensor.h"
#include "core.h"

using std::vector;
// Tensor Contructor
Tensor::Tensor(vector<int> dims, float initial_num){
	// Set the number of dimensions and the actual dimensions
	set_dims(dims);

	// Declare all the data points and initialize to
	int num_el = vector_product(dims);

	vector<float> data(num_el, initial_num);
	set_data(data);
};

Tensor::Tensor(vector<int> dims, vector<float> data){
	// Set the number of dimensions and the actual dimensions
	set_dims(dims);
	set_data(data);
}
Tensor::~Tensor(){
	// delete dims;
	// delete data;
}

// Getters

vector<int> Tensor::get_dims(){
	return dims;
}
vector<float>& Tensor::get_data(){
	return data;
}

// setters
void Tensor::set_dims(vector<int> n){
	dims = n;
}
void Tensor::set_data(vector<float>& n){
	data = n;
}
void Tensor::set_data(vector<float>& n, vector<int> dims){
	data = n;
	set_dims(dims);
}

// Utility Functions
int Tensor::size(){
	return data.size();
}
int Tensor::get_num_dims(){
	return dims.size();
}


//
// Tensor Tensor::operator+=(const Tensor& t){
// 	vector<int> dst_dims;
// 	broadcast(*this, t, dst_dims, ADD)
// 	dst = Tensor(dst_dims)
// 	vector<float> dst_data(dst.get_num_el(), 2);
// 	dst.set_data(dst_data);
// 	return dst;

// }

Tensor Tensor::operator+(Tensor& t){
	vector<float> new_base = broadcast_data(t.get_data(), t.get_dims(), dims);
	vector<float> new_data(data.size(), 0);
	for (int i = 0; i < data.size(); i++ ){
		new_data[i] = new_base[i] + data[i];
	}
    Tensor* out = new Tensor;
    *out = Tensor(dims, new_data);
	return *out;
}
