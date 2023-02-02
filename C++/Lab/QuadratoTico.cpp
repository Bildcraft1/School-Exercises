#include <iostream>
#include <cstdlib>
#include "./headers/numbertools.h"

using namespace std;

void createCube(int size) {
    for (int i = 0; i <= size; i++) {
        for (int s = 0; s <= size; s++) {
            cout << "*";
            if (s == size) {
                cout << "\n";
            }
        }
    }
}

int main() {
    int size;
    cout << "Inserisci grandezza cubo: ";
    cin >> size;

    while (!numberIsPositive(size)) {
        cout << "Attenzione, numero inserito minore di zero" << endl;
        cout << "Inserisci grandezza cubo: ";
        cin >> size;
    }

    createCube(size);
}