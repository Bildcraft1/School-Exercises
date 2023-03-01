#include <iostream>

using namespace std;

int menu() {
    int scelta = 0;
    cout << endl;
    cout << "1. Inzia inserimento dati" << endl;
    cout << "2. Leggi array" << endl;
    cout << "0. Esci" << endl;
    cout << endl;
    cout << "Scelta: ";
    cin >> scelta;
    return scelta;
}

/*
Elabora i dati misurati usando uno switch
*/

void elaboraDati(double misure[], int dim) {
    double tempMisure[dim];

    for (int i = 0; i < dim; i++) {
        tempMisure[i] = misure[i];
    }

    for (int i = 0; i < dim; i++) {
        switch(i) {
        
        case 0:
            misure[i] = (tempMisure[i] + tempMisure[i] + tempMisure[i+1]) / 3;
            break;

        case 10:
            misure[i] = (tempMisure[i] + tempMisure[i] + tempMisure[i-1]) / 3;
            break;

        default:
            misure[i] = (tempMisure[i] + tempMisure[i-1] + tempMisure[i+1]) / 3;
            break;

        }
    }
}

void caricaArray(double misure[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << "Inserisci valore in posizione " << i << ": ";
        cin >> misure[i];
    }
}

void leggiArray(double misure[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << misure[i] << ", ";
    }
}

int main() {
    const int MAX_DIM = 10;
    double misure[MAX_DIM];
    int scelta = 0;

    cout << "Misuratore Database" << endl;
    
    do {

        scelta = menu();
        
        switch (scelta)
        {
        case 1:
            caricaArray(misure, MAX_DIM);
            elaboraDati(misure, MAX_DIM);
            break;
        
        case 2:
            leggiArray(misure, MAX_DIM);
            break;

        default:
            break;
        }

    } while (scelta != 0);


    return 0;
}