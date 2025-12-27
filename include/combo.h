//
// Created by User on 12/26/2025.
//

#ifndef FAST_FOOD_COMBO_H
#define FAST_FOOD_COMBO_H

#include "items.h"
#include <iostream>

template <class T1, class T2>
class Combo : public Item {
private:
    T1 item1;
    T2 item2;

public:
    Combo(const T1& i1, const T2& i2)
        : item1(i1), item2(i2) {}

    [[nodiscard]] double price() const {
        return item1.price() + item2.price();
    }

    void print() const {
        std::cout << "===== COMBO =====\n";

        // ITEM 1
        if (auto* c = dynamic_cast<const Cola*>(&item1))
            std::cout << "Cola " << c->getGrams() << " ml\n";
        else if (auto* o = dynamic_cast<const Orange_juce*>(&item1))
            std::cout << "Orange Juice " << o->getGrams() << " ml\n";
        else if (auto* w = dynamic_cast<const Water*>(&item1))
            std::cout << "Water " << w->getGrams() << " ml\n";
        else if (auto* h = dynamic_cast<const Hamburger*>(&item1))
            std::cout << "Hamburger " << h->getGrams() << " g\n";
        else if (auto* p = dynamic_cast<const Pizza*>(&item1))
            std::cout << "Pizza Slice " << p->getGrams() << " g\n";
        else if (auto* f = dynamic_cast<const Fries*>(&item1))
            std::cout << "Fries " << f->getGrams() << " g\n";

        // ITEM 2
        if (auto* c = dynamic_cast<const Cola*>(&item2))
            std::cout << "Cola " << c->getGrams() << " ml\n";
        else if (auto* o = dynamic_cast<const Orange_juce*>(&item2))
            std::cout << "Orange Juice " << o->getGrams() << " ml\n";
        else if (auto* w = dynamic_cast<const Water*>(&item2))
            std::cout << "Water " << w->getGrams() << " ml\n";
        else if (auto* h = dynamic_cast<const Hamburger*>(&item2))
            std::cout << "Hamburger " << h->getGrams() << " g\n";
        else if (auto* p = dynamic_cast<const Pizza*>(&item2))
            std::cout << "Pizza Slice " << p->getGrams() << " g\n";
        else if (auto* f = dynamic_cast<const Fries*>(&item2))
            std::cout << "Fries " << f->getGrams() << " g\n";

        std::cout << "------------------\n";
        std::cout << "Total: " << price() << "$\n";
        std::cout << "===================\n";
    }
};





#endif //FAST_FOOD_COMBO_H