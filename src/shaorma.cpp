// =======================
// Shaorma
// =======================

#include "shaorma.h"

void Shaorma::afiseaza() const {
    std::cout << nume << " (" << pret_baza << " lei, " << cantitate << "g)";
    std::cout << " cu: ";
    if (are_pui) std::cout << "pui ";
    if (are_vita) std::cout << "vita ";
    if (are_porc) std::cout << "porc ";
    if (are_cartofi) std::cout << "cartofi ";
    if (are_salata) std::cout << "salata ";
    if (are_varza) std::cout << "varza ";
    if (are_rosii) std::cout << "rosii ";
    if (are_castraveti) std::cout << "castraveti ";
    std::cout << " | sosuri: ";
    if (are_maioneza) std::cout << "maioneza ";
    if (are_ketchup) std::cout << "ketchup ";
    std::cout << "\n";
}

bool Shaorma::getArePui() const { return are_pui; }
bool Shaorma::getAreVita() const { return are_vita; }
bool Shaorma::getArePorc() const { return are_porc; }
bool Shaorma::getAreCartofi() const { return are_cartofi; }
bool Shaorma::getAreSalata() const { return are_salata; }
bool Shaorma::getAreVarza() const { return are_varza; }
bool Shaorma::getAreRosii() const { return are_rosii; }
bool Shaorma::getAreCastraveti() const { return are_castraveti; }
bool Shaorma::getAreMaioneza() const { return are_maioneza; }
bool Shaorma::getAreKetchup() const { return are_ketchup; }

void Shaorma::setArePui(bool val) { are_pui = val; }
void Shaorma::setAreVita(bool val) { are_vita = val; }
void Shaorma::setArePorc(bool val) { are_porc = val; }
void Shaorma::setAreCartofi(bool val) { are_cartofi = val; }
void Shaorma::setAreSalata(bool val) { are_salata = val; }
void Shaorma::setAreVarza(bool val) { are_varza = val; }
void Shaorma::setAreRosii(bool val) { are_rosii = val; }
void Shaorma::setAreCastraveti(bool val) { are_castraveti = val; }
void Shaorma::setAreMaioneza(bool val) { are_maioneza = val; }
void Shaorma::setAreKetchup(bool val) { are_ketchup = val; }