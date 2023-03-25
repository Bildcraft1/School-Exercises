#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

std::random_device rd;
std::mt19937 rng(rd());

void caricaArray(int array[], int size) {
    std::uniform_int_distribution<int> random_number(0, 30);
    for (int i = 0; i < size; i++) {
        int random = random_number(rng);
        array[i] = random;
    }
}

void stampaArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

int binarySearch(const int array[], int value, int size) {
    int inf = 0, sup = size-1, center = (inf+sup)/2;

    while (inf <= sup) {
        if (array[center] == value) {
            return center;
        } else if (array[center] < value) {
            inf = center + 1;
        } else {
            sup = center - 1;
        }
        center = (inf+sup)/2;
    }

    return -1;
}

int main() {
    int array[10], value;
    std::cout << "Binary Search" << std::endl;
    caricaArray(array, 10);
    stampaArray(array, 10);
    sort(array, array+10);
    cout << endl;
    stampaArray(array, 10);

    // Binary Search
    cout << endl;
    cout << "Inserisci il valore da cercare: ";

    do {
        cin >> value;
        if (value < 0 || value > 30) {
            cout << "Inserisci un valore compreso tra 0 e 30: ";
        }
    } while (value < 0 || value > 30);

    int result = binarySearch(array, value, 10);

    if (result == -1) {
        cout << "Il valore " << value << " non e' stato trovato" << endl;
    } else {
        cout << "Il valore " << value << " e' stato trovato in posizione:" << (result+1) << endl;
    }

    return 0;
}
