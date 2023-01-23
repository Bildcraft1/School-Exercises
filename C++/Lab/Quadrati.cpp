#include <iostream>
#include <cstdlib>
#include "./headers/numbertools.h"

using namespace std;

void createCube(int size) {
    for(int i = 0; i <= size; i++) {
        for (int s = 0; s <= size; s++) {
            cout << "*";
            if (s == size) {
                cout << endl;
            }
        }
    }
    cout << endl;
}

int main() {
    int size, i = 0, j = 0;
    cout << "Inserisci grandezza cubo: ";
    cin >> size;

    size -= 1;

    while (!numberIsPositive(size)) {
        cout << "Attenzione, numero inserito minore di zero" << endl;
        cout << "Inserisci grandezza cubo: ";
        cin >> size;
    }

    while (i <= size) {
        createCube(i);
        i++;
    }

    j = size - 1;

    while (j >= 0) {
        createCube(j);
        j--;
    }
}