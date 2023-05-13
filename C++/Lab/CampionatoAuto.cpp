#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "../utils/tabulate/tabulate.hpp"

using namespace std;

const int R = 4, C = 4;

struct pilota {
    char nome[20];
    char scuderia[20];
    int punti;
};

void inserisciPiloti(pilota piloti[], int &n, const int &SIZE) {
    for(int i = 0; i < SIZE; i++) {
        cout << "Inserisci nome pilota: ";
        cin.getline(piloti[i].nome, 20);
        cout << "Inserisci scuderia: ";
        cin.getline(piloti[i].scuderia, 20);
        piloti[i].punti = 0;
        n++;
    }
}

void scambia(pilota &p1, pilota &p2) {
    pilota temp = p1;
    p1 = p2;
    p2 = temp;
}

void ordinaPerNome(pilota piloti[], const int &n, const int &size) {
    for(int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (piloti[i].nome > piloti[j].nome) {
                scambia(piloti[i], piloti[j]);
            }
        }
    }
}

void inserisciCircuiti(string circuiti[], const int &SIZE) {
    for(int i = 0; i < SIZE; i++) {
        cout << "Inserisci nome circuito: ";
        getline(cin, circuiti[i]);
    }
}

void stampaPiloti(pilota piloti[], int &n, const int &SIZE) {
    for(int i = 0; i < SIZE; i++) {
        cout << "__________________________" << endl;
        cout << "Nome pilota: " << piloti[i].nome << endl;
        cout << "Scuderia: " << piloti[i].scuderia << endl;
        cout << "Punti: " << piloti[i].punti << endl;
    }
}

void stampaCircuiti(string circuiti[], const int &SIZE) {
    for(int i = 0; i < SIZE; i++) {
        cout << "__________________________" << endl;
        cout << "Nome circuito: " << circuiti[i] << endl;
    }
}

void cercaPerScuderia(pilota piloti[], int &n, const int &SIZE) {
    char scuderia[20];
    cout << "Inserisci scuderia da cercare: ";
    cin.getline(scuderia, 20);
    for(int i = 0; i < SIZE; i++) {
        if (strcmp(piloti[i].scuderia, scuderia) == 0) {
            cout << "__________________________" << endl;
            cout << "Nome pilota: " << piloti[i].nome << endl;
            cout << "Scuderia: " << piloti[i].scuderia << endl;
            cout << "Punti: " << piloti[i].punti << endl;
        }
    }
}

void inserisciArrivi(int arrivi[R][C], const int &SIZE, pilota piloti[], const int &PSIZE, string circuiti[], const int &CSIZE) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << "Inserisci arrivo pilota " << piloti[i].nome << " nel circuito " << circuiti[j] << ": ";
            cin >> arrivi[i][j];
        }
    }
}

void stampaTabellaPunti(int arrivi[R][C], const int &SIZE, pilota piloti[], const int &PSIZE, string circuiti[], const int &CSIZE) {
    tabulate::Table table;
    table.add_row({"Nome", "Scuderia", "Punti", "Circuito 1", "Circuito 2", "Circuito 3", "Circuito 4"});

    for (int i = 0; i < SIZE; i++) {
        table.add_row({piloti[i].nome, piloti[i].scuderia, to_string(piloti[i].punti), to_string(arrivi[i][0]), to_string(arrivi[i][1]), to_string(arrivi[i][2]), to_string(arrivi[i][3])});
    }

    
    cout << table << endl;
}

void calcolaPunteggi(int arrivi[R][C], const int &SIZE, pilota piloti[], const int &PSIZE, string circuiti[], const int &CSIZE) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            switch (arrivi[i][j]) {
                case 1:
                    piloti[i].punti += 6;
                    break;
                case 2:
                    piloti[i].punti += 5;
                    break;
                case 3:
                    piloti[i].punti += 4;
                    break;
                case 4:
                    piloti[i].punti += 3;
                    break;
                case 5:
                    piloti[i].punti += 2;
                    break;
                case 6:
                    piloti[i].punti += 1;
                    break;
                default:
                    break;
            }
        }
    }
}

int main() {
    const int PSIZE = 4, CSIZE = 4;
    pilota tpiloti[PSIZE];
    int t = 0;
    string circuiti[CSIZE];
    int arrivi[R][C];

    inserisciPiloti(tpiloti, t, PSIZE);
    inserisciCircuiti(circuiti, CSIZE);
    stampaPiloti(tpiloti, t, PSIZE);
    stampaCircuiti(circuiti, CSIZE);
    // cercaPerScuderia(tpiloti, t, PSIZE);
    inserisciArrivi(arrivi, PSIZE, tpiloti, PSIZE, circuiti, CSIZE);
    stampaTabellaPunti(arrivi, PSIZE, tpiloti, PSIZE, circuiti, CSIZE);
    calcolaPunteggi(arrivi, PSIZE, tpiloti, PSIZE, circuiti, CSIZE);
    stampaTabellaPunti(arrivi, PSIZE, tpiloti, PSIZE, circuiti, CSIZE);
}