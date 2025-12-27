//
// Created by User on 12/16/2025.
//

#include "../include/account.h"
#include <iostream>

// ===================== Account =====================

Account::Account(const std::string& user, const std::string& pass)
        : username(user), password(pass) {}

std::string Account::getUsername() const { return username; }
std::string Account::getPassword() const { return password; }

void Account::setUsername(const std::string& user) { username = user; }
void Account::setPassword(const std::string& pass) { password = pass; }

bool Account::login(const std::string& user, const std::string& pass) const {
    return (user == username && pass == password);
}

void Account::buy() {

    bool buying = true;

    while (buying) {

        // ============================
        // LIVE CART PREVIEW (before menu)
        // ============================
        std::cout << "\n=========== CURRENT CART ===========\n";

        double preview_total = 0.0;
        for (auto* it : items) {
            it->print();
            std::cout << "\n";
            preview_total += it->price();
        }

        std::cout << "------------------------------------\n";
        std::cout << "TOTAL SO FAR: " << preview_total << "$\n";
        std::cout << "====================================\n\n";


        // ============================
        // MENU
        // ============================
        std::cout << "==================== MENU ====================\n";
        std::cout << "1. Cola           (500 ml)\n";
        std::cout << "2. Orange Juice   (300 ml)\n";
        std::cout << "3. Water          (500 ml)\n";
        std::cout << "4. Hamburger      (250 g)\n";
        std::cout << "5. Pizza Slice    (180 g)\n";
        std::cout << "6. Fries          (150 g)\n";
        std::cout << "7. Stop buying\n";
        std::cout << "8. Buy a Combo\n";
        std::cout << "Choose an item: ";

        std::string input;
        std::getline(std::cin, input);

        if (input == "7") {
            buying = false;
            break;
        }

        Item* item = nullptr;

        // ============================
        // SINGLE ITEMS
        // ============================
        if (input == "1") item = new Cola();
        else if (input == "2") item = new Orange_juce();
        else if (input == "3") item = new Water();
        else if (input == "4") item = new Hamburger();
        else if (input == "5") item = new Pizza();
        else if (input == "6") item = new Fries();

        // ============================
        // COMBO
        // ============================
        else if (input == "8") {

            std::cout << "\n=== COMBO MENU ===\n";

            std::cout << "Pick FIRST item:\n";
            std::cout << "1. Cola\n2. Orange Juice\n3. Water\n4. Hamburger\n5. Pizza\n6. Fries\n";
            std::cout << "Choice: ";

            std::string c1;
            std::getline(std::cin, c1);

            std::cout << "Pick SECOND item:\n";
            std::cout << "1. Cola\n2. Orange Juice\n3. Water\n4. Hamburger\n5. Pizza\n6. Fries\n";
            std::cout << "Choice: ";

            std::string c2;
            std::getline(std::cin, c2);

            Item* itemA = nullptr;
            Item* itemB = nullptr;

            if (c1 == "1") itemA = new Cola();
            else if (c1 == "2") itemA = new Orange_juce();
            else if (c1 == "3") itemA = new Water();
            else if (c1 == "4") itemA = new Hamburger();
            else if (c1 == "5") itemA = new Pizza();
            else if (c1 == "6") itemA = new Fries();

            if (c2 == "1") itemB = new Cola();
            else if (c2 == "2") itemB = new Orange_juce();
            else if (c2 == "3") itemB = new Water();
            else if (c2 == "4") itemB = new Hamburger();
            else if (c2 == "5") itemB = new Pizza();
            else if (c2 == "6") itemB = new Fries();

            if (!itemA || !itemB) {
                std::cout << "Invalid combo selection!\n\n";
                delete itemA;
                delete itemB;
                continue;
            }

            items.push_back(new Combo<Item, Item>(itemA, itemB));


            std::cout << "Combo added!\n\n";
            continue;
        }

        else {
            std::cout << "Invalid choice!\n\n";
            continue;
        }

        items.push_back(item);
        std::cout << "Item added!\n\n";
    }

    // ============================
    // APPLY ACCOUNT RESTRICTIONS
    // ============================

    if (dynamic_cast<const Kid_account*>(this)) {
        for (auto it = items.begin(); it != items.end();) {

            if (!(*it)->healthy()) {
                std::cout << "Kid restriction: ";
                (*it)->print();
                std::cout << " is unhealthy.\n";

                std::string choice;
                std::cout << "Remove this item? (yes/no): ";
                std::getline(std::cin, choice);

                if (choice == "yes" || choice == "y") {
                    delete *it;
                    it = items.erase(it);
                } else {
                    ++it;
                }
            }
            else {
                ++it;
            }
        }
    }

    if (dynamic_cast<const Special_account*>(this)) {
        for (auto it = items.begin(); it != items.end();) {

            bool bad = !(*it)->healthy();
            bool sugar_issue = false;

            Drink* d = dynamic_cast<Drink*>(*it);
            if (d && d->hasSugar())
                sugar_issue = true;

            if (!bad && !sugar_issue) {
                ++it;
                continue;
            }

            if (sugar_issue) {
                std::cout << "Special restriction: ";
                (*it)->print();
                std::cout << " has sugar.\n";

                std::string choice;
                std::cout << "Remove item or make it sugar-free? (remove/sugar): ";
                std::getline(std::cin, choice);

                if (choice == "remove") {
                    delete *it;
                    it = items.erase(it);
                    continue;
                }
                else if (choice == "sugar") {
                    d->setSugar(false);
                    std::cout << "Updated to sugar-free.\n";
                    ++it;
                    continue;
                }
                else {
                    std::cout << "Invalid choice. Keeping item.\n";
                    ++it;
                    continue;
                }
            }

            std::cout << "Special restriction: ";
            (*it)->print();
            std::cout << " is unhealthy.\n";

            std::string choice;
            std::cout << "Remove this item? (yes/no): ";
            std::getline(std::cin, choice);

            if (choice == "yes" || choice == "y") {
                delete *it;
                it = items.erase(it);
            } else {
                ++it;
            }
        }
    }

    // ============================
    // FINAL CART PRINT
    // ============================

    std::cout << "\n=========== FINAL CART ===========\n";

    double total = 0.0;
    for (auto* it : items) {
        it->print();
        std::cout << "\n";
        total += it->price();
    }

    std::cout << "----------------------------------\n";
    std::cout << "TOTAL: " << total << "$\n";
    std::cout << "==================================\n";
}










// ===================== Kid_account =====================

Kid_account::Kid_account(const std::string& user, const std::string& pass)
        : Account(user, pass) {}

void Kid_account::play() {
    std::cout << "Welcome, " << username << "! (Kid Account)\n";
    std::cout << "------------------------------\n";
    std::cout << "1. Buy\n";
    std::cout << "2. Logout\n";
    std::cout << "Enter your choice: ";

    std::string input;
    std::getline(std::cin, input);

    std::cout << "\n";

    if (input == "1") {
        std::cout << "Buying items...\n\n";
        buy();

    } else if (input == "2") {
        std::cout << "Logging out...\n\n";
    } else {
        std::cout << "Invalid choice!\n\n";
    }
}

// ===================== Adult_account =====================

Adult_account::Adult_account(const std::string& user, const std::string& pass)
        : Account(user, pass) {}

void Adult_account::play() {
    std::cout << "Welcome, " << username << "! (Adult Account)\n";
    std::cout << "------------------------------\n";
    std::cout << "1. Buy\n";
    std::cout << "2. Logout\n";
    std::cout << "Enter your choice: ";

    std::string input;
    std::getline(std::cin, input);

    std::cout << "\n";

    if (input == "1") {
        std::cout << "Buying items...\n\n";
        buy();
    } else if (input == "2") {
        std::cout << "Logging out...\n\n";
    } else {
        std::cout << "Invalid choice!\n\n";
    }
}

// ===================== Special_account =====================

Special_account::Special_account(const std::string& user, const std::string& pass)
        : Account(user, pass) {}

void Special_account::play() {
    std::cout << "Welcome, " << username << "! (Special Account)\n";
    std::cout << "------------------------------\n";
    std::cout << "1. Buy\n";
    std::cout << "2. Logout\n";
    std::cout << "Enter your choice: ";

    std::string input;
    std::getline(std::cin, input);

    std::cout << "\n";

    if (input == "1") {
        std::cout << "Buying items...\n\n";
        buy();
    } else if (input == "2") {
        std::cout << "Logging out...\n\n";
    } else {
        std::cout << "Invalid choice!\n\n";
    }
}