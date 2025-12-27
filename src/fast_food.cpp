//
// Created by User on 12/16/2025.
//

#include "../include/fast_food.h"
#include "../include/exceptions.h"

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <exception>


std::vector<Account*> FastFood::accounts;

// Constructor privat
FastFood::FastFood() {
    std::ifstream file("../database/accounts.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Could not open accounts.txt");
    }

    std::string username, password, type;

    // Read each line: username password type
    while (file >> username >> password >> type) {
        if (type == "kid") {
            accounts.push_back(new Kid_account(username, password));
        } else if (type == "adult") {
            accounts.push_back(new Adult_account(username, password));
        } else if (type == "special") {
            accounts.push_back(new Special_account(username, password));
        } else {
            throw std::runtime_error("The accounts file is corrupted");
        }

    }

};

// Instanța unică
FastFood& FastFood::getInstance() {
    static FastFood instance;
    return instance;
}

void FastFood::show_menu() {
    std::cout <<"############################################\n";
    std::cout<< "#                -Main Menu-               #\n";
    std::cout<< "# 1. See offers                            #\n";
    std::cout<< "# 2. Login                                 #\n";
    std::cout<< "# 3. Create costumer account               #\n";
    std::cout<< "# 4. Delete costumer account               #\n";
    std::cout<< "# 5. Quit                                  #\n";
    std::cout<< "############################################\n\n";
    std::cout<< "Enter your choice: ";
}

void FastFood::show_offers() {
    std::cout <<"############################################\n";
    std::cout<< "                -Offers-               \n";
    std::cout<< "1. Combo drink - drink \n";
    std::cout<< "2. Combo drink - hamburger\n";
    std::cout<< "3. Combo drink - pizza\n";
    std::cout<< "4. Combo drink - souce\n\n";
    std::cout<< "Press enter to continue: ";
    std::cin.ignore(100, '\n');
    std::cout<< "\n";
}

void FastFood::login() {
    std::string username, password;
    std::cout<< "     Logging in            \n";
    std::cout << "Enter your name:";
    std::getline(std::cin, username);
    std::cout << "Enter your password:";
    std::getline(std::cin, password);
    std::cout<< "\n";

    bool valid_login = false;
    for (auto account : accounts) {
        if (account->login(username, password)) {
            std::cout<< "You logged in \n\n";
            valid_login = true;
            account->play();
            break;
        }
    }
    if (!valid_login) {
        throw invalid_login("Login failed");
    }

}

void FastFood::create_account() {
    std::string username, password, type;

    std::cout << "   Creating new account\n";
    std::cout << "Enter username: ";
    std::getline(std::cin, username);

    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    std::cout << "Enter type (kid/adult/special): ";
    std::getline(std::cin, type);

    if (username.empty() || password.empty() ||
        !(type == "kid" || type == "adult" || type == "special")) {
        std::cout << "Invalid input!\n\n";
        return;
        }

    // Check duplicate
    for (auto acc : accounts) {
        if (acc->getUsername() == username) {
            std::cout << "Username already exists!\n\n";
            return;
        }
    }

    Account* newAcc = nullptr;
    if (type == "kid") newAcc = new Kid_account(username, password);
    else if (type == "adult") newAcc = new Adult_account(username, password);
    else newAcc = new Special_account(username, password);

    accounts.push_back(newAcc);

    // Append to file
    std::ofstream file("../database/accounts.txt", std::ios::app);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open accounts.txt");
    }
    file << username << " " << password << " " << type << "\n";

    std::cout << "Account created successfully!\n\n";
}

void FastFood::delete_account() {
    std::string username, password;

    std::cout << "   Deleting account\n";
    std::cout << "Enter username: ";
    std::getline(std::cin, username);

    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    bool found = false;

    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if ((*it)->getUsername() == username &&
            (*it)->login(username,password)) {

            delete *it;
            accounts.erase(it);
            found = true;
            break;
            }
    }

    if (!found) {
        std::cout << "Account not found or wrong password!\n\n";
        return;
    }

    // Rewrite entire file
    std::ofstream file("../database/accounts.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Could not open accounts.txt");
    }

    for (auto acc : accounts) {

        std::string type;
        if (dynamic_cast<Kid_account*>(acc)) type = "kid";
        if (dynamic_cast<Adult_account*>(acc)) type = "adult";
        if (dynamic_cast<Special_account*>(acc)) type = "special";


        file << acc->getUsername() << " "
             << acc->getPassword() << " "
             << type << "\n";
    }

    std::cout << "Account deleted successfully!\n\n";
}

void FastFood::play() {
    bool running = true;
    std::string input;
    while (running) {
        show_menu();
        try {
            getline(std::cin, input);
            std::cout << "\n";
            if (input.size() > 2 || input.empty()) {
                throw std::invalid_argument("Invalid input!");
            }
            switch (char choice = input[0]) {
                case '1': {
                    show_offers();
                    break;
                }
                case '2': {
                    login();
                    break;
                }
                case '3': {
                    create_account();
                    break;
                }
                case '4': {
                    delete_account();
                    break;
                }
                case '5': {
                    std::cout<< "Quitting...\n";
                    running = false;
                    break;
                }
                default:
                    std::cout << "Invalid Choice!\n";
            }
        }
        catch (std::invalid_argument& e) {
            std::cout << e.what() << "\n\n";
        } catch (invalid_login& e) {
            std::cout << e.what() << "\n\n";
        }
    }
}
