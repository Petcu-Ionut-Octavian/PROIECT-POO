// =======================
// Client
// =======================

#include "client.h"

// =======================
// Constructor & Destructor
// =======================
Client::Client() {
    id = ++id_generator;
}

Client::~Client() {
    // vectorul comanda se eliberează automat
}

// =======================
// Builder Cartofi
// =======================
void Client::build_cartofi() {
    auto c = std::make_shared<Cartofi>(10.0); // preț fix sau îl poți cere separat

    char raspuns;
    std::cout << "Doriti ketchup? (y/n): ";
    std::cin >> raspuns;
    c->setAreKetchup(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti maioneza? (y/n): ";
    std::cin >> raspuns;
    c->setAreMaioneza(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti mustar? (y/n): ";
    std::cin >> raspuns;
    c->setAreMustar(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti sos picant? (y/n): ";
    std::cin >> raspuns;
    c->setAreSosPicant(raspuns == 'y' || raspuns == 'Y');

    comanda.push_back(c);
}

// =======================
// Builder Pizza
// =======================
void Client::build_pizza() {
    auto p = std::make_shared<Pizza>(25.0);

    char raspuns;
    std::cout << "Doriti salam? (y/n): ";
    std::cin >> raspuns;
    p->setAreSalam(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti ciuperci? (y/n): ";
    std::cin >> raspuns;
    p->setAreCiuperci(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti masline? (y/n): ";
    std::cin >> raspuns;
    p->setAreMasline(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti extra branza? (y/n): ";
    std::cin >> raspuns;
    p->setAreExtraCheese(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti ketchup? (y/n): ";
    std::cin >> raspuns;
    p->setAreKetchup(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti usturoi? (y/n): ";
    std::cin >> raspuns;
    p->setAreUsturoi(raspuns == 'y' || raspuns == 'Y');

    comanda.push_back(p);
}

// =======================
// Builder Shaorma
// =======================
void Client::build_shaorma() {
    auto s = std::make_shared<Shaorma>(20.0);

    char raspuns;
    std::cout << "Doriti pui? (y/n): ";
    std::cin >> raspuns;
    s->setArePui(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti vita? (y/n): ";
    std::cin >> raspuns;
    s->setAreVita(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti porc? (y/n): ";
    std::cin >> raspuns;
    s->setArePorc(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti cartofi? (y/n): ";
    std::cin >> raspuns;
    s->setAreCartofi(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti salata? (y/n): ";
    std::cin >> raspuns;
    s->setAreSalata(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti varza? (y/n): ";
    std::cin >> raspuns;
    s->setAreVarza(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti rosii? (y/n): ";
    std::cin >> raspuns;
    s->setAreRosii(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti castraveti? (y/n): ";
    std::cin >> raspuns;
    s->setAreCastraveti(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti maioneza? (y/n): ";
    std::cin >> raspuns;
    s->setAreMaioneza(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti ketchup? (y/n): ";
    std::cin >> raspuns;
    s->setAreKetchup(raspuns == 'y' || raspuns == 'Y');

    comanda.push_back(s);
}

// =======================
// Builder Burger
// =======================
void Client::build_burger() {
    auto b = std::make_shared<Burger>(30.0);

    char raspuns;
    std::cout << "Doriti carne vita? (y/n): ";
    std::cin >> raspuns;
    b->setAreCarneVita(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti carne pui? (y/n): ";
    std::cin >> raspuns;
    b->setAreCarnePui(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti carne porc? (y/n): ";
    std::cin >> raspuns;
    b->setAreCarnePorc(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti salata? (y/n): ";
    std::cin >> raspuns;
    b->setAreSalata(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti rosii? (y/n): ";
    std::cin >> raspuns;
    b->setAreRosii(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti ceapa? (y/n): ";
    std::cin >> raspuns;
    b->setAreCeapa(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti castraveti? (y/n): ";
    std::cin >> raspuns;
    b->setAreCastraveti(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti cheddar? (y/n): ";
    std::cin >> raspuns;
    b->setAreCheddar(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti ketchup? (y/n): ";
    std::cin >> raspuns;
    b->setAreKetchup(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti maioneza? (y/n): ";
    std::cin >> raspuns;
    b->setAreMaioneza(raspuns == 'y' || raspuns == 'Y');

    std::cout << "Doriti mustar? (y/n): ";
    std::cin >> raspuns;
    b->setAreMustar(raspuns == 'y' || raspuns == 'Y');

    comanda.push_back(b);
}

// =======================
// Afișare Comandă
// =======================
void Client::afiseazaComanda() const {
    std::cout << "Client ID: " << id << "\n";
    for (const auto& produs : comanda) {
        produs->afiseaza();
    }
}

// =======================
// Total
// =======================
double Client::total() const {
    double suma = 0.0;
    for (const auto& produs : comanda) {
        suma += produs->getPretBaza();
    }
    return suma;
}