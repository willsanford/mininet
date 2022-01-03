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
		vector<Tensor<T>> biases;

		vector<int> layer_sizes;

		std::string act_function;

	public:
		Net(int input_size, 
			int output_size,
			vector<int> hidden_layer_sizes,

			// Turn this into a function handle eventually
			std::string act_function);
		~Net();


		/*!
			* run
			* @brief Run the inputs through the network to get the .
			*
			*/
		Tensor<T> run(Tensor<T>& input, int batch_size);


		// TODO: generate gradient descent, apply gradient descents
};

#endif
