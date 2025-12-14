#include "meniu.h"

// =======================
// Singleton: FastFoodMenu
// =======================
FastFoodMenu* FastFoodMenu::instance = nullptr;

FastFoodMenu* FastFoodMenu::getInstance() {
    if (!instance) {
        instance = new FastFoodMenu();
    }
    return instance;
}

std::ostream& operator<<(std::ostream& os, const FastFoodMenu& menu) {
    os << "Meniu FastFood:\n";
    for (const auto& item : menu.items) {
        os << "- " << item << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, FastFoodMenu& menu) {
    std::string item;
    std::cout << "Introdu un produs pentru meniu: ";
    is >> item;
    menu.addItem(item);
    return is;
}

void FastFoodMenu::addItem(const std::string& item) {
    items.push_back(item);
}

void FastFoodMenu::showMenu() const {
    std::cout << *this;
}

// =======================
// Produs
// =======================
double Produs::getPretBaza() const { return pret_baza; }
std::string Produs::getNume() const { return nume; }
int Produs::getCantitate() const { return cantitate; }

void Produs::setPretBaza(double pret) { pret_baza = pret; }
void Produs::setNume(const std::string& numeNou) { nume = numeNou; }
void Produs::setCantitate(int grame) { cantitate = grame; }

// =======================
// Cartofi
// =======================
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

// =======================
// Pizza
// =======================
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

// =======================
// Shaorma
// =======================
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

    
