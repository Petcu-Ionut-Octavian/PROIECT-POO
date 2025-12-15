// =======================
// Pizza
// =======================

#include "pizza.h"

void Pizza::afiseaza() const {
    std::cout << nume << " (" << pret_baza << " lei, " << cantitate << "g)";
    std::cout << " cu toppinguri: ";
    if (are_salam) std::cout << "salam ";
    if (are_ciuperci) std::cout << "ciuperci ";
    if (are_masline) std::cout << "masline ";
    if (are_extra_cheese) std::cout << "extra branza ";
    std::cout << " | sosuri: ";
    if (are_ketchup) std::cout << "ketchup ";
    if (are_usturoi) std::cout << "usturoi ";
    std::cout << "\n";
}

bool Pizza::getAreSalam() const { return are_salam; }
bool Pizza::getAreCiuperci() const { return are_ciuperci; }
bool Pizza::getAreMasline() const { return are_masline; }
bool Pizza::getAreExtraCheese() const { return are_extra_cheese; }
bool Pizza::getAreKetchup() const { return are_ketchup; }
bool Pizza::getAreUsturoi() const { return are_usturoi; }

void Pizza::setAreSalam(bool val) { are_salam = val; }
void Pizza::setAreCiuperci(bool val) { are_ciuperci = val; }
void Pizza::setAreMasline(bool val) { are_masline = val; }
void Pizza::setAreExtraCheese(bool val) { are_extra_cheese = val; }
void Pizza::setAreKetchup(bool val) { are_ketchup = val; }
void Pizza::setAreUsturoi(bool val) { are_usturoi = val; }