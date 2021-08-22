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

using std::vector;
// Tensor Contructor
Tensor::Tensor(vector<int> *dims, float initial_num){
	// Set the number of dimensions and the actual dimensions
	set_num_dims(dims->size());
	set_dims(dims);

	// Declare all the data points and initialize to
	int data_points = 1;
	for (auto i = dims->begin(); i != dims->end(); ++i){
		data_points *= *i;
	}

	set_num_el(data_points);
	set_data(new vector<float>(data_points));

	// Populate the tensor with the initial value
	data->assign(num_el, initial_num);
};
Tensor::~Tensor(){
	delete dims;
	delete data;
}

// Getters
int Tensor::get_num_dims(){
	return num_dims;
}

int Tensor::get_num_el(){
	return num_el;
}
vector<int>* Tensor::get_dims(){
	return dims;
}
vector<float>* Tensor::get_data(){
	return data;
}

// Setters
void Tensor::set_num_dims(int n){
	num_dims = n;
}

void Tensor::set_num_el(int n){
	num_el = n;
}
void Tensor::set_dims(vector<int> *n){
	dims = n;
}
void Tensor::set_data(vector<float> *n){
	data = n;
}