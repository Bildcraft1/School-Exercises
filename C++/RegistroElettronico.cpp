#include <iostream>

using namespace std;

void caricaVettore(string V[], float voti[], int DIM) {
    for (int i = 0; i < DIM; i++) {
        cout << "Inserisci una stringa: ";
        getline(cin, V[i]);
        cout << "Inserisci voto dello studente";
        cin >> voti[i];
        while (voti[i] > 10) {
            cout << "Hai inserito un valore superiore al 10" << endl;
            cout << "Inserisci voto dello studente: ";
            cin >> voti[i];
        }
        cin.ignore();
    }
}

void leggiVettore(string V[], float voti[], int DIM) {
    for (int i = 0; i < DIM; i++) {
        cout << "Nome in posizione: " << i+1 << " " << V[i] << endl;
        cout << "Voto dello studente: " << voti[i] << endl;
        cout << endl;
    }
}

float mediaVoti(const float voti[], int DIM) {
    float mediaTotale = 0;
    for (int i = 0; i < DIM; i++) {
        mediaTotale += voti[i];
    }
    return mediaTotale/DIM;
}

string migliorStudente(string studenti[], float voti[], int DIM) {
    string migliorStudente;
    float maxVoto = 0;
    for (int i = 0; i < DIM; i++) {
        if (voti[i] > maxVoto) {
            migliorStudente = studenti[i];
            maxVoto = voti[i];
        }
    }
    return migliorStudente;
}

string peggiorStudente(string studenti[], float voti[], int DIM) {
    string peggiorStudente;
    float maxVoto = 10;
    for (int i = 0; i < DIM; i++) {
        if (voti[i] < maxVoto) {
            peggiorStudente = studenti[i];
            maxVoto = voti[i];
        }
    }
    return peggiorStudente;
}

int main() {
    const int DIM = 2;
    string studenti[DIM];
    float voti[DIM];

    cout << "Registro Elettronico" << endl;
    caricaVettore(studenti, voti, DIM);
    leggiVettore(studenti, voti, DIM);
    cout << endl << "Media dei voti: " << mediaVoti(voti, DIM);
    cout << endl << "Miglior studente: " << migliorStudente(studenti, voti, DIM);
    cout <<  endl << "Peggior studente: " << peggiorStudente(studenti, voti, DIM);
    return 0;
}
