#include <iostream>

#include "File.h"

int main() {
    try {
        // Use our example class that throws an exception
        File file;
        file.getContent("test.txt");

    } catch (boost::exception& e) {
        // Diagnose the exception and write it in error stream to read it
        std::cerr << boost::diagnostic_information(e);
    }

    return EXIT_SUCCESS;
}