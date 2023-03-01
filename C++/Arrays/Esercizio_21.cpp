#include <iostream>

using namespace std;

int menu() {
    int scelta = 0;
    cout << endl;
    cout << "1. Inzia inserimento dati" << endl;
    cout << "2. Leggi array" << endl;
    cout << "3. Copia array" << endl;
    cout << "0. Esci" << endl;
    cout << endl;
    cout << "Scelta: ";
    cin >> scelta;
    return scelta;
}

void caricaArray(int array[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << "Inserisci valore in posizione " << i << ": ";
        cin >> array[i];
    }
}

void leggiArray(int array[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << array[i] << ", ";
    }
}

void copiaArray(int source[], int destination[], int dim, int &counter, int limitePrimo, int limiteSecondo) {
    for (int i = 0; i < dim; i++) {
        if (source[i] >= limitePrimo && source[i] <= limiteSecondo) {
            destination[counter] = source[i];
            counter++;
        }
    }
}


int main() {
    int input = 0, counter = 0, scelta = 0;
    int limitePrimo = 0, limiteSecondo = 0;

    cout << "Esericizo 21" << endl;

    cout << "Inserisci grandezza Array: ";

    do {
        cin >> input;
    } while (input < 0);

    const int DIM = input;

    int vettore[DIM], vettoreCopia[DIM];

    do {

        scelta = menu();
        
        switch (scelta)
        {
        case 1:
            caricaArray(vettore, DIM);
            break;
        
        case 2:
            cout << "Array originale: " << endl;
            leggiArray(vettore, DIM);
            cout << endl;
            if (counter == 0) {
                cout << "Non hai ancora elaborato i dati" << endl;
            } else {
                cout << "Array applicando il massimo e minimo: " << endl;
                leggiArray(vettoreCopia, counter);
            }
            break;

        case 3:
            cout << "Inserisci primo limite: ";
            cin >> limitePrimo;
            cout << endl;
            cout << "Inserisci secondo limite: ";
            cin >> limiteSecondo;
            cout << endl;
            copiaArray(vettore, vettoreCopia, DIM, counter, limitePrimo, limiteSecondo);
            break;

        default:
            break;
        }

    } while (scelta != 0);

    return 0;
}