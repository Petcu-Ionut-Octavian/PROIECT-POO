#ifndef COMBO_H
#define COMBO_H

template <class T1, class T2>
class Combo final : public Item {
    T1* item1;
    T2* item2;

public:
    Combo(T1* i1, T2* i2)
        : item1(i1), item2(i2) {}

    ~Combo() override {
        delete item1;
        delete item2;
    }

    [[nodiscard]] double price() const override {
        const double base = item1->price() + item2->price();

        const bool isFood1  = dynamic_cast<Food*>(item1)  != nullptr;
        const bool isFood2  = dynamic_cast<Food*>(item2)  != nullptr;
        const bool isDrink1 = dynamic_cast<Drink*>(item1) != nullptr;
        const bool isDrink2 = dynamic_cast<Drink*>(item2) != nullptr;

        if ((isFood1 && isFood2) || (isDrink1 && isDrink2))
            return base * 0.90;   // 10% off

        return base * 0.85;       // 15% off
    }

    [[nodiscard]] bool healthy() const override {
        return item1->healthy() && item2->healthy();
    }

    void print() const override {
        std::cout << "===== COMBO =====\n";
        std::cout << "Item 1: "; item1->print(); std::cout << "\n";
        std::cout << "Item 2: "; item2->print(); std::cout << "\n";
        std::cout << "------------------\n";
        std::cout << "Total: " << price() << "$\n";
        std::cout << "===================\n";
    }
};

#endif // COMBO_H