#ifndef PRODUS_HPP
#define PRODUS_HPP

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

#endif