#include "layer.h"

template<class T>
Layer::Layer(vector<T>& weights, T bias, vector<T> activation){
    weights = weights;
    bias = bias;
    activation = activation;
}
template Layer<float>;


template<T>
vector<T> Layer::run(){
    
}
template vector<float>run();