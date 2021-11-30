#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include "logs.h"
using namespace std;


void log(string message, message_t type){
	#ifdef LOGGING
	// Get the current time
	time_t now = time(0);
	tm* ltm = localtime(&now);
	// Print out the time of day
	printf("[%02d:%02d:%02d] ", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);

	// Change the color of the output based on the message type
	switch (type){
		case LOG:
			cout << "LOG: ";
			break;
		case WARNING:
			cout << YELLOW << "WARNING: ";
			break;
		case ERROR:
			cout << RED << "ERROR: ";
			break;
		case SUCCESS:
			cout << GREEN << "SUCCESS: ";
			break;
	}

	// Print the message and reset the color
	cout << message << RESET << endl;;
	#endif
}
