#include <iostream>
#include <random>

using namespace std;

const int R = 10, C = 10; // dimensione massima della matrice

random_device rd;
mt19937 gen(rd());

int menu(bool matriceInserita) {
    int scelta;

    cout << "========================" << endl;
    cout << "      Ordina Matrice    " << endl;
    cout << "========================" << endl;

    if (matriceInserita) {
        cout << "1. Inserisci matrice" << endl;
        cout << "2. Stampa matrice" << endl;
        cout << "3. Ordina matrice" << endl;
        cout << "4. Carica random" << endl;
    } else {
        cout << "1. Inserisci matrice" << endl;
        cout << "4. Carica random" << endl;
    }

    cout << "0. Esci" << endl;
    cout << "Scelta >> ";
    cin >> scelta;
    return scelta;
}

bool caricaMatrice(int matrice[R][C], int righe, int colonne) {
    if (righe < 1 || righe > R || colonne < 1 || colonne > C) {
        return false;
    }
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            cout << "Inserisci il valore in posizione (" << i << ", " << j << "): ";
            cin >> matrice[i][j];
        }
    }
    return true;
}

void stampaMatrice(const int matrice[R][C], int righe, int colonne) {
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
}

void scambia(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void ordinaMatrice(int matrice[R][C], int righe, int colonne) {
    int temp;
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            for (int k = 0; k < righe; k++) {
                for (int l = 0; l < colonne; l++) {
                    if (matrice[i][j] < matrice[k][l]) {
                        scambia(matrice[i][j], matrice[k][l]);
                    }
                }
            }
        }
    }
}

void caricaRandom(int matrice[R][C], int righe, int colonne) {
    uniform_int_distribution<> dis(-100, 100);
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            matrice[i][j] = dis(gen);
        }
    }
}

int main() {
    int matrice[R][C], righe, colonne;
    bool matriceInserita = false;

    cout << "Inserisci il numero di righe: ";
    cin >> righe;
    while (righe < 1 || righe > R) {
        cout << "Il numero di righe deve essere compreso tra 1 e " << R << endl;
        cout << "Inserisci il numero di righe: ";
        cin >> righe;
    }
    
    cout << "Inserisci il numero di colonne: ";
    cin >> colonne;
    while (colonne < 1 || colonne > R) {
        cout << "Il numero di colonne deve essere compreso tra 1 e " << C << endl;
        cout << "Inserisci il numero di colonne: ";
        cin >> colonne;
    }

    int scelta = menu(matriceInserita);
    while (scelta != 0) {
        switch (scelta) {
            case 1:
                if (caricaMatrice(matrice, righe, colonne)) {
                    matriceInserita = true;
                } else {
                    cout << "Errore nell'inserimento della matrice" << endl;
                }
                break;
            case 2:
                if (!matriceInserita) {
                    cout << "La matrice non e' stata inserita" << endl;
                    break;
                }
                stampaMatrice(matrice, righe, colonne);
                break;
            case 3:
                if (!matriceInserita) {
                    cout << "La matrice non e' stata inserita" << endl;
                    break;
                }
                ordinaMatrice(matrice, righe, colonne);
                break;
            case 4:
                caricaRandom(matrice, righe, colonne);
                matriceInserita = true;
                break;
            default:
                cout << "Scelta non valida" << endl;
                break;
        }
        scelta = menu(matriceInserita);
    }

}