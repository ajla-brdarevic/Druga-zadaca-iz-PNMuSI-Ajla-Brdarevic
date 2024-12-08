#include "GaussSeidel.h"
#include <cmath> 
#include <iomanip> 

GaussSeidel::GaussSeidel(int broj, double relaksacija, double eps, int maxIter)
    : brojJednacina(broj),
    koeficijentRelaksacije(relaksacija),
    tacnost(eps),
    maxIteracija(maxIter) {
    // Inicijalizacija matrice koeficijenata s dimenzijama brojJednacina x brojJednacina
    matricaKoeficijenata.resize(brojJednacina, std::vector<double>(brojJednacina));
    // Inicijalizacija vektora nehomogenih �lanova
    nehomogeniClanovi.resize(brojJednacina);
    // Po�etna aproksimacija postavljena na 0 za sve elemente
    aproksimacija.resize(brojJednacina, 0.0);
}

bool GaussSeidel::provjeriKonvergenciju() {
    // Provjera dijagonalne dominacije matrice koeficijenata
    for (int i = 0; i < brojJednacina; i++) {
        double suma = 0.0;
        for (int j = 0; j < brojJednacina; j++) {
            if (i != j) {
                suma += fabs(matricaKoeficijenata[i][j]); // Zbir apsolutnih vrijednosti elemenata osim dijagonale
            }
        }
        // Ako dijagonalni element nije ve�i od zbira ostalih elemenata u redu, matrica nije dijagonalno dominantna
        if (fabs(matricaKoeficijenata[i][i]) <= suma) {
            return false;
        }
    }
    return true; // Matrica zadovoljava uslov dijagonalne dominacije
}

void GaussSeidel::unosPodataka() {
    std::cout << "\nUnijeti koeficijente matrice sistema:\n";
    for (int i = 0; i < brojJednacina; i++) {
        for (int j = 0; j < brojJednacina; j++) {
            std::cin >> matricaKoeficijenata[i][j]; // Unos svakog elementa matrice
        }
    }

    std::cout << "\nUnijeti vektor kolone nehomogenih clanova:\n";
    for (int i = 0; i < brojJednacina; i++) {
        std::cin >> nehomogeniClanovi[i]; // Unos svakog elementa vektora desne strane
    }
}

void GaussSeidel::pokreniMetodu() {
    // Provjera konvergencije prije pokretanja metode
    if (!provjeriKonvergenciju()) {
        std::cerr << "\nMatrica ne zadovoljava uslov konvergencije (dijagonalna dominacija).\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(6); // Postavljanje decimalne preciznosti
    std::cout << "\nIteracija\tAproksimacije\t\tMaksimalna greska\n";

    for (int iteracija = 1; iteracija <= maxIteracija; iteracija++) {
        std::vector<double> novaAproksimacija = aproksimacija; // Kopiranje trenutne aproksimacije
        double maksimalnaGreska = 0.0; // Po�etna vrijednost gre�ke

        for (int i = 0; i < brojJednacina; i++) {
            double suma = 0.0;
            for (int j = 0; j < brojJednacina; j++) {
                if (j != i) {
                    suma += matricaKoeficijenata[i][j] * novaAproksimacija[j]; // Izra�unavanje sume za i-tu jedna�inu
                }
            }

            // Izra�unavanje nove aproksimacije uz relaksaciju
            double novaVrijednost = (1 - koeficijentRelaksacije) * aproksimacija[i] +
                (koeficijentRelaksacije *
                    (nehomogeniClanovi[i] - suma) / matricaKoeficijenata[i][i]);

            // Pra�enje maksimalne gre�ke
            maksimalnaGreska = std::max(maksimalnaGreska, fabs(novaVrijednost - aproksimacija[i]));
            novaAproksimacija[i] = novaVrijednost; // A�uriranje aproksimacije za trenutnu iteraciju
        }

        aproksimacija = novaAproksimacija; // A�uriranje trenutne aproksimacije

        // Ispis rezultata za trenutnu iteraciju
        std::cout << iteracija << "\t\t";
        for (double x : aproksimacija) {
            std::cout << x << "\t";
        }
        std::cout << "\t" << maksimalnaGreska << "\n";

        // Provjera kriterija ta�nosti
        if (maksimalnaGreska < tacnost) {
            std::cout << "\nKriterij tacnosti zadovoljen nakon " << iteracija << " iteracija.\n";
            std::cout << "_________________________________________\n";
            return;
        }
    }

    // Ispis ako je dostignut maksimalan broj iteracija bez zadovoljenja ta�nosti
    std::cerr << "\nPostignut maksimalan broj iteracija (" << maxIteracija << ").\n";
}