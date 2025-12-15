#ifndef SHAORMA_HPP
#define SHAORMA_HPP

#include "produs.h"

class Shaorma final : public Produs {
private:
    bool are_pui;
    bool are_vita;
    bool are_porc;
    bool are_cartofi;
    bool are_salata;
    bool are_varza;
    bool are_rosii;
    bool are_castraveti;
    bool are_maioneza;
    bool are_ketchup;

public:
    Shaorma(double pret_baza) : Produs("Shaorma", pret_baza) {}

    void afiseaza() const override;

    // Getteri
    bool getArePui() const;
    bool getAreVita() const;
    bool getArePorc() const;
    bool getAreCartofi() const;
    bool getAreSalata() const;
    bool getAreVarza() const;
    bool getAreRosii() const;
    bool getAreCastraveti() const;
    bool getAreMaioneza() const;
    bool getAreKetchup() const;

    // Setteri
    void setArePui(bool val);
    void setAreVita(bool val);
    void setArePorc(bool val);
    void setAreCartofi(bool val);
    void setAreSalata(bool val);
    void setAreVarza(bool val);
    void setAreRosii(bool val);
    void setAreCastraveti(bool val);
    void setAreMaioneza(bool val);
    void setAreKetchup(bool val);
};

#endif