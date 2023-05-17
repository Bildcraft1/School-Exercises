#include <iostream>
#include <string>

using namespace std;
const int MAX_SIZE = 20;

struct libro {
    int codice;
    char titolo[20];
    float prezzo;
    int numeropag;
};

bool inserisciLibro(libro libreria[], int &n) {
    if (n >= MAX_SIZE) {
        printf("Errore! Hai riempito del tutto la libreria");
        return false;
    } else {
        cout << "Inserisci codice libro";
        cin >> libreria[n].codice;
        printf("Inserisci titolo del libro");
        cin >> libreria[n].titolo;
        cin.ignore();
        printf("Inserisci prezzo");
        cin >> libreria[n].prezzo;
        printf("Inserisci numero pagine");
        cin >> libreria[n].numeropag;
        n++;
    }
    return true;
}

void stampaLibreria(libro libreria[], const int n) {
    for (int i = 0; i < n; i++) {
        cout << "________________________________";
        cout << "Codice: " << libreria[i].codice;
        cout << "Titolo: " << libreria[i].titolo;
        cout << "Prezzo: " << libreria[i].prezzo;
        cout << "Numero Pagine: " << libreria[i].numeropag;
    }
}


int main() {
    libro libreria[MAX_SIZE];
    int n = 0;

    inserisciLibro(libreria, n);
    stampaLibreria(libreria, n);

    return 0;
}
