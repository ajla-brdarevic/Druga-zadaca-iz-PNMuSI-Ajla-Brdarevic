#include "TestProblemi.h" 
#include <iostream>  

void TestProblemi::testGaussJordan() {
    std::cout << "Testiranje Gauss-Jordan metode\n";
    std::cout << "_________________________________\n";

    // Kreiranje objekta za Gauss-Jordan metodu sa dimenzijama 3x4
    GaussJordan gaussJordan(3, 4);

    // Ulazni podaci - matrica koeficijenata sistema
    std::vector<std::vector<double>> matrica = {
        {80, -20, -20, 20},
        {-20, 40, -20, 20},
        {-20, -20, 130, 20}
    };

    // Unos matrice ruèno u objekt
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            gaussJordan.matrica[i][j] = matrica[i][j];

    // Ispisivanje matrice sistema
    std::cout << "Matrica:\n";
    for (size_t i = 0; i < matrica.size(); ++i) {
        for (size_t j = 0; j < matrica[i].size(); ++j) {
            std::cout << matrica[i][j] << " ";  // Ispisivanje elemenata matrice
        }
        std::cout << "\n";  
    }

    // Pozivanje metode za Gauss-Jordan eliminaciju
    gaussJordan.gaussJordanEliminacija();

    // Ispisivanje rješenja sistema
    gaussJordan.prikaziRjesenja();
}

void TestProblemi::testMatricnaMetoda() {
    std::cout << "\nTestiranje matricne metode\n";
    std::cout << "_________________________________\n";

    // Kreiranje objekta za Matriènu metodu sa dimenzijama 3
    MatricnaMetoda matricnaMetoda(3);

    // Ulazni podaci - matrica koeficijenata sistema
    std::vector<std::vector<double>> matrica = {
        {80, -20, -20, 20},
        {-20, 40, -20, 20},
        {-20, -20, 130, 20}
    };

    // Desna strana sistema
    std::vector<double> desnaStrana = { 20, 20, 20 };

    // Ispisivanje matrice sistema
    std::cout << "Matrica:\n";
    for (size_t i = 0; i < matrica.size(); ++i) {
        for (size_t j = 0; j < matrica[i].size(); ++j) {
            std::cout << matrica[i][j] << " ";  // Ispisivanje elemenata matrice
        }
        std::cout << "\n";  
    }

    // Dodavanje matrice i desne strane u objekt MatricnaMetoda
    matricnaMetoda.matrica = matrica;
    matricnaMetoda.vektorDesneStrane = desnaStrana;

    // Varijable za èuvanje inverzne matrice i proširene matrice
    std::vector<std::vector<double>> inverzna, prosirena;

    // Raèunanje inverzne matrice
    if (matricnaMetoda.racunajInverznu(inverzna, prosirena)) {
        // Dobijanje rješenja sistema korištenjem inverzne matrice
        auto rjesenja = matricnaMetoda.dobijRjesenje(inverzna);

        // Ispisivanje rješenja sistema
        std::cout << "\nRjesenja sistema:\n";
        for (size_t i = 0; i < rjesenja.size(); ++i) {
            std::cout << "x" << i + 1 << " = " << rjesenja[i] << "\n";  // Ispisivanje svakog rješenja
        }
    }
}

void TestProblemi::testGaussSeidel() {
    std::cout << "\nTestiranje Gauss-Seidel metode\n";
    std::cout << "_________________________________\n";

    // Kreiranje objekta za Gauss-Seidel metodu sa dimenzijama 5, poèetnim uslovima i kriterijumima
    GaussSeidel gaussSeidel(5, 1.0, 0.0001, 100);

    // Ulazni podaci - matrica koeficijenata sistema
    std::vector<std::vector<double>> matrica = {
        {4, -1, 0, 1, 0},
        {-1, 4, -1, 0, 1},
        {0, -1, 4, -1, 0},
        {1, 0, -1, 4, -1},
        {0, 1, 0, -1, 4}
    };

    // Desna strana sistema
    std::vector<double> desnaStrana = { 100, 100, 100, 100, 100 };

    // Ispisivanje matrice sistema
    std::cout << "Matrica:\n";
    for (size_t i = 0; i < matrica.size(); ++i) {
        for (size_t j = 0; j < matrica[i].size(); ++j) {
            std::cout << matrica[i][j] << " ";  // Ispisivanje elemenata matrice
        }
        std::cout << "\n";
    }

    // Ispisivanje desne strane sistema
    std::cout << "\nDesna strana:\n";
    for (size_t i = 0; i < desnaStrana.size(); ++i) {
        std::cout << desnaStrana[i] << " ";  // Ispisivanje elemenata desne strane
    }
    std::cout << "\n";

    // Dodavanje matrice i desne strane u objekt GaussSeidel
    gaussSeidel.matricaKoeficijenata = matrica;
    gaussSeidel.nehomogeniClanovi = desnaStrana;

    // Provjera da li matrica zadovoljava uslove za konvergenciju
    if (gaussSeidel.provjeriKonvergenciju()) {
        // Pokretanje Gauss-Seidel metode ako matrica zadovoljava uslov
        gaussSeidel.pokreniMetodu();
    }
    else {
        // Ispisivanje greške ako matrica ne zadovoljava uslov konvergencije
        std::cerr << "\nMatrica ne zadovoljava uslov konvergencije.\n";
    }
}