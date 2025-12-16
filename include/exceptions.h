//
// Created by User on 12/16/2025.
//

#ifndef FAST_FOOD_EXCEPTIONS_H
#define FAST_FOOD_EXCEPTIONS_H

#include <stdexcept>
#include <string>

// Custom exception class for login errors
class invalid_login final : public std::runtime_error {
public:
    explicit invalid_login(const std::string& msg);
};



#endif //FAST_FOOD_EXCEPTIONS_H