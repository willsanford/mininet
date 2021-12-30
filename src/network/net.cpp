#include "net.h"
#include "tensor.h"

template<class T>
Net(vector<int> input_size, vector<int> output_size, int num_hidden_layers, int hidden_layer_size, int batch_size=1){
    // create vectors of tensors for weights and activations

    // Set the function handle for the activation functions

    // Think of whatever else might need to be done
}
template Net<T>(vector<int> input_size, vector<int> output_size, int num_hidden_layers, int hidden_layer_size, int batch_size=1);


template<T> 
Tensor<T> run(Tensor<T> input, int batch_size){
    // Declare a new activations v  ector<Tensor<T>> and make it the correct size
    vector<Tensor<T>> new_activations(num_hidden_layers + 1);
    Tensor<T> output(output_size);
    // Loop through each layer of weights, activations and biases and 
    // run the function a_{i+1} = act_func(w_i * a_i + b_i)

    for (int layer_i = 0; layer_i < activations.size(); i++){
        // Put in the actual logic for multiplying a single layer of activations and a matrix of weights
    }   

    // set the output as the last result

    // return the last result
}
template run(Tensor<float> input, int batch_size);