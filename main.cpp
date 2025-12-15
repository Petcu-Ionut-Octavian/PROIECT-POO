#include "meniu.h"
#include "produs.h"
#include "cartofi.h"
#include "pizza.h"
#include "shaorma.h"
#include "burger.h"
#include "client.h"  //este suficient doar??

int main() {
    FastFoodMenu* menu = FastFoodMenu::getInstance();


    bool running = true;
    while(running){
        int optiune = 0;
        std::cout << "\n=== Meniu FastFood ===\n";
        std::cout << "1. Comanda noua\n";
        std::cout << "2. Iesire\n";
        std::cout << "Optiune: ";
        std::cin >> optiune;

        switch(optiune) {
            case 1: {
                Client client();

                bool comandaInCurs = true;
                while (comandaInCurs) {
                    int alegereProdus = 0;
                    std::cout << "\n--- Comanda pentru (cod client) " << numeClient << " ---\n";
                    std::cout << "1. Adauga Cartofi\n";
                    std::cout << "2. Adauga Pizza\n";
                    std::cout << "3. Adauga Shaorma\n";
                    std::cout << "4. Adauga Burger\n";
                    std::cout << "5. Afiseaza comanda\n";
                    std::cout << "6. Finalizeaza comanda\n";
                    std::cout << "7. Anuleaza comanda\n";
                    std::cout << "Optiune: ";
                    std::cin >> alegereProdus;

                    switch (alegereProdus) {
                        case 1:
                            client.build_cartofi(10.0); 
                            break;
                        case 2:
                            client.build_pizza(25.0); 
                            break;
                        case 3:
                            client.build_shaorma(20.0); 
                            break;
                        case 4:
                            client.build_burger(30.0); 
                            break;
                        case 5:
                            client.afiseazaComanda();
                            std::cout << "Total: " << client.total() << " lei\n";
                            break;
                        case 6:
                            std::cout << "Comanda finalizata pentru " << numeClient << "!\n";
                            client.afiseazaComanda();
                            std::cout << "Total de plata: " << client.total() << " lei\n";
                            comandaInCurs = false;
                            break;
                        case 7:
                            std::cout << "Comanda anulata!\n";
                            comandaInCurs = false;
                            break;
                        default:
                            std::cout << "Optiune invalida!\n";
                    }
                }

    return 0;
}
