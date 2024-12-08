#pragma once

#ifndef GAUSS_SEIDEL_H
#define GAUSS_SEIDEL_H

#include <vector> 
#include <iostream> 

class GaussSeidel {
public:
    int brojJednacina;                                      // Broj linearnih jednaèina u sistemu
    std::vector<std::vector<double>> matricaKoeficijenata;  // Matrica koeficijenata sistema linearnih jednaèina
    std::vector<double> nehomogeniClanovi;                  // Vektor nehomogenih èlanova (desna strana sistema)
    std::vector<double> aproksimacija;                      // Trenutna aproksimacija rješenja sistema
    double koeficijentRelaksacije;                          // Koeficijent relaksacije za iterativni postupak
    double tacnost;                                         // Maksimalna dopuštena greška za zaustavljanje iteracija
    int maxIteracija;                                       // Maksimalni broj iteracija

    // Funkcija koja provjerava da li je matrica koeficijenata konvergentna:
    // Vraæa true ako metoda može konvergirati, inaèe vraæa false
    bool provjeriKonvergenciju();

    // Konstruktor:
    // Inicijalizuje parametre metode kao što su broj jednaèina, relaksacija, taènost i maksimalni broj iteracija
    GaussSeidel(int broj, double relaksacija, double eps, int maxIter);

    // Funkcija za unos podataka:
    // Omoguæava unos matrice koeficijenata i vektor nehomogenih èlanova
    void unosPodataka();

    // Funkcija za pokretanje Gauss-Seidel metode
    void pokreniMetodu();
};

#endif