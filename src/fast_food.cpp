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
    std::cout<< "        -Main Menu-        \n";
    std::cout<< "1. See offers             \n";
    std::cout<< "2. Login                  \n";
    std::cout<< "3. Create costumer account \n";
    std::cout<< "4. Delete costumer account \n";
    std::cout<< "5. Quit                    \n\n";
    std::cout<< "Enter your choice: ";
}

void FastFood::show_offers() {
    std::cout<< "        -Offers-        \n";
    std::cout<< "1.  \n";
    std::cout<< "2.  \n";
    std::cout<< "3.  \n";
    std::cout<< "4.  \n\n";
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
            account.play();  //to do
            break;
        }
    }
    if (!valid_login) {
        throw std::runtime_error("Login failed");
    }

}

void FastFood::play() {
    bool running = true;
    std::cout << "Welcome to Fast Food Smart!\n\n";
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
                    create_account(); //to do
                    break;
                }
                case '4': {
                    delete_account(); //to do
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
