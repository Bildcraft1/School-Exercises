#include <iostream>
#include <string>

using namespace std;

// Questo metodo carica il vettore con i valori inseriti dall'utente.
void caricaVettore(int v[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << "Inserisci valore in posizione " << i+1 << ":" << endl;
        cin >> v[i];
    }
}

// Questo metodo stampa il contenuto del vettore.
void leggiVettore(int v[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << v[i] << " ";
    }
}

// Questo metodo ritorna la posizione del valore all'interno del vettore.
int ricercaVettore(int v[], int dim, int valore) {
    for (int i = 0; i < dim; i++) {
        if (v[i] == valore) {
            return i;
        }
    }
    return -1;
}

// Questo metodo ritorna il valore massimo all'interno del vettore.
int maxVettore(int v[], int dim) {
    int vmax = 0;
    for (int i = 0; i < dim; i++) {
        if (v[i] > vmax) {
            vmax = v[i];
        }
    }
    return vmax;
}

// Questo metodo ritorna il valore minimo all'interno del vettore.
int minVettore(int v[], int dim) {
    int vmin = maxVettore(v, dim);
    for (int i = 0; i < dim; i++) {
        if (v[i] < vmin) {
            vmin = v[i];
        }
    }
    return vmin;
}

// Questo metodo ritorna la somma dei valori all'interno del vettore.
int sommaVettore(int v[], int dim) {
    int somma = 0;
    for (int i = 0; i < dim; i++) {
        somma += v[i];
    }
    return somma;
}

// Questo metodo ritorna la media dei valori all'interno del vettore.
double mediaVettore(int v[], int dim) {
    return sommaVettore(v, dim) / dim;
}

// Questo metodo inverte l'ordine dei valori all'interno del vettore.
void invertiVettore(int v[], int dim, int invertedV[]) {
    for (int i = 0; i < dim; i++) {
        invertedV[i] = v[dim - i - 1];
    }
}

int main() {
    const int DIM = 10;
    int v[DIM];
    int invertedV[DIM];

    caricaVettore(v, DIM);
    leggiVettore(v, DIM);

    int valore;
    cout << endl << "Inserisci valore da cercare: ";
    cin >> valore;

    int posizione = ricercaVettore(v, DIM, valore);

    if (posizione == -1) {
        cout << "Valore non trovato" << endl;
    } else {
        cout << "Valore trovato in posizione " << posizione+1 << endl;
    }

    // Questo codice stampa il valore massimo, minimo, la somma e la media di un vettore di interi.
    // Il vettore è di dimensione 10.
    // Il metodo maxVettore() ritorna il valore massimo all'interno del vettore.
    // Il metodo minVettore() ritorna il valore minimo all'interno del vettore.
    // Il metodo sommaVettore() ritorna la somma dei valori all'interno del vettore.
    // Il metodo mediaVettore() ritorna la media dei valori all'interno del vettore.

    cout << "Valore massimo dentro al vettore: " << maxVettore(v, DIM) << endl;
    cout << "Valore minimo dentro al vettore: " << minVettore(v, DIM) << endl;
    cout << "Somma totale dei valori all'interno del vettore: " << sommaVettore(v, DIM) << endl;
    cout << "Media dei valori all'interno del vettore: " << mediaVettore(v, DIM) << endl;
    
    cout << "Vettore originale: " << endl;
    leggiVettore(v, DIM);

    // Il programma legge 10 numeri interi e li inserisce in un vettore.
    // Successivamente inverte l'ordine dei numeri e li stampa.

    cout << "Vettore invertito: " << endl;
    invertiVettore(v, DIM, invertedV);
    leggiVettore(invertedV, DIM);

    return 0;
}