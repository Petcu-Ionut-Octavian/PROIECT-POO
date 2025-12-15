#ifndef PIZZA_HPP
#define PIZZA_HPP

#include "produs.h"

class Pizza final : public Produs {
private:
    bool are_salam;
    bool are_ciuperci;
    bool are_masline;
    bool are_extra_cheese;
    bool are_ketchup;
    bool are_usturoi;

public:
    Pizza(double pret_baza) : Produs("Pizza", pret_baza) {}

    void afiseaza() const override;

    // Getteri
    bool getAreSalam() const;
    bool getAreCiuperci() const;
    bool getAreMasline() const;
    bool getAreExtraCheese() const;
    bool getAreKetchup() const;
    bool getAreUsturoi() const;

    // Setteri
    void setAreSalam(bool val);
    void setAreCiuperci(bool val);
    void setAreMasline(bool val);
    void setAreExtraCheese(bool val);
    void setAreKetchup(bool val);
    void setAreUsturoi(bool val);
};

#endif