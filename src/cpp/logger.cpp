#include "logger.hpp"

int main() {
    LOG(error) << "error"; //logger.cpp:4:0: error: main: error
    LOG(warn)  << "warn";  //logger.cpp:5:0: warn: main: warn
    LOG(debug) << "debug"; //logger.cpp:6:0: warn: main: debug
    LOG(info)  << "info";  //
    LOG(trace) << "trace"; //

    return 0;
}

