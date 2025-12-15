// =======================
// Cartofi
// =======================

#include "cartofi.h"

void Cartofi::afiseaza() const {
    std::cout << nume << " (" << pret_baza << " lei, " << cantitate << "g)";
    std::cout << " cu sosuri: ";
    if (are_ketchup) std::cout << "ketchup ";
    if (are_maioneza) std::cout << "maioneza ";
    if (are_mustar) std::cout << "mustar ";
    if (are_sos_picant) std::cout << "sos picant ";
    std::cout << "\n";
}

bool Cartofi::getAreKetchup() const { return are_ketchup; }
bool Cartofi::getAreMaioneza() const { return are_maioneza; }
bool Cartofi::getAreMustar() const { return are_mustar; }
bool Cartofi::getAreSosPicant() const { return are_sos_picant; }

void Cartofi::setAreKetchup(bool val) { are_ketchup = val; }
void Cartofi::setAreMaioneza(bool val) { are_maioneza = val; }
void Cartofi::setAreMustar(bool val) { are_mustar = val; }
void Cartofi::setAreSosPicant(bool val) { are_sos_picant = val; }