#include "include/fast_food.h"
#include <exception>
#include <iostream>
#include <ostream>

int main() {

    try {
        FastFood::getInstance();
        FastFood::play();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}