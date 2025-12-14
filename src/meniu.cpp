#include "meniu.h"

// =======================
// Singleton: FastFoodMenu
// =======================
FastFoodMenu* FastFoodMenu::instance = nullptr;

FastFoodMenu* FastFoodMenu::getInstance() {
    if (!instance) {
        instance = new FastFoodMenu();
    }
    return instance;
}

std::ostream& operator<<(std::ostream& os, const FastFoodMenu& menu) {
    os << "Meniu FastFood:\n";
    for (const auto& item : menu.items) {
        os << "- " << item << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, FastFoodMenu& menu) {
    std::string item;
    std::cout << "Introdu un produs pentru meniu: ";
    is >> item;
    menu.addItem(item);
    return is;
}

void FastFoodMenu::addItem(const std::string& item) {
    items.push_back(item);
}

void FastFoodMenu::showMenu() const {
    std::cout << *this;
}

// =======================
// Burger
// =======================
Burger::Burger(const std::string& bun, const std::string& meat)
    : bun(bun), meat(meat) {}

Burger::Burger(const Burger& other)
    : bun(other.bun), meat(other.meat), sauce(other.sauce), extras(other.extras) {}

Burger& Burger::operator=(const Burger& other) {
    if (this != &other) {
        bun = other.bun;
        meat = other.meat;
        sauce = other.sauce;
        extras = other.extras;
    }
    return *this;
}

Burger::~Burger() {}

std::ostream& operator<<(std::ostream& os, const Burger& b) {
    os << "Burger: " << b.bun << " + " << b.meat;
    if (!b.sauce.empty()) os << " cu " << b.sauce;
    if (!b.extras.empty()) {
        os << " [extras: ";
        for (const auto& e : b.extras) os << e << " ";
        os << "]";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Burger& b) {
    std::cout << "Introdu bun si carne: ";
    is >> b.bun >> b.meat;
    return is;
}

bool Burger::operator==(const Burger& other) const {
    return bun == other.bun && meat == other.meat &&
           sauce == other.sauce && extras == other.extras;
}

Burger operator+(const Burger& a, const Burger& b) {
    Burger combined = a;
    combined.extras.insert(combined.extras.end(), b.extras.begin(), b.extras.end());
    return combined;
}

// =======================
// BurgerBuilder
// =======================
BurgerBuilder& BurgerBuilder::setBun(const std::string& bun) {
    
