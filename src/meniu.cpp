// =======================
// Singleton: FastFoodMenu (Singleton)
// =======================

#include "meniu.h"

FastFoodMenu* FastFoodMenu::instance = nullptr;

FastFoodMenu* FastFoodMenu::getInstance() {
    if (!instance) {
        instance = new FastFoodMenu();
    }
    return instance;
}

std::ostream& operator<<(std::ostream& os, const FastFoodMenu& menu) {
    os << "Meniu FastFood:\n";
    return os;
}

std::istream& operator>>(std::istream& is, FastFoodMenu& menu) {
    return is;
}

void FastFoodMenu::addItem(const std::string& item) {
    items.push_back(item);
}

void FastFoodMenu::showMenu() const {
    std::cout << *this;
}

