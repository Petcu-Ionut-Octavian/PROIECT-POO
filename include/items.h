//
// Created by User on 12/26/2025.
//

#ifndef FAST_FOOD_ITEMS_H
#define FAST_FOOD_ITEMS_H

#include <iostream>

// ============================================================
// Base Item
// ============================================================

class Item {
protected:
    double grams;

public:
    explicit Item(double grams = 0.0);
    virtual ~Item();

    [[nodiscard]] virtual double price() const = 0;
    [[nodiscard]] virtual bool healthy() const = 0;

    [[nodiscard]] double getGrams () const ;
};

// ============================================================
// Drinks
// ============================================================

class Drink : public Item {
protected:
    bool sugar;

public:
    explicit Drink(double grams = 0.0, bool sugar = false);
    ~Drink() override;

    // NEW:
    void setSugar(bool s);
    [[nodiscard]] bool getSugar() const;
};

// Cola --------------------------------------------------------

class Cola final : public Drink {
public:
    explicit Cola(double grams = 500);
    ~Cola() override;

    [[nodiscard]] double price() const override;
    [[nodiscard]] bool healthy() const override;
};

// Orange Juice ------------------------------------------------

class Orange_juce final : public Drink {
public:
    explicit Orange_juce(double grams = 300);
    ~Orange_juce() override;

    [[nodiscard]] double price() const override;
    [[nodiscard]] bool healthy() const override;
};

// Water -------------------------------------------------------

class Water final : public Drink {
public:
    explicit Water(double grams = 500);
    ~Water() override;

    [[nodiscard]] double price() const override;
    [[nodiscard]] bool healthy() const override;
};

// ============================================================
// Foods
// ============================================================

class Food : public Item {
protected:
    bool spicy_sauce;

public:
    explicit Food(double grams = 0.0, bool spicy = false);
    ~Food() override;

    // NEW:
    void setSpicy(bool s);
    [[nodiscard]] bool getSpicy() const;
};

// Hamburger ---------------------------------------------------

class Hamburger final : public Food {
public:
    explicit Hamburger(double grams = 250, bool spicy = false);
    ~Hamburger() override;

    [[nodiscard]] double price() const override;
    [[nodiscard]] bool healthy() const override;
};

// Pizza -------------------------------------------------------

class Pizza final : public Food {
public:
    explicit Pizza(double grams = 180, bool spicy = false);
    ~Pizza() override;

    [[nodiscard]] double price() const override;
    [[nodiscard]] bool healthy() const override;
};

// Fries -------------------------------------------------------

class Fries final : public Food {
public:
    explicit Fries(double grams = 150, bool spicy = false);
    ~Fries() override;

    [[nodiscard]] double price() const override;
    [[nodiscard]] bool healthy() const override;
};

#endif // FAST_FOOD_ITEMS_H