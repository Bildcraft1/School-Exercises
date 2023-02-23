#include <iostream>
#include <cstdlib>

using namespace std;

void caricaStudenti(string V[], int DIM) {
    for (int i = 0; i < DIM; i++) {
        cout << "Inserisci nome studente: ";
        getline(cin, V[i]);
    }
}

void caricaVoti(float voti[], string nomi[],  int DIM) {
    int x;
    for (int i = 0; i < DIM; i++) {
        cout << "Inserisci voto dello studente " << nomi[i] << ":" << "";
        x = rand() % 10 + 1;
        voti[i] = x;
    }
}

void sortStudentsNames(string V[], int DIM) {
    int i, j;
    string temp;
    for (i = 0; i < DIM - 1; i++) {
        for (j = i + 1; j < DIM; j++) {
            if (V[i] > V[j]) {
                temp = V[i];
                V[i] = V[j];
                V[j] = temp;
            }
        }
    }
}

// Sort the students grades and names in descending order and then print them in ascending order (from the best to the worst).
void exchangeSort(string V[], float voti[], int DIM) {
    int i, j;
    float temp;
    string tempString;
    for (i = 0; i < DIM - 1; i++) {
        for (j = i + 1; j < DIM; j++) {
            if (voti[i] < voti[j]) {
                temp = voti[i];
                voti[i] = voti[j];
                voti[j] = temp;

                tempString = V[i];
                V[i] = V[j];
                V[j] = tempString;
            }
        }
    }
}


// Print the students grades and names.
void leggiVettore(string V[], float voti[], int DIM) {
    for (int i = 0; i < DIM; i++) {
        cout << "Nome in posizione: " << i+1 << " " << V[i] << endl;
        cout << "Voto dello studente: " << voti[i] << endl;
        cout << endl;
    }
}

void leggiStudenti(string V[], int DIM) {
    for (int i = 0; i < DIM; i++) {
        cout << V[i] << endl;
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
    srand(time(nullptr));
    const int DIM = 5;
    string studenti[DIM], temp[DIM];
    float voti[DIM];

    cout << "Registro Elettronico" << endl;
    caricaStudenti(studenti, DIM);
    caricaVoti(voti, studenti, DIM);

    cout << endl << "Vettore non ordinato" << endl;
    leggiVettore(studenti, voti, DIM);
    leggiStudenti(studenti, DIM);
    cout << endl;
    
    cout << endl << "Vettore ordinato" << endl;

    // Clone the array to sort the names.
    for (int i = 0; i < DIM; i++) {
        temp[i] = studenti[i];
    }

    sortStudentsNames(temp, DIM);
    leggiStudenti(temp, DIM);
    
    exchangeSort(studenti, voti, DIM);
    leggiVettore(studenti, voti, DIM);


    cout << endl << "Media dei voti: " << mediaVoti(voti, DIM);
    cout << endl << "Miglior studente: " << migliorStudente(studenti, voti, DIM);
    cout <<  endl << "Peggior studente: " << peggiorStudente(studenti, voti, DIM);
    return 0;
}
