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
// Tensor Contructors

// Blank Constructors
template<class T>
Tensor<T>::Tensor(){

}

template<class T>
Tensor<T>::Tensor(vector<int> dims){
	set_dims(dims);
		// Declare all the data points and initialize to
	int num_el = vector_product(dims);

	vector<T> data(num_el);
	set_data(data);
}



template<class T>
Tensor<T>::Tensor(vector<int> dims, T fill_value){
	// Set the number of dimensions and the actual dimensions
	set_dims(dims);

	// Declare all the data points and initialize to
	int num_el = vector_product(dims);

	vector<T> data(num_el, fill_value);
	set_data(data);
};


template<class T>
Tensor<T>::Tensor(vector<int> dims, vector<T> data){
	// Set the number of dimensions and the actual dimensions
	set_dims(dims);
	set_data(data);
}

template<class T>
Tensor<T>::~Tensor(){
	// delete dims;
	// delete data;
}

// Getters
template<class T>
vector<int> Tensor<T>::get_dims(){
	return dims;
}
template<class T>
vector<T>& Tensor<T>::get_data(){
	return data;
}

// setters
template<class T>
void Tensor<T>::set_dims(vector<int> n){
	dims = n;
}


template<class T>
void Tensor<T>::set_data(vector<T>& n){
	data = n;
}

template<class T>
void Tensor<T>::set_data(vector<T>& n, vector<int> dims){
	data = n;
	set_dims(dims);
}

// Utility Functions
template<class T>
int Tensor<T>::size(){
	return data.size();
}
template<class T>
int Tensor<T>::get_num_dims(){
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

template class Tensor<int>;
template class Tensor<float>;
