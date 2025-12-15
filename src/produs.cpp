// =======================
// Produs
// =======================

#include "produs.h"

ostream& operator<< (ostream& out, Produs& ob){
  ob.afiseaza();
  return out;
}

double Produs::getPretBaza() const { return pret_baza; }
std::string Produs::getNume() const { return nume; }
int Produs::getCantitate() const { return cantitate; }

void Produs::setPretBaza(double pret) { pret_baza = pret; }
void Produs::setNume(const std::string& numeNou) { nume = numeNou; }

void Produs::setCantitate(int grame) { cantitate = grame; }

