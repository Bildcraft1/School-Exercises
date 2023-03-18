#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

std::random_device rd;
std::mt19937 rng(rd());

template<size_t size>
void caricaArray(int array[]) {
    std::uniform_int_distribution<int> random_number(0, 30);
    for (int i = 0; i < size; i++) {
        int random = random_number(rng);
        array[i] = random;
    }
}

template<size_t size>
void stampaArray(int array[]) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

template<size_t size>
int binarySearch(const int array[], int value) {
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
    caricaArray<10>(array);
    stampaArray<10>(array);
    sort(array, array+10);
    cout << endl;
    stampaArray<10>(array);

    // Binary Search
    cout << endl;
    cout << "Inserisci il valore da cercare: ";

    do {
        cin >> value;
        if (value < 0 || value > 30) {
            cout << "Inserisci un valore compreso tra 0 e 30: ";
        }
    } while (value < 0 || value > 30);


    if (binarySearch<10>(array, value) == -1) {
        cout << "Il valore " << value << " non e' stato trovato";
    } else {
        cout << "Il valore " << value << " e' stato trovato in posizione:" << binarySearch<10>(array, value);
    }

    return 0;
}
