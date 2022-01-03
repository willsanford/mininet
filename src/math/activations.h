#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H

#include <string>

template<class T> T relu(T in);
template<class T> T drelu(T in);



template<class T> T act_func(T in, std::string func);
#endif
