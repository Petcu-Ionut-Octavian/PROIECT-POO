#ifndef CARTOFI_HPP
#define CARTOFI_HPP

#include "produs.h"

class Cartofi final : public Produs {
private:
    bool are_ketchup;
    bool are_maioneza;
    bool are_mustar;
    bool are_sos_picant;

public:
    Cartofi(double pret_baza) : Produs("Cartofi", pret_baza) {}

    void afiseaza() const override;

    // Getteri
    bool getAreKetchup() const;
    bool getAreMaioneza() const;
    bool getAreMustar() const;
    bool getAreSosPicant() const;

    // Setteri
    void setAreKetchup(bool val);
    void setAreMaioneza(bool val);
    void setAreMustar(bool val);
    void setAreSosPicant(bool val);
};

#endif