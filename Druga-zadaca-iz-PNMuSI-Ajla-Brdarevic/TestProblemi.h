#pragma once

#ifndef TEST_PROBLEMI_H  
#define TEST_PROBLEMI_H  

#include "gauss_jordan.h"  
#include "matricna_metoda.h"  
#include "GaussSeidel.h"  

// Definisanje klase TestProblemi
class TestProblemi {
public:
    // Funkcija za testiranje Gauss-Jordan metode
    void testGaussJordan();

    // Funkcija za testiranje Matriène metode
    void testMatricnaMetoda();

    // Funkcija za testiranje Gauss-Seidel metode
    void testGaussSeidel();
};

#endif