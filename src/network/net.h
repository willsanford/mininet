/*
 * layer.h
 *
 * Basic Layer class header
 *
 * Author: Will Sanford
 * Date: Aug 19, 2021
 */
#ifndef NET_H
#define NET_H

#include <cstdlib>
#include <vector>
#include <string>
#include "tensor.h"
using std::vector;

/*!
 *  \brief Network class
 *      
 *  Longer description of the network should be put here
 *
 */
template<class T>
class Net{
	private:
		vector<Tensor<T>> weights;
		vector<Tensor<T>> activions;
		vector<T> biases;

		Tensor<T> last_result;

		int num_hidden_layers

		vector<int> output_size;

	public:
		Net(vector<int> input_size, 
				vector<int> output_size,
				int num_hidden_layers, 
				int hidden_layer_size,
				string activation_function);

		~Net();


		/*!
			* run
			* @brief Run the inputs through the network to get the .
			*
			*/
		Tensor<T> run(Tenosr<T> input, int batch_size);


		// TODO: generate gradient descent, apply gradient descents
};

#endif
