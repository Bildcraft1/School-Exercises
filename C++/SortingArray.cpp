#include <iostream>
#include <cstdlib>

using namespace std;

// Questo metodo carica il vettore con i valori inseriti dall'utente.
void caricaVettore(int v[], int dim) {
    int temp, counter = 0, x = 0;
    cout << "Array prima del sorting" << endl;
    for (int i = 0; i < dim; i++) {
        x = rand() % 20 + 1;

        v[i] = x;
        counter++;
        cout << v[i] << " ";

        for (int k = 0; k < counter; k++)
        {
            for (int j = k + 1; j < counter; j++)
            {
                if (v[k] > v[j])
                {
                    temp = v[k];
                    v[k] = v[j];
                    v[j] = temp;
                }
            }
        }
    }
}

// Questo metodo stampa il contenuto del vettore.
void leggiVettore(int v[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << v[i] << " ";
    }
}

int main() {
    const int DIM = 10;
    int v[DIM];

    srand(time(nullptr));
    cout << "Sorting Algorithm" << endl;
    caricaVettore(v, DIM);
    cout << endl << "Dopo sorting" << endl;
    leggiVettore(v, DIM);

    return 0;
}
