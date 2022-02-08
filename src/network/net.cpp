#include "logs.h"
#include "net.h"
#include "tensor.h"
#include "tensor_math.h"
#include "activations.h"
using std::vector;


template<class T>
Net<T>::Net(int input_size, int output_size, vector<int> hidden_layer_sizes, std::string act_function){
    // Define a default forward pass network
}
template class Net<float>;


template<class T> 
Tensor<T> Net<T>::run(Tensor<T>& input, int batch_size){
    // Declare a new activations vector<Tensor<T>> and declare the internal tensors
    vector<Tensor<T>> new_activations(layer_sizes.size());
    for(int i = 0; i < new_activations.size(); i++){
        // Layers are single dimensional tensors
        vector<int> layer_size = {layer_sizes[i]};
        Tensor<T> layer(layer_size, 0);
        new_activations[i] = layer;
    }

    // Set the first layer of activations as the input
    new_activations[0] = input;

    TMATH_STATUS success;

    // The number of weights is one less than the number of activations,
    for (int layer_num = 0; layer_num < weights.size(); layer_num++){

        // Multiply the weights by the activations to get the base of the next layer
        success = tmult(weights[layer_num], new_activations[layer_num], new_activations[layer_num+1]);
        if (success != TMATH_SUCCESS){
            log("Tensor multiplication failed in network run", ERROR);
        }
    
        // Run each element in the output   
        success = telwise_op<T>(new_activations[layer_num+1], biases[layer_num], ADD);
        if (success != TMATH_SUCCESS){
            log("Bias addition failed in network run", ERROR);
        }

        // Run each of the nect activations through the activation function
        for(int i = 0; i < new_activations[layer_num+1].size(); i++){
            new_activations[layer_num+1].get_data()[i] = act_func<T>(new_activations[layer_num+1].get_data()[i], act_function);

        }
    }   

    // Run the final layer of activations against their weights
    return new_activations.back();
}
