#ifndef BURGER_HPP
#define BURGER_HPP

#include "produs.h"

class Burger final : public Produs {
private:
    bool are_carne_vita;
    bool are_carne_pui;
    bool are_carne_porc;
    bool are_salata;
    bool are_rosii;
    bool are_ceapa;
    bool are_castraveti;
    bool are_cheddar;
    bool are_ketchup;
    bool are_maioneza;
    bool are_mustar;

public:
    Burger(double pret_baza) : Produs("Burger", pret_baza) {}

    void afiseaza() const override;

    // Getteri
    bool getAreChiflaSesame() const;
    bool getAreChiflaSimpla() const;
    bool getAreCarneVita() const;
    bool getAreCarnePui() const;
    bool getAreCarnePorc() const;
    bool getAreSalata() const;
    bool getAreRosii() const;
    bool getAreCeapa() const;
    bool getAreCastraveti() const;
    bool getAreCheddar() const;
    bool getAreKetchup() const;
    bool getAreMaioneza() const;
    bool getAreMustar() const;
    bool getAreBbq() const;

    // Setteri
    void setAreChiflaSesame(bool val);
    void setAreChiflaSimpla(bool val);
    void setAreCarneVita(bool val);
    void setAreCarnePui(bool val);
    void setAreCarnePorc(bool val);
    void setAreSalata(bool val);
    void setAreRosii(bool val);
    void setAreCeapa(bool val);
    void setAreCastraveti(bool val);
    void setAreCheddar(bool val);
    void setAreKetchup(bool val);
    void setAreMaioneza(bool val);
    void setAreMustar(bool val);
    void setAreBbq(bool val);
};

#endif