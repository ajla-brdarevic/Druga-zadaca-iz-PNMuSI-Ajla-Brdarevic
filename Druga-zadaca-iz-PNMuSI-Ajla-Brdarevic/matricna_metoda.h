#pragma once 

#ifndef MATRICNA_METODA_H 
#define MATRICNA_METODA_H

#include <vector> 
#include <iostream> 

class MatricnaMetoda {
public:
    std::vector<std::vector<double>> matrica; // 2D vektor koji predstavlja matricu sistema linearnih jedna�ina
    std::vector<double> vektorDesneStrane;    // Vektor koji sadr�i elemente desne strane sistema
    int brojJednacina;                        // Broj jedna�ina (ili varijabli) u sistemu

    // Konstruktor klase
    // Parametar brojJednacina koristi se za inicijalizaciju veli�ine matrice i pripadaju�ih struktura
    MatricnaMetoda(int brojJednacina);

    // O�ekuje unos elemenata matrice i vektora
    void unosMatrice();

    // Funkcija za ispis matrice na konzolu
    // Parametar mat je referenca na matricu koja �e biti ispisana
    // Ozna�ena je kao const jer ne mijenja stanje objekta
    void ispisMatrice(const std::vector<std::vector<double>>& mat) const;

    // Funkcija za ra�unanje inverzne matrice
    // Parametri inverzna i prosirena su reference na matrice koje se koriste tokom ra�unanja
    // Inverzna matrica �e se po potrebi popuniti rezultatom
    // Funkcija vra�a true ako je inverzna matrica uspje�no izra�unata, ina�e vra�a false
    bool racunajInverznu(std::vector<std::vector<double>>& inverzna, std::vector<std::vector<double>>& prosirena) const;

    // Funkcija za dobijanje rje�enja sistema koriste�i inverznu matricu
    // Parametar inverzna je referenca na unaprijed izra�unatu inverznu matricu
    // Funkcija vra�a vektor koji predstavlja rje�enje sistema linearnih jedna�ina
    std::vector<double> dobijRjesenje(const std::vector<std::vector<double>>& inverzna) const;
};

#endif