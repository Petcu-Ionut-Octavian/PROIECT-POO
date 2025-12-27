//
// Created by User on 12/16/2025.
//

#ifndef FAST_FOOD_ACCOUNT_H
#define FAST_FOOD_ACCOUNT_H

#include <string>
#include <vector>
#include "items.h"
#include "combo.h"

class Account {
protected:
    std::string username;
    std::string password;

    std::vector<Item*> items;

public:
    virtual ~Account() = default;

    // Constructor
    explicit Account(std::string  user = "", std::string  pass = "");

    // Getters
    [[nodiscard]] std::string getUsername() const;
    [[nodiscard]] std::string getPassword() const;

    // Setters
    void setUsername(const std::string& user);
    void setPassword(const std::string& pass);

    // Utility
    [[nodiscard]] bool login(const std::string& user, const std::string& pass) const;

    virtual void play() = 0;
    void buy();

};

class Kid_account final : public Account {
public:
    explicit Kid_account(const std::string& user = "", const std::string& pass = "");

    void play() override;

};

class Adult_account final : public Account {
public:
    explicit Adult_account(const std::string& user = "", const std::string& pass = "");

    void play() override;
};

class Special_account final : public Account {
public:
    explicit Special_account(const std::string& user = "", const std::string& pass = "");

    void play() override;
};

#endif //FAST_FOOD_ACCOUNT_H