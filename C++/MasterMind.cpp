#include <iostream>
#include <string>
#include <cstdlib>
#include <random>

using namespace std;

random_device rd;
mt19937 rng(rd());

void codiceCasuale(string code[], int SIZE) {
    uniform_int_distribution<int> xDist(0, 8);

    for (int i = 0; i < SIZE; i++) {
        int random = xDist(rng);
        switch (random) {
            case 0:
                code[i] = "R";
                break;
            case 1:
                code[i] = "G";
                break;
            case 2:
                code[i] = "B";
                break;
            case 3:
                code[i] = "Y";
                break;
            case 4:
                code[i] = "O";
                break;
            case 5:
                code[i] = "P";
                break;
            case 6:
                code[i] = "W";
                break;
            case 7:
                code[i] = "V";
                break;
            case 8:
                code[i] = "M";
                break;  
        }
    }
}

bool checkCode(string code[], string answer[], int SIZE) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (code[i] == answer[i]) {
            count++;
        }
    }

    if (count == SIZE) {
        return true;
    } else {
        return false;
    }
}

void inserisciCodice(string answer[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        cout << "Inserisci il " << i + 1 << "° colore: ";
        cin >> answer[i];
    }
}

int main() {
    const int SIZE = 4;
    string code[SIZE];
    string answer[SIZE];
    int maxTries = 10, tries = 0;
    bool win = false;

    codiceCasuale(code, SIZE);

    for (int i = 0; i < SIZE; i++) {
        cout << code[i] << " ";
    }   

    cout << endl;

    while (tries < maxTries && !win) {
        inserisciCodice(answer, SIZE);
        if (checkCode(code, answer, SIZE)) {
            cout << "Hai indovinato il codice!" << endl;
            break;
        } else {
            cout << "Hai sbagliato il codice!" << endl;
            tries++;
        }
    }

    return 0;
}