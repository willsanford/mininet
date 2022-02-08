# NNs from scratch
This is my attempt at writing a basic neural network framework in c++.

# TODO (short term):
- [ ] Implement the `telwise_op` operation
- [ ] Write unit tests for `tconst_op` and `telwise_op`
- [ ] Write the activation logic to take a tensor instead of a single value. Less function calls
- [ ] Write more unit tests for broadcasted mmults. Do (mxm) * (mx1) tests to simulate single layer forward passes
# TODO (long term):
- [ ] Write softmax and relu funtions for
- [ ] Implement the layer class for fully connected forward pass networks
- [ ] Look into how to set up the back propogation algorithm
- [ ] With tensor mult done, try running some timing tests with very large matrices and start the data collection

# Compilation
A cmake file is provided. To compile and run the test files, run the following commands

```
cmake -S. -Bbuild
cmake --build build
./build/mininet
```
# Documentaion Generation
To generate documentation, run 
```bash
doxygen Doxyfile
``` 
this will generate an index file in `doxygen/html/index.html`.


# Requirements
- cmake
- googletest
- doxygen