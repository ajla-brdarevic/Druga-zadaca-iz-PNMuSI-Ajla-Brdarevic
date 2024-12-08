#pragma once

#ifndef GAUSS_JORDAN_H
#define GAUSS_JORDAN_H

#include <vector>
#include <iostream>

// Klasa GaussJordan za implementaciju Gauss-Jordan eliminacije
class GaussJordan {
public:
    std::vector<std::vector<double>> matrica; // Dvodimenzionalni vektor za èuvanje matrice sistema jednaèina
    int redovi, kolone;                       // Dimenzije matrice: broj redova (redovi) i broj kolona (kolone)

    // Konstruktor klase GaussJordan:
    // Prima broj redova i kolona matrice te ih postavlja kao poèetne vrijednosti atributa klase
    GaussJordan(int redovi, int kolone);

    // Funkcija za unos elemenata matrice:
    // Omoguæava unos elemente matrice putem konzole
    void unesiMatricu();

    // Funkcija za prikaz matrice:
    // Ispisuje trenutno stanje matrice na konzoli
    void prikaziMatricu();

    // Funkcija za izvoðenje Gauss-Jordan eliminacije:
    // Implementira algoritam za transformaciju matrice u reducirani oblik (Row Reduced Echelon Form, RREF)
    void gaussJordanEliminacija();

    // Funkcija za prikaz rješenja sistema:
    // Na osnovu reducirane matrice ispisuje rješenja sistema linearnih jednaèina
    void prikaziRjesenja();
};

#endif