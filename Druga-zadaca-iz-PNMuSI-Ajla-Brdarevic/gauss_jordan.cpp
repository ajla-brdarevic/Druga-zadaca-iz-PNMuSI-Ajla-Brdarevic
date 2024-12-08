#include "gauss_jordan.h"

// Konstruktor klase GaussJordan:
// Inicijalizuje dimenzije matrice i alocira memoriju za dvodimenzionalni vektor
// Postavlja sve elemente matrice na po�etnu vrijednost 0
GaussJordan::GaussJordan(int redovi, int kolone) : redovi(redovi), kolone(kolone) {
    matrica.resize(redovi, std::vector<double>(kolone, 0)); // Kreiranje matrice zadane dimenzije i inicijalizacija na 0
}

// Funkcija za unos elemenata matrice:
// Omogu�ava unos vrijednosti za sve elemente matrice putem konzole
// Petlje prolaze kroz sve redove i kolone matrice radi popunjavanja
void GaussJordan::unesiMatricu() {
    std::cout << "\nUnijeti elemente matrice (" << redovi << "x" << kolone << "):\n";
    for (int i = 0; i < redovi; i++) {     // Iteracija kroz redove matrice
        for (int j = 0; j < kolone; j++) { // Iteracija kroz kolone matrice
            std::cin >> matrica[i][j];     // Unos pojedina�nog elementa matrice
        }
    }
}

// Funkcija za prikaz matrice:
// Ispisuje sve elemente matrice
// Petlja prolazi kroz svaki red i ispisuje njegove elemente
void GaussJordan::prikaziMatricu() {
    std::cout << "\nTrenutna matrica:\n";
    for (const auto& red : matrica) {   // Iteracija kroz svaki red matrice
        for (double elem : red) {       // Iteracija kroz svaki element unutar trenutnog reda
            std::cout << elem << " ";   // Ispis pojedina�nog elementa
        }
        std::cout << "\n";              
    }
}

// Funkcija za izvo�enje Gauss-Jordan eliminacije:
// Implementira algoritam za redukciju matrice u reducirani redni oblik (RREF)
// Sadr�i dva glavna koraka: normalizaciju glavnog elementa i eliminaciju ostalih elemenata u koloni
void GaussJordan::gaussJordanEliminacija() {
    for (int i = 0; i < redovi; i++) {  // Iteracija kroz redove matrice

        // 1. Normalizacija glavnog elementa:
        // Dijeli cijeli red s vrijedno��u glavnog elementa kako bi se postavio na 1
        double glavnaVrijednost = matrica[i][i];
        for (int j = 0; j < kolone; j++) {  // Iteracija kroz kolone trenutnog reda
            matrica[i][j] /= glavnaVrijednost;
        }

        // 2. Eliminacija ostalih elemenata u istoj koloni:
        // Postavlja sve ostale elemente u trenutnoj koloni na 0
        for (int k = 0; k < redovi; k++) {                      // Iteracija kroz sve ostale redove
            if (k != i) {                                       // Izbjegava trenutni red (ve� normalizovan)
                double faktor = matrica[k][i];                  // Faktor eliminacije
                for (int j = 0; j < kolone; j++) {              // Iteracija kroz kolone
                    matrica[k][j] -= faktor * matrica[i][j];    // A�uriranje elemenata reda
                }
            }
        }
    }
}

// Funkcija za prikaz rje�enja sistema linearnih jedna�ina:
// Na osnovu reducirane matrice, funkcija ispisuje vrijednosti nepoznatih (x1, x2, ..., xn)
void GaussJordan::prikaziRjesenja() {
    std::cout << "\nRjesenja sistema:\n";
    for (int i = 0; i < redovi; i++) {      // Iteracija kroz redove matrice
        // Ispisuje vrijednost posljednje kolone trenutnog reda kao rje�enje za nepoznatu x_i
        std::cout << "x" << i + 1 << " = " << matrica[i][kolone - 1] << "\n";
    }
}