#ifndef FASTFOOD_HPP
#define FASTFOOD_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// =======================
// Singleton: FastFoodMenu
// =======================
class FastFoodMenu {
private:
    static FastFoodMenu* instance;

    FastFoodMenu() = default;

public:
    virtual ~FastFoodMenu() = default;

    static FastFoodMenu* getInstance();

    friend std::ostream& operator<<(std::ostream& os, const FastFoodMenu& menu);
    friend std::istream& operator>>(std::istream& is, FastFoodMenu& menu);

    void showMenu() const;
};

#endif 
