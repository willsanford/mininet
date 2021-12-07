
#ifndef LOGS_H
#define LOGS_H


#include <cstdlib>
#include <string>

using namespace std;


// Message types
enum message_t {
    LOG = 0,
    WARNING = 1,
    ERROR = 2,
    SUCCESS = 3
};

// Message color
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
void log(string message, message_t type = LOG);

#endif