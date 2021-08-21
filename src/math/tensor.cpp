/*
 * tensor.cpp
 *
 *  Basic tensor class.
 *
 * Author: Will Sanford
 * Date: Aug 19, 2021
 */

#include <iostream>
#include <cstdlib>
#include "tensor.h"

// Tensor Contructor 
void Tensor::Tensor(int num_dims, int *dims, float initial_num = 0){
	// Set the number of dimensions and the actual dimensions
	set_num_dims(nu_dims);	
	set_dims(dims)
		
	// Declare all the data points and initialize to
	int data_points = 0;
	for (int i = 0; i < dim_n; i++){
		data_points *= dims[i];
	}
	set_num_el(data_points)
	set_data((float*) std::malloc(data_points * sizeof(float)));
	for (int i = 0; i < data_points; i++){
		data[i] = initial_num;
	}
};

// Tensor printing function
void Tensor::print(){
	std::cout << "Tensor fill this in later" << std::endl;
}
