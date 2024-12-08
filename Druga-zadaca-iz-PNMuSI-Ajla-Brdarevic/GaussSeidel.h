#pragma once

#ifndef GAUSS_SEIDEL_H
#define GAUSS_SEIDEL_H

#include <vector> 
#include <iostream> 

class GaussSeidel {
public:
    int brojJednacina;                                      // Broj linearnih jedna�ina u sistemu
    std::vector<std::vector<double>> matricaKoeficijenata;  // Matrica koeficijenata sistema linearnih jedna�ina
    std::vector<double> nehomogeniClanovi;                  // Vektor nehomogenih �lanova (desna strana sistema)
    std::vector<double> aproksimacija;                      // Trenutna aproksimacija rje�enja sistema
    double koeficijentRelaksacije;                          // Koeficijent relaksacije za iterativni postupak
    double tacnost;                                         // Maksimalna dopu�tena gre�ka za zaustavljanje iteracija
    int maxIteracija;                                       // Maksimalni broj iteracija

    // Funkcija koja provjerava da li je matrica koeficijenata konvergentna:
    // Vra�a true ako metoda mo�e konvergirati, ina�e vra�a false
    bool provjeriKonvergenciju();

    // Konstruktor:
    // Inicijalizuje parametre metode kao �to su broj jedna�ina, relaksacija, ta�nost i maksimalni broj iteracija
    GaussSeidel(int broj, double relaksacija, double eps, int maxIter);

    // Funkcija za unos podataka:
    // Omogu�ava unos matrice koeficijenata i vektor nehomogenih �lanova
    void unosPodataka();

    // Funkcija za pokretanje Gauss-Seidel metode
    void pokreniMetodu();
};

#endif