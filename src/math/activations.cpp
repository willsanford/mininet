#include "activations.h"


template<class T> 
T relu(T in){
  if (in > 0){
    return in;
  }
  return 0;
}
template float relu(float in);


template<class T>
T drelu(T in){
  if (in >= 0){
    return 1;
  }
  return 0;
} 
template float drelu(float in);