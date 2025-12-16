//
// Created by User on 12/16/2025.
//

#include "../include/account.h"

// Constructor
Account::Account(const std::string& user, const std::string& pass)
    : username(user), password(pass) {}

// Getters
std::string Account::getUsername() const {
    return username;
}

std::string Account::getPassword() const {
    return password;
}

// Setters
void Account::setUsername(const std::string& user) {
    username = user;
}

void Account::setPassword(const std::string& pass) {
    password = pass;
}

// Utility
bool Account::login(const std::string& user, const std::string& pass) const {
    return (user == username && pass == password);
}


Kid_account::Kid_account(const std::string& user, const std::string& pass)
        : Account(user, pass) {}

Adult_account::Adult_account(const std::string& user, const std::string& pass)
        : Account(user, pass) {}

Special_account::Special_account(const std::string& user, const std::string& pass)
        : Account(user, pass) {}