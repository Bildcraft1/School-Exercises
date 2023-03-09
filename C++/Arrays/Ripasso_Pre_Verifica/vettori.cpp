#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void caricaArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Inserisci valore in posizione " << (i+1) << " : ";
        cin >> array[i];
    }
}

void leggiArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << " " << array[i];
    }
}

void exchangeSort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i] < array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int massimoArray(int array[], int size) {
    int max = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max == array[i];
        }
    }
    return max;
}

int minimoArray(int array[], int size) {
    int min = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] < min) {
            min == array[i];
        }
    }
    return min;
}

int mediaArray(int array[], int size) {
    int media = 0;
    for (int i = 0; i < size; i++) {
        media += array[i];
    }
    return media/size;
}

int main() {
    const int MAX_SIZE = 30;
    int dim = 0;
    int array[MAX_SIZE];

    do {
        cout << "Inserisci grandezza array: ";
        cin >> dim;
    } while (dim <= 0 || dim > 30);

    caricaArray(array, dim);

    cout << endl << "Array prima del riordinamento" << endl;

    leggiArray(array, dim);

    cout << endl << "Array Riodinato" << endl;

    exchangeSort(array, dim);
    leggiArray(array, dim);

    cout << endl << "Max: " << massimoArray(array, dim) << " Min: " << minimoArray(array, dim) << " Media: " << mediaArray(array, dim);

    return 0;
}