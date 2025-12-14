#include <iostream>
#include <memory>
#include "meniu.h"

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
                std::string numeClient;
                std::cout << "Introdu numele clientului: ";
                std::cin >> numeClient;
                Client client(numeClient);

                bool comandaInCurs = true;
                while(comandaInCurs) {
                    int alegereProdus = 0;
                    std::cout << "\n--- Comanda pentru (cod client) " << numeClient << " ---\n";
                    std::cout << "1. Adauga Cartofi\n";
                    std::cout << "2. Adauga Pizza\n";
                    std::cout << "3. Adauga Shaorma\n";
                    std::cout << "3. Adauga Hamburger\n";
                    std::cout << "4. Afiseaza comanda\n";
                    std::cout << "5. Finalizeaza comanda\n";
                    std::cout << "6. Anuleaza comanda\n";
                    std::cout << "Optiune: ";
                    std::cin >> alegereProdus;

                    switch(alegereProdus) {
                        case 1:
                            client.adaugaProdus(std::make_shared<Cartofi>(10.0));
                            break;
                        case 2:
                            client.adaugaProdus(std::make_shared<Pizza>(25.0));
                            break;
                        case 3:
                            client.adaugaProdus(std::make_shared<Shaorma>(20.0));
                            break;
                        case 4:
                            client.afiseazaComanda();
                            std::cout << "Total: " << client.total() << " lei\n";
                            break;
                        case 5:
                            std::cout << "Comanda finalizata pentru " << numeClient << "!\n";
                            client.afiseazaComanda();
                            std::cout << "Total de plata: " << client.total() << " lei\n";
                            comandaInCurs = false;
                            break;
                        case 6:
                            std::cout << "Comanda anulata!\n";
                            comandaInCurs = false;
                            break;
                        default:
                            std::cout << "Optiune invalida!\n";
                    }
                }
                break;
            }
            case 2: {
                running = false;
                std::cout << "La revedere!\n";
                break;
            }
            default:
                std::cout << "Optiune invalida!\n";
    }

    return 0;
}
