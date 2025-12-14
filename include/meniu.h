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
    std::vector<std::string> items;

    FastFoodMenu() = default;

public:
    virtual ~FastFoodMenu() = default;

    static FastFoodMenu* getInstance();

    friend std::ostream& operator<<(std::ostream& os, const FastFoodMenu& menu);
    friend std::istream& operator>>(std::istream& is, FastFoodMenu& menu);

    void addItem(const std::string& item);
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
    double pret;

public:
    Produs(const std::string& nume, double pret) : nume(nume), pret(pret) {}
    virtual ~Produs() = default;

    virtual void afiseaza() const = 0; // metodă abstractă
    double getPret() const { return pret; }
    std::string getNume() const { return nume; }
};

class Cartofi : public Produs {
public:
    Cartofi(double pret) : Produs("Cartofi", pret) {}
    void afiseaza() const override;
};

class Pizza : public Produs {
public:
    Pizza(double pret) : Produs("Pizza", pret) {}
    void afiseaza() const override;
};

class Shaorma : public Produs {
public:
    Shaorma(double pret) : Produs("Shaorma", pret) {}
    void afiseaza() const override;
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
