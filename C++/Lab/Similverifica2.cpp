/*
1) Costruire una funzione GEN che genera e visualizza una sequenza di numeri casuali
(compresi tra 15 e 50, estremi esclusi), la sequenza termina solo quando la somma dei
numeri già generati supera il numero 15.000.

2) Tre numeri naturali x, y, e z tali che x2 + y2 = z2 costituiscono un Terna Pitagorica;
costruire una funzione TERNA che dopo aver acquisito un numero intero Z, visualizza
l’elenco delle coppie X,Y tali che X, Y ,Z formi una terna pitagorica.

3) Costruire una funzione TROVAK che dato un vettore di caratteri VET e un carattere K determina se K è presente in VET oppure no.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
1) Costruire una funzione GEN che genera e visualizza una sequenza di numeri casuali
(compresi tra 15 e 50, estremi esclusi), la sequenza termina solo quando la somma dei
numeri già generati supera il numero 15.000.
*/

void gen() {
    int n=0, somma=0, i=0;

    // Genero un numero casuale compreso tra 15 e 50 (estremi inclusi)
    do {
        n = rand() % 35 + 15;
        somma += n;
        cout << n << " ";
        i++;
    } while (somma < 15000);

    cout << endl << "Somma: " << somma << endl;
}

/*
2) Tre numeri naturali x, y, e z tali che x2 + y2 = z2 costituiscono un Terna Pitagorica;
costruire una funzione TERNA che dopo aver acquisito un numero intero Z, visualizza
l’elenco delle coppie X,Y tali che X, Y ,Z formi una terna pitagorica.
*/

void terna(int z) {
    int x, y;

    for (x = 1; x < z; x++) {
        for (y = 1; y < z; y++) {
            if (x*x + y*y == z*z) {
                cout << "X: " << x << " Y: " << y << " Z: " << z << endl;
            }
        }
    }
}

/*
3) Costruire una funzione TROVAK che dato un vettore di caratteri VET e un carattere K determina se K è presente in VET oppure no.
*/
bool trovak(char v[], int dim, char k) {
    for (int i = 0; i < dim; i++) {
        if (v[i] == k) {
            return true;
        }
    }
    return false;
}

bool numeroMaggiore (int number)
{
    if (number > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void caricaVettore(char v[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << "Inserisci valore in posizione " << i+1 << ":" << endl;
        cin >> v[i];
    }
}

int main() {
    const int DIM = 10;
    char VET[DIM], search;
    int input;
    srand(time(NULL));

    // Generazione numeri casuali
    cout << "Generazione numeri casuali" << endl;
    gen();

    // Terna pitagorica
    cout << "Terna pitagorica" << endl;

    cout << "Inserisci numero per terna: ";
    cin >> input;

    while(!numeroMaggiore(input)) {
        cout << "Inserisci numero maggiore di 0: ";
        cin >> input;
    }

    terna(input);

    // Trova carattere
    cout << "Trova carattere" << endl;

    caricaVettore(VET, DIM);

    cout << "Inserisci carattere da cercare: ";
    cin >> search;

    if(trovak(VET, DIM, search)) {
        cout << "Il carattere " << search << " è presente nel vettore" << endl;
    } else {
        cout << "Il carattere " << search << "non è presente nel vettore" << endl;
    }

    return 0;
}