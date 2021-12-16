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


template<class T>
class Tensor{
	private:
		int num_dims;
		int num_el;
		vector<int> dims;
		vector<T> data;
	public:
		// Contructors and destructors
		Tensor();
		Tensor(vector<int> dims);
		Tensor(vector<int> dims, T fill_value);
		Tensor(vector<int> dims, vector<T> data);
		~Tensor();
		
		// Getters 
		vector<int> get_dims();
		vector<T> &get_data();

		// Setters
		void set_num_dims(int n);
		void set_dims(vector<int> n);
		void set_data(vector<T>& n);
		void set_data(vector<T>&data, vector<int> dims); 

		// Utility fucntions
		int size();
		int get_num_dims();

		// Operators
		Tensor operator+(Tensor& t);

};

#endif
