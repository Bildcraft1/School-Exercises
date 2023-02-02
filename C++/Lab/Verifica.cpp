#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int potenza(int base, int esponente) {
    return pow(base, esponente);
}

int cifraMaggiore(int n) {
    int max=0, temp=0;
    while (n > 0) {
        temp = n % 10;
        if (temp > max) {
            max = temp;
        }
        n /= 10;
    }
    return max;
}

// ricevuti due numeri naturali n e m restitutisce il più piccolo numero divisible per m e maggiore di n
int minDiv(int n, int m) {
    int min=0;
    for (int i=n+1; i<=n+m; i++) {
        if (i % m == 0) {
            min = i;
            break;
        }
    }
    return min;
}

// restituisci il numero di divisori di un numero naturale n
int contaDiv(int n) {
    int conta=0;
    for (int i=1; i<=n; i++) {
        if (n % i == 0) {
            conta++;
        }
    }
    return conta;
}

// ricevuti 2 numeri naturali n e m conti quante coppie del tipo (i,j) con 0<i<=n e 0<j<=m soddisfano la condizione x+y % 5 == 0
int contaCoppie(int n, int m) {
    int conta=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if ((i+j) % 5 == 0) {
                conta++;
            }
        }
    }
    return conta;
}

int main() {
    int cock = 0;
    cin >> cock;
    cout << contaCoppie(cock, 10);
}