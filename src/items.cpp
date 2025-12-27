#include "../include/items.h"

// ============================================================
// Item
// ============================================================

Item::Item(const double grams) : grams(grams) {}
Item::~Item() = default;

double Item::getGrams() const { return grams; }

// ============================================================
// Drink
// ============================================================

Drink::Drink(const double grams, bool sugar)
    : Item(grams), sugar(sugar) {}

Drink::~Drink() = default;

// Cola --------------------------------------------------------

Cola::Cola(const double grams)
    : Drink(grams, true) {}

Cola::~Cola() = default;

double Cola::price() const {
    return grams * 0.015;
}

bool Cola::healthy() const {
    return false;
}

// Orange Juice ------------------------------------------------

Orange_juce::Orange_juce(const double grams)
    : Drink(grams, false) {}

Orange_juce::~Orange_juce() = default;

double Orange_juce::price() const {
    return grams * 0.02;
}

bool Orange_juce::healthy() const {
    return true;
}

// Water -------------------------------------------------------

Water::Water(const double grams)
    : Drink(grams, false) {}

Water::~Water() = default;

double Water::price() const {
    return 1.0;
}

bool Water::healthy() const {
    return true;
}

// ============================================================
// Food
// ============================================================

Food::Food(const double grams, const bool spicy)
    : Item(grams), spicy_sauce(spicy) {}

Food::~Food() = default;

// Hamburger ---------------------------------------------------

Hamburger::Hamburger(const double grams, const bool spicy)
    : Food(grams, spicy) {}

Hamburger::~Hamburger() = default;

double Hamburger::price() const {
    return grams * 0.025;
}

bool Hamburger::healthy() const {
    return grams < 200;
}

// Pizza -------------------------------------------------------

Pizza::Pizza(const double grams, const bool spicy)
    : Food(grams, spicy) {}

Pizza::~Pizza() = default;

double Pizza::price() const {
    return grams * 0.03;
}

bool Pizza::healthy() const {
    return false;
}

// Fries -------------------------------------------------------

Fries::Fries(const double grams, const bool spicy)
    : Food(grams, spicy) {}

Fries::~Fries() = default;

double Fries::price() const {
    return grams * 0.02;
}

bool Fries::healthy() const {
    return grams < 120;
}


void Drink::setSugar(bool s) { sugar = s; }
bool Drink::getSugar() const { return sugar; }

void Food::setSpicy(bool s) { spicy_sauce = s; }
bool Food::getSpicy() const { return spicy_sauce; }