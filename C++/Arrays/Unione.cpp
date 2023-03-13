#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;

std::random_device rd;
std::mt19937 rng(rd());

void caricaArrayRandom(int array[], int size) {
    uniform_int_distribution<int> random_number(0, 30);
    // Carico l'array in modo random controllando che non ci siano valori uguali, se c'è un valore uguale genero un nuovo numero
    for (int i = 0; i < size; i++) {
        bool isDuplicate = false;
        array[i] = random_number(rng);
        for (int j = 0; j < i; j++) {
            if (array[i] == array[j] && !isDuplicate) {
                i--;
                isDuplicate = true;
            }
        }
    }

}

void leggiArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

void trovaUnione(int insieme1[], int insieme2[], int unione[], int sizeInsieme1, int sizeInsieme2, int &sizeUnione) {
    int i = 0, j = 0;
    while (i < sizeInsieme1 && j < sizeInsieme2) {
        // Prendo gli array da confrontare
        if (insieme1[i] < insieme2[j]) {
            // Aggiungo il più piccolo all'unione
            unione[sizeUnione] = insieme1[i];
            i++;
        } else if (insieme1[i] > insieme2[j]) {
            // Aggiungo il più piccolo dei 2 all'unione 
            unione[sizeUnione] = insieme2[j];
            j++;
        } else {
            // Aggiungo il numero all'unione
            unione[sizeUnione] = insieme1[i];
            i++;
            j++;
        }
        sizeUnione++;
    }

    // Aggiungo i numeri restanti dell'array più grande
    while (i < sizeInsieme1) {
        unione[sizeUnione] = insieme1[i];
        i++;
        sizeUnione++;
    }

    // Aggiungo i numeri restanti dell'array più grande
    while (j < sizeInsieme2) {
        unione[sizeUnione] = insieme2[j];
        j++;
        sizeUnione++;
    }
}

void sortArray(int array[], int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i] < array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    const int MAX_SIZE = 30;
    int insieme1[MAX_SIZE], insieme2[MAX_SIZE];
    int sizeInsiemi = 0;
    int intersezione[MAX_SIZE];
    int sizeIntersezione = 0;

    do {
        cout << "Inserisci la dimensione degli insiemi (MAX 30): ";
        cin >> sizeInsiemi;
    } while (sizeInsiemi > MAX_SIZE || sizeInsiemi < 0);

    caricaArrayRandom(insieme1, sizeInsiemi);
    caricaArrayRandom(insieme2, sizeInsiemi);

    sortArray(insieme1, sizeInsiemi);
    sortArray(insieme2, sizeInsiemi);

    cout << "Insieme 1: ";
    leggiArray(insieme1, sizeInsiemi);
    cout << endl;

    cout << "Insieme 2: ";
    leggiArray(insieme2, sizeInsiemi);
    cout << endl;

    trovaUnione(insieme1, insieme2, intersezione, sizeInsiemi, sizeInsiemi, sizeIntersezione);

    cout << "Unione: ";

    leggiArray(intersezione, sizeIntersezione);
    cout << endl;

    return 0;
}