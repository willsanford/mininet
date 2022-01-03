#include "activations.h"

/**
 * @brief Relu
 * 
 * @tparam T 
 * @param in 
 * @return T 
 */
template<class T> 
T relu(T in){
  if (in > 0){
    return in;
  }
  return 0;
}
template float relu(float in);

/**
 * @brief Derivative of the relu
 * 
 * @tparam T 
 * @param in 
 * @return T 
 */
template<class T>
T drelu(T in){
  if (in >= 0){
    return 1;
  }
  return 0;
} 
template float drelu(float in);


template<class T> T act_func(T in, std::string func){
  if (func == "relu"){
    return relu(in);
  }else if(func == "drelu"){
    return drelu(in);

  // Default to relu
  }else{
    return relu(in);
  }
}
template float act_func(float in, std::string func);