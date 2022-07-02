
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <chrono>

#include "tensor.h"
#include "tensor_math.h"

using namespace std::chrono;
int main(void){
  // vector<int> dims1 = {1000,1000};
  // Tensor<float> test1(dims1, 1);

  // vector<int> dims2 = {1000,1000};
  // Tensor<float> test2(dims2, 1);

  // vector<int> dims3 = {1000,1000};
  // Tensor<float> test3(dims3);

  // auto start = high_resolution_clock::now();
  // TMATH_STATUS outcome = tmult(test1, test2, test3);
  // auto stop = high_resolution_clock::now();
  // auto duration = duration_cast<microseconds>(stop - start);
  // cout << duration.count() << endl;

  int size = 1024;

  vector<float> in1(size * size, 1);
  vector<float> in2(size * size, 1);

  auto start = high_resolution_clock::now();
  vector<float> out = mmult<float>(in1, in2, 1000, 1000, 1000);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stop - start);
  cout << duration.count() << endl;
}
