/*
1. Costruire una funzione che dato un numero intero M>0, restituisce la somma dei numeri x compresi tra 1 e M per i quali il valore (x*x)/(x-5) è maggiore di 10.
2. Costruire una funzione che calcola la media di una sequenza di numeri casuali (compresi tra 10 e 30, estremi inclusi), la sequenza termina quando la media dei numeri generati supera il valore 20.
3. Costruire una funzione che dato un numero intero K, conta quanti sono gli i*j pari (con i<K e j<=K) 
*/

#include <iostream>
#include <cstdlib>

using namespace std;

// Costruire una funzione che dato un numero intero M>0, restituisce la somma dei numeri x compresi tra 1 e M per i quali il valore (x*x)/(x-5) è maggiore di 10.
int sommaPari(int m) {
    int somma=0, temp=0;
    for (int i=1; i<=m; i++) {
        
        // Controllo se i è diverso da 5 (per evitare divisione per 0)
        if (i != 5) {
            temp = (i*i)/(i-5);
        }

        // Controllo se il risultato è maggiore di 10
        if (temp >= 10) {
            somma += i;
        }
    }
    return somma;

}

// Costruire una funzione che calcola la media di una sequenza di numeri casuali (compresi tra 10 e 30, estremi inclusi), la sequenza termina quando la media dei numeri generati supera il valore 20. 
double mediaCasuale() {
    int n=0, somma=0, i=0;
    double media=0;
    
    // Genero un numero casuale compreso tra 10 e 30 (estremi inclusi)
    while (media < 20) {
        n = rand() % 21 + 10;
        somma += n;
        media = somma / (i+1);
        i++;
    }
    return media;
}

//  Costruire una funzione che dato un numero intero K, conta quanti sono gli i*j pari (con i<K e j<=K) 
int contaK(int k) {
    int conta=0;
    // Controlla tutti i valori di i e j minori di k
    for (int i=1; i<k; i++) {
        for (int j=1; j<=k; j++) {
            // Controlla se i*j è pari
            if ((i*j) % 2 == 0) {
                conta++;
            }
        }
    }
    return conta;
}

// Funzioni di verifica

// Funzione per verificare se il numero è maggiore di 0
bool checkNumber(int n) {
    if (n > 0) {
        return true;
    } else {
        return false;
    }
}

// Funzione per verificare se il numero è pari
bool checkPositive(int n) {
    if (n % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cout << "Pre verifica" << endl;
    srand(time(NULL));
    int n=0;
    
    // Funzione sommaPari
    cout << "Inserisci un numero positivo pari" << endl;
    cin >> n;

    while(!checkNumber(n) && !checkPositive(n)) {
        cout << "Inserisci un numero positivo pari" << endl;
        cin >> n;
    }
    cout << "Somma pari: " << sommaPari(n) << endl;

    // Funzione mediaCasuale
    cout << "Media casuale: " << mediaCasuale() << endl;

    // Funzione contaK
    cout << "Inserisci un numero positivo" << endl;
    cin >> n;

    while(!checkNumber(n)) {
        cout << "Inserisci un numero positivo" << endl;
        cin >> n;
    }

    cout << "Conta K = " << contaK(n) << endl;

    return 0;
}