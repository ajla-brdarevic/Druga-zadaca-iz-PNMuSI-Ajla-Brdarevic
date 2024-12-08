#include "matricna_metoda.h" 
#include <iomanip> 

// Konstruktor klase MatricnaMetoda
// Parametar brojJednacina definira broj redova i kolona matrice
MatricnaMetoda::MatricnaMetoda(int brojJednacina) : brojJednacina(brojJednacina) {
    // Inicijalizacija matrice sa zadanim brojem redova i kolona
    matrica.resize(brojJednacina, std::vector<double>(brojJednacina));
    // Inicijalizacija vektora desne strane s brojem elemenata jednakim broju jednaèina
    vektorDesneStrane.resize(brojJednacina);
}

// Funkcija za unos elemenata matrice i vektora desne strane
void MatricnaMetoda::unosMatrice() {
    std::cout << "Unijeti elemente matrice sistema:\n";
    // Petlja za unos elemenata matrice
    for (int i = 0; i < brojJednacina; i++) {
        for (int j = 0; j < brojJednacina; j++) {
            std::cin >> matrica[i][j]; // Unos svakog elementa matrice
        }
    }

    // Unos elemenata vektora desne strane
    std::cout << "\nUnijeti elemente vektora desne strane: ";
    for (int i = 0; i < brojJednacina; i++) {
        std::cin >> vektorDesneStrane[i]; // Unos svakog elementa vektora
    }
}

// Funkcija za ispis matrice
// Parametar mat sadrži matricu koja æe biti ispisana
void MatricnaMetoda::ispisMatrice(const std::vector<std::vector<double>>& mat) const {
    for (const auto& red : mat) {                    // Iteracija kroz svaki red matrice
        for (double el : red) {                      // Iteracija kroz svaki element u redu
            std::cout << std::setw(10) << el << " "; // Ispis elementa s formatiranjem širine polja
        }
        std::cout << "\n"; 
    }
}

// Funkcija za raèunanje inverzne matrice pomoæu Gauss-Jordan eliminacije
bool MatricnaMetoda::racunajInverznu(std::vector<std::vector<double>>& inverzna, std::vector<std::vector<double>>& prosirena) const {
    // Inicijalizacija inverzne matrice kao jediniène
    inverzna.assign(brojJednacina, std::vector<double>(brojJednacina, 0.0));
    prosirena = matrica;      // Kopiranje matrice sistema u proširenu matricu
    for (int i = 0; i < brojJednacina; i++) {
        inverzna[i][i] = 1.0; // Postavljanje dijagonalnih elemenata na 1
    }

    // Poèetak Gauss-Jordan eliminacije
    for (int i = 0; i < brojJednacina; i++) {
        double dijagonalniElement = prosirena[i][i]; // Èuvanje dijagonalnog elementa
        if (dijagonalniElement == 0) {               // Provjera da li je matrica singularna
            std::cerr << "Greška: Matrica nije invertibilna.\n"; 
            return false;                            // Prekid ako nije moguæe izraèunati inverznu matricu
        }

        // Normalizacija reda - dijeljenje svih elemenata reda dijagonalnim elementom
        for (int j = 0; j < brojJednacina; j++) {
            prosirena[i][j] /= dijagonalniElement;
            inverzna[i][j] /= dijagonalniElement;
        }

        // Eliminacija elemenata u ostalim redovima
        for (int k = 0; k < brojJednacina; k++) {
            if (k != i) { // Preskakanje trenutnog reda
                double faktor = prosirena[k][i]; // Faktor za eliminaciju
                for (int j = 0; j < brojJednacina; j++) {
                    prosirena[k][j] -= faktor * prosirena[i][j];
                    inverzna[k][j] -= faktor * inverzna[i][j];
                }
            }
        }

        // Ispis trenutnog stanja proširene matrice
        std::cout << "\nTrenutno stanje prosirene matrice:\n";
        ispisMatrice(prosirena);
    }

    return true; // Inverzna matrica uspješno izraèunata
}

// Funkcija za dobijanje rješenja sistema linearnih jednaèina
std::vector<double> MatricnaMetoda::dobijRjesenje(const std::vector<std::vector<double>>& inverzna) const {
    std::vector<double> rjesenje(brojJednacina, 0.0); // Inicijalizacija vektora rješenja
    for (int i = 0; i < brojJednacina; i++) {
        for (int j = 0; j < brojJednacina; j++) {
            // Koristi elemente inverzne matrice i vektora desne strane za izraèunavanje rješenja
            rjesenje[i] += inverzna[i][j] * vektorDesneStrane[j];
        }
    }
    return rjesenje; // Vraæanje vektora rješenja
}