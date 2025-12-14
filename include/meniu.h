#ifndef FASTFOOD_HPP
#define FASTFOOD_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// =======================
// Singleton: FastFoodMenu
// =======================
class FastFoodMenu {
private:
    static FastFoodMenu* instance;

    FastFoodMenu() = default;

public:
    virtual ~FastFoodMenu() = default;

    static FastFoodMenu* getInstance();

    friend std::ostream& operator<<(std::ostream& os, const FastFoodMenu& menu);
    friend std::istream& operator>>(std::istream& is, FastFoodMenu& menu);

    void showMenu() const;
};

// =======================
// Builder: Burger
// =======================
class Burger {
private:
    std::string bun;
    std::string meat;
    std::string sauce;
    std::vector<std::string> extras;

public:
    Burger() = default;
    Burger(const std::string& bun, const std::string& meat);
    Burger(const Burger& other);
    Burger& operator=(const Burger& other);
    ~Burger();

    friend std::ostream& operator<<(std::ostream& os, const Burger& b);
    friend std::istream& operator>>(std::istream& is, Burger& b);

    bool operator==(const Burger& other) const;
    friend Burger operator+(const Burger& a, const Burger& b);
};

class BurgerBuilder {
private:
    Burger burger;

public:
    BurgerBuilder& setBun(const std::string& bun);
    BurgerBuilder& setMeat(const std::string& meat);
    BurgerBuilder& setSauce(const std::string& sauce);
    BurgerBuilder& addExtra(const std::string& extra);

    Burger build();
};

// =======================
// Ierarhie: Produs
// =======================
class Produs {
protected:
    std::string nume;
    double pret_baza;
    int cantitate; // grame

public:
    Produs(const std::string& nume, double pret_baza) : nume(nume), pret_baza(pret_baza) {}
    virtual ~Produs() = default;

    virtual void afiseaza() const = 0; // metodă abstractă

    // Getteri
    double getPretBaza() const;
    std::string getNume() const;
    int getCantitate() const;

    // Setteri
    void setPretBaza(double pret);
    void setNume(const std::string& numeNou);
    void setCantitate(int grame);
};

class Cartofi final : public Produs {
private:
    bool are_ketchup;
    bool are_maioneza;
    bool are_mustar;
    bool are_sos_picant;

public:
    Cartofi(double pret_baza) : Produs("Cartofi", pret_baza) {}

    void afiseaza() const override;

    // Getteri
    bool getAreKetchup() const;
    bool getAreMaioneza() const;
    bool getAreMustar() const;
    bool getAreSosPicant() const;

    // Setteri
    void setAreKetchup(bool val);
    void setAreMaioneza(bool val);
    void setAreMustar(bool val);
    void setAreSosPicant(bool val);
};

class Pizza final : public Produs {
private:
    bool are_salam;
    bool are_ciuperci;
    bool are_masline;
    bool are_extra_cheese;
    bool are_ketchup;
    bool are_usturoi;

public:
    Pizza(double pret_baza) : Produs("Pizza", pret_baza) {}

    void afiseaza() const override;

    // Getteri
    bool getAreSalam() const;
    bool getAreCiuperci() const;
    bool getAreMasline() const;
    bool getAreExtraCheese() const;
    bool getAreKetchup() const;
    bool getAreUsturoi() const;

    // Setteri
    void setAreSalam(bool val);
    void setAreCiuperci(bool val);
    void setAreMasline(bool val);
    void setAreExtraCheese(bool val);
    void setAreKetchup(bool val);
    void setAreUsturoi(bool val);
};

class Shaorma final : public Produs {
private:
    bool are_pui;
    bool are_vita;
    bool are_porc;
    bool are_cartofi;
    bool are_salata;
    bool are_varza;
    bool are_rosii;
    bool are_castraveti;
    bool are_maioneza;
    bool are_ketchup;

public:
    Shaorma(double pret_baza) : Produs("Shaorma", pret_baza) {}

    void afiseaza() const override;

    // Getteri
    bool getArePui() const;
    bool getAreVita() const;
    bool getArePorc() const;
    bool getAreCartofi() const;
    bool getAreSalata() const;
    bool getAreVarza() const;
    bool getAreRosii() const;
    bool getAreCastraveti() const;
    bool getAreMaioneza() const;
    bool getAreKetchup() const;

    // Setteri
    void setArePui(bool val);
    void setAreVita(bool val);
    void setArePorc(bool val);
    void setAreCartofi(bool val);
    void setAreSalata(bool val);
    void setAreVarza(bool val);
    void setAreRosii(bool val);
    void setAreCastraveti(bool val);
    void setAreMaioneza(bool val);
    void setAreKetchup(bool val);
};

// =======================
// Obiect: Client
// =======================
class Client {
private:
    std::string nume;
    std::vector<std::shared_ptr<Produs>> comanda;

public:
    Client(const std::string& nume);
    ~Client();

    void adaugaProdus(const std::shared_ptr<Produs>& produs);
    void afiseazaComanda() const;
    double total() const;
};

#endif // FASTFOOD_HPP
