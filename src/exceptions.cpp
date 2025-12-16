//
// Created by User on 12/16/2025.
//



#include "../include/exceptions.h"

// Constructor implementation
invalid_login::invalid_login(const std::string& msg)
    : std::runtime_error(msg) {}
