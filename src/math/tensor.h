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

/*! 
 *  \brief Tensor class
 *
 *  Longer description of the tensor should be put here
 *  Currently Supported Data types:
 *  float
 *  
 */
template<class T>
class Tensor{
	private:
		int num_dims;
		int num_el;
		vector<int> dims;
		vector<T> data;
	public:
		/*!
		* Constructs a deafult Tensor object.
		* @brief Creates a deafult tensor object with no data or dimensions asscociated with it 
		*/
		Tensor();

		/*!
		* Constructs a Tensor object with dimensions.
		* @brief Creates a deafult tensor object with no data or dimensions asscociated with it\ 
		* @param dims the dimensions of the constructed tensor.
		*/
		Tensor(vector<int> dims);
		
		/*!
		* Constructs a Tensor object with dimensions and a default fill value.
		* @brief Creates a deafult tensor object with no data or dimensions asscociated with it 
		*/
		Tensor(vector<int> dims, T fill_value);
		
		/*!
		* Constructs a Tensor with the given dimensions and data.
		* @brief Creates a deafult tensor object with no data or dimensions asscociated with it 
		*/
		Tensor(vector<int> dims, vector<T> data);

		/*!
		* Descturcts the current tensor.
		* @brief currently does nothing
		*/
		~Tensor();
		 
		/*!
		* @brief Get the dimensions of the tensor.
		* @return A vector that contains teh dimensions of the tensor.
		*/
		vector<int> get_dims();

 		/*!
		* @brief Get a reference to the data contained in the Tensor.
		* @return A reference to the data contained in the Tensor.
		*/
		vector<T> &get_data();

		
		/*!
		* @brief Set the dimensions of the Tensor.
		* @param n A vector of ints that will be the new dimensions of the Tensor
		* @returns void
		* Should only be used when the structure of the accompanying data is new. This will commonly be used if a new shape is needed
		*/
		void set_dims(vector<int> n);
		
		/*!
		* @brief Set the data of the Tensor.
		* @param data A vector of type T that will be set as the new data of the tensor
		* @returns void
		*/
		void set_data(vector<T>&data);
		
		/*!
		* @brief Set new dimensions and data for the tensor.
		* @param data A vector of type T that will be set as the new data of the Tensor
		* @param dims A vector of ints that will be the new dimensions of the Tensor
		* @returns void
		*/
		void set_data(vector<T>&data, vector<int> dims); 

		/*!
		* @brief Get the size of the data vector
		* @returns returns the number of elements in the data vector
		*/
		int size();

		/*!
		* @brief Get the size of the dimension vector
		* @returns returns the number of elements in the dimension vector
		*/
		int get_num_dims();
};

#endif
