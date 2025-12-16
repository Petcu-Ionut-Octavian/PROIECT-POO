//
// Created by User on 12/16/2025.
//

#ifndef FAST_FOOD_ACCOUNT_H
#define FAST_FOOD_ACCOUNT_H

#include <string>

class Account {
private:
    std::string username;
    std::string password;

public:
    // Constructor
    explicit Account(const std::string& user = "", const std::string& pass = "");

    // Getters
    [[nodiscard]] std::string getUsername() const;
    [[nodiscard]] std::string getPassword() const;

    // Setters
    void setUsername(const std::string& user);
    void setPassword(const std::string& pass);

    // Utility
    [[nodiscard]] bool login(const std::string& user, const std::string& pass) const;
};

class Kid_account : public Account {
public:
    explicit Kid_account(const std::string& user = "", const std::string& pass = "");

};

class Adult_account : public Account {
public:
    explicit Adult_account(const std::string& user = "", const std::string& pass = "");

};

class Special_account : public Account {
public:
    explicit Special_account(const std::string& user = "", const std::string& pass = "");

};

#endif //FAST_FOOD_ACCOUNT_H