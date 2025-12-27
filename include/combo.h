#ifndef COMBO_H
#define COMBO_H

template <class T1, class T2>
class Combo : public Item {
private:
    Item* item1;
    Item* item2;

public:
    Combo(Item* i1, Item* i2)
        : item1(i1), item2(i2) {}

    ~Combo() override {
        delete item1;
        delete item2;
    }

    [[nodiscard]] double price() const override {
        double base = item1->price() + item2->price();

        bool isFood1  = dynamic_cast<Food*>(item1)  != nullptr;
        bool isFood2  = dynamic_cast<Food*>(item2)  != nullptr;
        bool isDrink1 = dynamic_cast<Drink*>(item1) != nullptr;
        bool isDrink2 = dynamic_cast<Drink*>(item2) != nullptr;

        // Food + Food OR Drink + Drink → 10% reducere
        if ((isFood1 && isFood2) || (isDrink1 && isDrink2)) {
            return base * 0.90;
        }

        // Food + Drink OR Drink + Food → 15% reducere
        return base * 0.85;
    }

    [[nodiscard]]  bool healthy() const override {
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
