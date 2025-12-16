//
// Created by User on 12/16/2025.
//

#ifndef FAST_FOOD_FAST_FOOD_H
#define FAST_FOOD_FAST_FOOD_H

#include <string>
#include <vector>

#include "account.h"

class FastFood {
private:
    static std::vector<Account*> accounts;

    // Constructor privat
    FastFood();

public:

    // Interzicem copierea
    FastFood(const FastFood&) = delete;
    FastFood& operator=(const FastFood&) = delete;

    static FastFood& getInstance();

    static void show_menu();
    static void show_offers();
    static void login();
    static void play();
};





#endif //FAST_FOOD_FAST_FOOD_H