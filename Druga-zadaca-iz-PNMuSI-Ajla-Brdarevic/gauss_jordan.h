#pragma once

#ifndef GAUSS_JORDAN_H
#define GAUSS_JORDAN_H

#include <vector>
#include <iostream>

// Klasa GaussJordan za implementaciju Gauss-Jordan eliminacije
class GaussJordan {
public:
    std::vector<std::vector<double>> matrica; // Dvodimenzionalni vektor za �uvanje matrice sistema jedna�ina
    int redovi, kolone;                       // Dimenzije matrice: broj redova (redovi) i broj kolona (kolone)

    // Konstruktor klase GaussJordan:
    // Prima broj redova i kolona matrice te ih postavlja kao po�etne vrijednosti atributa klase
    GaussJordan(int redovi, int kolone);

    // Funkcija za unos elemenata matrice:
    // Omogu�ava unos elemente matrice putem konzole
    void unesiMatricu();

    // Funkcija za prikaz matrice:
    // Ispisuje trenutno stanje matrice na konzoli
    void prikaziMatricu();

    // Funkcija za izvo�enje Gauss-Jordan eliminacije:
    // Implementira algoritam za transformaciju matrice u reducirani oblik (Row Reduced Echelon Form, RREF)
    void gaussJordanEliminacija();

    // Funkcija za prikaz rje�enja sistema:
    // Na osnovu reducirane matrice ispisuje rje�enja sistema linearnih jedna�ina
    void prikaziRjesenja();
};

#endif