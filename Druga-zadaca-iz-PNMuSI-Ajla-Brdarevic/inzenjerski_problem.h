#pragma once 

#ifndef INZENJERSKI_PROBLEM_H
#define INZENJERSKI_PROBLEM_H

#include <vector>
#include <iostream>
#include "gauss_jordan.h"
#include "matricna_metoda.h"
#include "GaussSeidel.h"

class InzenjerskiProblem {
public:
    // Konstruktor klase
    InzenjerskiProblem();

    // Funkcije za rješavanje sistema
    void rijesiGaussJordan();
    void rijesiMatricnaMetoda();
    void rijesiGaussSeidel();

    // Funkcija za ispis rezultata
    void ispisRezultata(const std::vector<double>& rjesenje);

private:
    // Atributi klase
    std::vector<std::vector<double>> matricaKoeficijenata;
    std::vector<double> vektorDesneStrane;

    // Konstante sistema
    double k1, k2, k3, k4, k5, k6;
    double G1, G2, G3, G4;
};

#endif