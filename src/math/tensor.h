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
		vector<int> dims;
		vector<float> data;
	public:
		// Contructors and destructors
		Tensor(vector<int> dims, float initial_num = 0);
		Tensor(vector<int> dims, vector<float> data);
		~Tensor();
		
		// Getters 
		vector<int> get_dims();
		vector<float> &get_data();

		// Setters
		void set_num_dims(int n);
		void set_dims(vector<int> n);
		void set_data(vector<float>& n);
		void set_data(vector<float>&data, vector<int> dims); 

		// Utility fucntions
		int size();
		int get_num_dims();

		// Operators
		Tensor operator+(Tensor& t);

};

enum op_t{
    ADD = 0,
    MULT = 1
};

#endif
