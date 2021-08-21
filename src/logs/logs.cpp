#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include "logs.h"
using namespace std;


void log(string message, int type){
	cout << message << endl;
/*
	// Get the time
	time_t now = time(0);
	tm *ltm = localtime(&now);

	string hour = to_string(5+ltm->tm_hour);
	string min = to_string(30 + ltm->tm_min);
	string sec = to_string()
	
	// Switch on message type
	switch(type){
		// Note - White
		case 0:
			break;
		// Success - Green
		case 1:
			system("Color 0A");			
			break;
		// Warning - Yellow
		case 2:
			break;
		// Error - Red
		case 3;
			system("Color E4");
			break;
		
		// Currently does nothing
		default:
			break;

	}
	*/
}
