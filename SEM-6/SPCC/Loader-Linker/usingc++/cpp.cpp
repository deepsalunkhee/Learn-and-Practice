#include <iostream>

extern "C" void displayMessage() {
    std::cout << "Hello, world from cpp!" << std::endl;
}
