#include "../include/exceptions.h"

invalid_login::invalid_login(const std::string& msg)
    : std::runtime_error(msg) {}

invalid_input::invalid_input(const std::string& msg)
    : std::runtime_error(msg) {}

invalid_age::invalid_age(const std::string& msg)
    : std::runtime_error(msg) {}