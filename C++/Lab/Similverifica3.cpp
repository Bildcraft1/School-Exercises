#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// Calcola media della variazione delle temperature
double mediaVariazione(double v[], int dim) {
    double media = 0;
    for (int i = 0; i < dim-1; i++) {
        media += v[i+1] - v[i];
    }
    return abs(media / (dim-1));
}


void caricaVettore(double v[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << "Inserisci valore in posizione " << i+1 << ":" << endl;
        cin >> v[i];
    }
}

void leggiVettore(double v[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int const DIM = 5;
    double v[DIM];
    caricaVettore(v, DIM);
    leggiVettore(v, DIM);

    cout << "Media variazione: " << mediaVariazione(v, DIM) << endl;

    return 0;
}