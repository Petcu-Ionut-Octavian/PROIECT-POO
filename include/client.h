#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "meniu.h"
#include "produs.h"
#include "cartofi.h"
#include "pizza.h"
#include "shaorma.h"
#include "burger.h"

class Client {
private:
    int id;
    inline static int id_generator = 0;
    std::vector<std::shared_ptr<Produs>> comanda;

public:
    // Constructor & Destructor
    Client();
    ~Client();

    // Funcții builder pentru produse
    void build_cartofi(double pret_baza, bool ketchup=false, bool maioneza=false,
                       bool mustar=false, bool sos_picant=false);

    void build_pizza(double pret_baza, bool salam=false, bool ciuperci=false,
                     bool masline=false, bool extra_cheese=false,
                     bool ketchup=false, bool usturoi=false);

    void build_shaorma(double pret_baza, bool pui=false, bool vita=false, bool porc=false,
                       bool cartofi=false, bool salata=false, bool varza=false,
                       bool rosii=false, bool castraveti=false,
                       bool maioneza=false, bool ketchup=false);

    void build_burger(double pret_baza, bool carne_vita=false, bool carne_pui=false, bool carne_porc=false,
                      bool salata=false, bool rosii=false, bool ceapa=false,
                      bool castraveti=false, bool cheddar=false,
                      bool ketchup=false, bool maioneza=false, bool mustar=false);

    // Funcții utile
    void afiseazaComanda() const;
    double total() const;
};

#endif // CLIENT_HPP