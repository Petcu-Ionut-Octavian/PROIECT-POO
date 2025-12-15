// =======================
// Burger
// =======================

#include "burger.h"

void Burger::afiseaza() const {
    std::cout << nume << " (" << pret_baza << " lei, " << cantitate << "g)";
    std::cout << " cu: ";
    if (are_chifla_sesame) std::cout << "chifla sesame ";
    if (are_chifla_simpla) std::cout << "chifla simpla ";
    if (are_carne_vita) std::cout << "carne vita ";
    if (are_carne_pui) std::cout << "carne pui ";
    if (are_carne_porc) std::cout << "carne porc ";
    if (are_salata) std::cout << "salata ";
    if (are_rosii) std::cout << "rosii ";
    if (are_ceapa) std::cout << "ceapa ";
    if (are_castraveti) std::cout << "castraveti ";
    if (are_cheddar) std::cout << "cheddar ";
    std::cout << " | sosuri: ";
    if (are_ketchup) std::cout << "ketchup ";
    if (are_maioneza) std::cout << "maioneza ";
    if (are_mustar) std::cout << "mustar ";
    if (are_bbq) std::cout << "bbq ";
    std::cout << "\n";
}

// Getteri
bool Burger::getAreChiflaSesame() const { return are_chifla_sesame; }
bool Burger::getAreChiflaSimpla() const { return are_chifla_simpla; }
bool Burger::getAreCarneVita() const { return are_carne_vita; }
bool Burger::getAreCarnePui() const { return are_carne_pui; }
bool Burger::getAreCarnePorc() const { return are_carne_porc; }
bool Burger::getAreSalata() const { return are_salata; }
bool Burger::getAreRosii() const { return are_rosii; }
bool Burger::getAreCeapa() const { return are_ceapa; }
bool Burger::getAreCastraveti() const { return are_castraveti; }
bool Burger::getAreCheddar() const { return are_cheddar; }
bool Burger::getAreKetchup() const { return are_ketchup; }
bool Burger::getAreMaioneza() const { return are_maioneza; }
bool Burger::getAreMustar() const { return are_mustar; }
bool Burger::getAreBbq() const { return are_bbq; }

// Setteri
void Burger::setAreChiflaSesame(bool val) { are_chifla_sesame = val; }
void Burger::setAreChiflaSimpla(bool val) { are_chifla_simpla = val; }
void Burger::setAreCarneVita(bool val) { are_carne_vita = val; }
void Burger::setAreCarnePui(bool val) { are_carne_pui = val; }
void Burger::setAreCarnePorc(bool val) { are_carne_porc = val; }
void Burger::setAreSalata(bool val) { are_salata = val; }
void Burger::setAreRosii(bool val) { are_rosii = val; }
void Burger::setAreCeapa(bool val) { are_ceapa = val; }
void Burger::setAreCastraveti(bool val) { are_castraveti = val; }
void Burger::setAreCheddar(bool val) { are_cheddar = val; }
void Burger::setAreKetchup(bool val) { are_ketchup = val; }
void Burger::setAreMaioneza(bool val) { are_maioneza = val; }
void Burger::setAreMustar(bool val) { are_mustar = val; }
void Burger::setAreBbq(bool val) { are_bbq = val; }