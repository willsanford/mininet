/*
 * tensor.h
 *
 * Basic tensor class header
 *
 * Author: Will Sanford
 * Date: Aug 19, 2021
 */
#ifndef TENSOR_H
#define TENSOR_H

class Tensor{
	private:
		int num_dims;
		int *dims;
		int num_el;
		float *data;
	public:
		// Getters 
		int get_num_dims(){
			return num_dims;
		}
		int* get_dims(){
			return dims;
		}
		int get_num_el(){
			return num_el;
		}
		float *get_data(){
			return data;
		}

		// Setters
		void set_num_dims(int n){
			num_dims = n;
		}
		void set_dims(int* n){
			dims = n;
		}
		void set_num_el(int n){
			num_el = n;
		}
		void set_data(float * n){
			data = n;
		}
}

#endif
