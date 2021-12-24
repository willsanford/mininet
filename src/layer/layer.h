/*
 * layer.h
 *
 * Basic Layer class header
 *
 * Author: Will Sanford
 * Date: Aug 19, 2021
 */
#ifndef LAYER_H
#define LAYER_H

#include <cstdlib>
#include <vector>
#include "tensor.h"

using std::vector;

/*! 
 *  \brief Layer class
 *
 *  Longer description of the tensor should be put here
 *  
 */
template<class T>
class Layer{
	private:
        int nodes;
        T bias;
        Tensor<T> weights;
     
	public:
		/*!
		* Constructs a deafult Layer object.
		* @brief Creates a deafult Layer with no data associated with it
		*/
		Layer();
g   
	public:
		/*!
		* Constructs a deafult Layer object.
		* @brief Creates a deafult Layer with no data associated with it
		*/
		Layer();

        /*!
        * Default destructor
        * @brief Creates a default destructor
        */
};

#endif
