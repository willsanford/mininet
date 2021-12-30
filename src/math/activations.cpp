#include "activations.h"


template<class T> 
T relu(T in){
  if (in < 0){
    return 0;
  }
  return in;
}
template float relu(float in);