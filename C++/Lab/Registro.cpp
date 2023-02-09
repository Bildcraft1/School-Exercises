#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void caricaArray(string v[], int voti[], int num) {
    for (int i = 0; i < num ; i++) {
        cout << "Inserisci studente n. " << i+1 << endl;
        cin.ignore();
        getline(cin, v[i]);
        cout << "Inserisci voto: ";
        cin >> voti[i];
    }
}

void leggiArray(string v[], int voti[], int num) {
    cout << "Nome" << "     " << "Voto" << endl;
    for (int i = 0; i < num; i++) {
        cout << v[i] << "     " << voti[i] << endl;
    }
}

int main() {
    const int DIM = 10;
    std::string v[DIM];
    int voti[DIM];

    cout << "Registro Voti" << endl;
    caricaArray(v, voti, DIM);
    leggiArray(v, voti, DIM);
}