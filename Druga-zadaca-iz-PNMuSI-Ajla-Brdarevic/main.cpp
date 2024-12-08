#include <iostream>
#include "gauss_jordan.h"        
#include "matricna_metoda.h"      
#include "GaussSeidel.h"          
#include "TestProblemi.h"         
#include "inzenjerski_problem.h"  

// Funkcija za ispis glavnog menija sa dostupnim opcijama
void prikaziMeni() {
    std::cout << "\nOdabrati opciju:\n";
    std::cout << "1 - Gauss-Jordan metoda\n";           // Opcija za Gauss-Jordan metodu
    std::cout << "2 - Matricna metoda\n";               // Opcija za Matri�nu metodu
    std::cout << "3 - Gauss-Seidel metoda\n";           // Opcija za Gauss-Seidel metodu
    std::cout << "4 - Testiranje poznatih problema\n";  // Opcija za testiranje poznatih problema
    std::cout << "5 - Inzenjerski problem\n";           // Opcija za in�enjerski problem
    std::cout << "0 - Izlaz\n";                         // Opcija za izlaz iz programa
    std::cout << "\nIzbor: ";                           // Odabir opcije
}

int main() {
    int izbor;  // Varijabla za pohranu korisni�kog odabira

    do {
        prikaziMeni();      // Ispis menija sa opcijama
        std::cin >> izbor;  // �itanje korisni�kog unos

        // Na temelju korisni�kog odabira izvr�ava odgovaraju�i slu�aj
        switch (izbor) {
        case 1: {
            // Gauss-Jordan metoda
            int redovi, kolone;
            std::cout << "Unijeti broj redova i kolona (ukljucujuci desnu stranu sistema): ";
            std::cin >> redovi >> kolone;        // Korisnik unosi dimenzije matrice

            GaussJordan sistem(redovi, kolone);  // Kreira objekt za Gauss-Jordan metodu
            sistem.unesiMatricu();               // Unos matrice

            std::cout << "\nPocetna matrica:\n";
            sistem.prikaziMatricu();            // Ispisujemo po�etnu matricu

            sistem.gaussJordanEliminacija();    // Primjena Gauss-Jordan eliminaciju

            std::cout << "\nMatrica nakon Gauss-Jordan eliminacije\n";
            sistem.prikaziMatricu();            // Ispis matrice nakon eliminacije

            std::cout << "\nRjesenja nakon Gauss-Jordan eliminacije\n";
            sistem.prikaziRjesenja();           // Ispis rje�enja sistema
            std::cout << "_________________________________________\n";
            break;
        }
        case 2: {
            // Matricna metoda
            int brojJednacina;
            std::cout << "Unijeti broj jednacina: ";
            std::cin >> brojJednacina;          // Korisnik unosi broj jedna�ina

            MatricnaMetoda metoda(brojJednacina);  // Kreiranje objekta za matricnu metodu
            metoda.unosMatrice();               // Unosimo matricu

            std::vector<std::vector<double>> inverzna, prosirena;
            if (metoda.racunajInverznu(inverzna, prosirena)) {  // Ra�unanje inverzne matricu
                std::vector<double> rjesenje = metoda.dobijRjesenje(inverzna);  // Ra�unanje rje�enje

                std::cout << "\nRjesenje sistema:\n";
                for (int i = 0; i < brojJednacina; i++) {
                    std::cout << "x" << i + 1 << " = " << rjesenje[i] << "\n";  // Ispis rje�enja sistema
                }
                std::cout << "_________________________________________\n";
            }
            else {
                std::cerr << "Neuspjeh pri racunanju inverzne matrice.\n";
            }
            break;
        }
        case 3: {
            // Gauss-Seidel metoda
            int brojJednacina;
            double relaksacija, tacnost;
            const int maxIteracije = 800;  // Maksimalan broj iteracija

            std::cout << "Unijeti broj jednacina: ";
            std::cin >> brojJednacina;  // Korisnik unosi broj jedna�ina

            std::cout << "Unijeti koeficijent relaksacije (0 < w <= 2): ";
            std::cin >> relaksacija;  // Unos koeficijenta relaksacije

            std::cout << "Unijeti tacnost (epsilon): ";
            std::cin >> tacnost;  // Unos ta�nosti

            GaussSeidel metoda(brojJednacina, relaksacija, tacnost, maxIteracije);  // Kreira objekat za Gauss-Seidel metodu
            metoda.unosPodataka();  // Unos podataka
            metoda.pokreniMetodu();
            break;
        }
        case 4:
            // Testiranje poznatih problema
            TestProblemi test;
            test.testGaussJordan();  // Gauss-Jordan metoda
            test.testMatricnaMetoda();  // Matri�na metoda
            test.testGaussSeidel();  // Gauss-Seidel metoda
            break;
        case 5: {
            // Inzenjerski problem
            InzenjerskiProblem problem;  // Kreiraj objekat klase

            // Pozivanje funkcija
            problem.rijesiGaussJordan();
            problem.rijesiMatricnaMetoda();
            problem.rijesiGaussSeidel();
            break;
        }
        case 0:
            std::cout << "Izlaz iz programa.\n";  // Ispis poruke pri izlazu iz programa
            break;
        default:
            std::cout << "Nepoznata opcija!\n";  // Ako korisnik unese nepoznatu opciju
            break;
        }
    } while (izbor != 0);  // Program traje dok korisnik ne odabere opciju za izlaz

    return 0;
}