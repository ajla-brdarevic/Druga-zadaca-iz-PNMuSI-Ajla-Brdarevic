#pragma once 

#ifndef MATRICNA_METODA_H 
#define MATRICNA_METODA_H

#include <vector> 
#include <iostream> 

class MatricnaMetoda {
public:
    std::vector<std::vector<double>> matrica; // 2D vektor koji predstavlja matricu sistema linearnih jednaèina
    std::vector<double> vektorDesneStrane;    // Vektor koji sadrži elemente desne strane sistema
    int brojJednacina;                        // Broj jednaèina (ili varijabli) u sistemu

    // Konstruktor klase
    // Parametar brojJednacina koristi se za inicijalizaciju velièine matrice i pripadajuæih struktura
    MatricnaMetoda(int brojJednacina);

    // Oèekuje unos elemenata matrice i vektora
    void unosMatrice();

    // Funkcija za ispis matrice na konzolu
    // Parametar mat je referenca na matricu koja æe biti ispisana
    // Oznaèena je kao const jer ne mijenja stanje objekta
    void ispisMatrice(const std::vector<std::vector<double>>& mat) const;

    // Funkcija za raèunanje inverzne matrice
    // Parametri inverzna i prosirena su reference na matrice koje se koriste tokom raèunanja
    // Inverzna matrica æe se po potrebi popuniti rezultatom
    // Funkcija vraæa true ako je inverzna matrica uspješno izraèunata, inaèe vraæa false
    bool racunajInverznu(std::vector<std::vector<double>>& inverzna, std::vector<std::vector<double>>& prosirena) const;

    // Funkcija za dobijanje rješenja sistema koristeæi inverznu matricu
    // Parametar inverzna je referenca na unaprijed izraèunatu inverznu matricu
    // Funkcija vraæa vektor koji predstavlja rješenje sistema linearnih jednaèina
    std::vector<double> dobijRjesenje(const std::vector<std::vector<double>>& inverzna) const;
};

#endif