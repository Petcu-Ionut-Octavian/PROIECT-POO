#ifndef FAST_FOOD_EXCEPTIONS_H
#define FAST_FOOD_EXCEPTIONS_H

#include <stdexcept>
#include <string>

// Custom exception class for login errors
class invalid_login final : public std::runtime_error {
public:
    explicit invalid_login(const std::string& msg);
};

// Custom exception for invalid general input
class invalid_input final : public std::runtime_error {
public:
    explicit invalid_input(const std::string& msg);
};

// Custom exception for invalid age
class invalid_age final : public std::runtime_error {
public:
    explicit invalid_age(const std::string& msg);
};

#endif // FAST_FOOD_EXCEPTIONS_H
