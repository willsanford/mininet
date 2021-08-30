/*
 * tensor.h
 *
 * Basic tensor class header
 *
 * Author: Will Sanford
 * Date: Aug 19, 2021
 */
#ifndef TENSOR_H
#define TENSOR_H

#include <cstdlib>
#include <vector>

using std::vector;
class Tensor{
	private:
		int num_dims;
		int num_el;
		vector<int> *dims;
		vector<float> *data;
	public:
		// Contructors and destructors
		Tensor(vector<int>& dims, float initial_num = 0);
		~Tensor();
		// Getters 
		int get_num_dims();
		int get_num_el();
		vector<int>* get_dims();
		vector<float> *get_data();

		// Setters
		void set_num_dims(int n);
		void set_num_el(int n);
		void set_dims(vector<int>& n);
		void set_data(vector<float>& n);
	
		// Other functions
		// returns the pointer to the first element of the element
		float* get_first_p();
};

#endif
