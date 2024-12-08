#include "inzenjerski_problem.h"

InzenjerskiProblem::InzenjerskiProblem() {
    // Inicijalizacija konstanti sistema (k1, k2, k3,...)
    k1 = 12; // Koeficijent za prvu jednačinu
    k2 = 12; // Koeficijent za drugu jednačinu
    k3 = 8;  // Koeficijent za treću jednačinu
    k4 = 12; // Koeficijent za četvrtu jednačinu
    k5 = 12; // Koeficijent za petu jednačinu
    k6 = 12; // Koeficijent za šestu jednačinu

    // Inicijalizacija G konstanti (nepoznati članovi)
    G1 = 6;  // G1 je vrijednost za prvu jednačinu
    G2 = 12; // G2 je vrijednost za drugu jednačinu
    G3 = 8;  // G3 je vrijednost za treću jednačinu
    G4 = 6;  // G4 je vrijednost za četvrtu jednačinu

    // Inicijalizacija matrice koeficijenata sistema
    matricaKoeficijenata = {
        {k1 + k2 + k3, -k2, -k3, 0},   // Prvi red matrice
        {-k2, k2 + k4, -k3, -k4},      // Drugi red matrice
        {-k3, -k4, k3 + k5 + k6, -k5}, // Treći red matrice
        {0, -k4, -k5, k4 + k6}         // Četvrti red matrice
    };

    // Inicijalizacija vektora desne strane sistema
    vektorDesneStrane = { G1, G2, G3, G4 };
}

// Funkcija koja koristi Gauss-Jordan metodu za rješavanje sistema
void InzenjerskiProblem::rijesiGaussJordan() {
    // Kreiranje objekta klase GaussJordan sa veličinom matrice koeficijenata
    GaussJordan gaussJordan(matricaKoeficijenata.size(), matricaKoeficijenata[0].size());
    gaussJordan.matrica = matricaKoeficijenata; // Postavljanje matrice koeficijenata
    gaussJordan.gaussJordanEliminacija();       // Pozivanje funkcije za Gauss-Jordan eliminaciju
    gaussJordan.prikaziRjesenja();              // Ispis rezultata rješenja
}

// Funkcija koja koristi matricnu metodu za rješavanje sistema
void InzenjerskiProblem::rijesiMatricnaMetoda() {
    // Kreiranje objekta klase MatricnaMetoda sa veličinom matrice koeficijenata
    MatricnaMetoda matricnaMetoda(matricaKoeficijenata.size());
    matricnaMetoda.matrica = matricaKoeficijenata;        // Postavljanje matrice koeficijenata
    matricnaMetoda.vektorDesneStrane = vektorDesneStrane; // Postavljanje vektora desne strane

    std::vector<std::vector<double>> inverzna; // Vektor za pohranu inverzne matrice
    std::vector<std::vector<double>> prosirena; // Vektor za pohranu proširene matrice
    // Pozivanje funkcije za izračunavanje inverzne matrice i proširene matrice
    if (matricnaMetoda.racunajInverznu(inverzna, prosirena)) {
        // Ako je inverzija uspješna
        std::vector<double> rjesenje = matricnaMetoda.dobijRjesenje(inverzna);
        ispisRezultata(rjesenje); // Ispis rezultata rješenja
    }
}

// Funkcija koja koristi Gauss-Seidel metodu za rješavanje sistema
void InzenjerskiProblem::rijesiGaussSeidel() {
    // Kreiranje objekta klase GaussSeidel sa potrebnim parametrima
    GaussSeidel gaussSeidel(matricaKoeficijenata.size(), 1.0, 0.0001, 100);
    gaussSeidel.matricaKoeficijenata = matricaKoeficijenata; // Postavljanje matrice koeficijenata
    gaussSeidel.nehomogeniClanovi = vektorDesneStrane;       // Postavljanje vektora desne strane
    gaussSeidel.pokreniMetodu();                             // Pokretanje metode Gauss-Seidel
}

// Funkcija koja ispisuje rješenja sistema
void InzenjerskiProblem::ispisRezultata(const std::vector<double>& rjesenje) {
    std::cout << "Rješenja sistema:\n";
    // Ispis svih rješenja sa odgovarajućim indeksima (x1, x2, ...)
    for (size_t i = 0; i < rjesenje.size(); i++) {
        std::cout << "x" << i + 1 << " = " << rjesenje[i] << "\n";
    }
}
