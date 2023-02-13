/*
Andrea Moro Detto Rocco - 3^B
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
1) Costruire una funzione MediaCasuali che dato un intero M genera M numeri casuali (compresi nell’intervallo 1-10 estremi inclusi) e restituisce la somma dei pari
*/
int mediaCasuali(int m)
{
    int somma = 0;
    for (int i = 0; i < m; i++)
    {
        int n = rand() % 10 + 1;
        somma += n;
    }
    return somma;
}

/*
2) Costruire una funzione ContaDiv che dati 2 numeri interi A e B dice se esistono o meno divisori comuni di A e B
*/

int ContaDiv(int a, int b)
{
    int temp = 0;
    for (int i = 2; i <= a && i <= b; i++)
    {
        if ((a % i) == 0 && (b % i) == 0)
        {
            temp++;
        }
    }
    return temp;
}

/*
3) Dato il vettore dei valori di temperatura rilevata alle ore 12:00 a Cortina nella prima settimana di
Febbraio, la funzione SopraMedia determina quanti sono stati i giorni con temperatura superiore alla
temperatura media della settimana stessa.
*/
double mediaTemperature(double v[], int dim)
{
    double media = 0;
    for (int i = 0; i < dim; i++)
    {
        media += v[i];
    }
    return media / dim;
}

// Funzione che stampa i risultati della funzione sopraMedia
void stampaRisultati(double temp[], bool check[], double media, int DIM)
{
    cout << "Media delle temperature: " << media << endl;
    cout << "I giorni con temperatura maggiore alla media sono stati il:";
    for (int i = 0; i < DIM; i++)
    {
        if (check[i])
        {
            cout << " " << i + 1 << " (Temp: " << temp[i] << "),";
        }
    }
    cout << endl;
}

// Funzione che controlla se la temperatura è maggiore della media
void SopraMedia(double temp[], bool check[], int DIM)
{
    double media = mediaTemperature(temp, DIM);
    for (int i = 0; i < DIM; i++)
    {
        if (temp[i] > media)
        {
            check[i] = true;
        }
        else
        {
            check[i] = false;
        }
    }
    stampaRisultati(temp, check, media, DIM);
}

// Funzione che carica il vettore con le temperature
void caricaVettore(double v[], int DIM)
{
    for (int i = 0; i < DIM; i++)
    {
        cout << "Inserisci valore della temperatura: ";
        cin >> v[i];
    }
}

// Funzione che controlla se il numero è maggiore di 0
bool numeroMaggiore(int n)
{
    if (n < 0)
    {
        return false;
    }
    return true;
}

int main()
{
    // Inizializzazione del generatore di numeri casuali e variabili
    srand(time(NULL));
    const int DIM = 7;
    int ncasuale = 0, a = 0, b = 0;
    double temperatura[DIM];
    bool superioreTemp[DIM];

    // Chiamata delle funzioni
    cout << "Somma di numeri casuali" << endl;
    cout << "Inserisci numero di numeri da generare: ";
    cin >> ncasuale;
    while (!numeroMaggiore(ncasuale))
    {
        cout << "Hai inserito un numero minore di 0, reinserisci: ";
        cin >> ncasuale;
    }
    cout << "La somma di " << ncasuale << " numeri casuali e': " << mediaCasuali(ncasuale) << endl;

    caricaVettore(temperatura, DIM);
    SopraMedia(temperatura, superioreTemp, DIM);

    cout << "Inserisci A: ";
    cin >> a;
    while (!numeroMaggiore(a))
    {
        cout << "Hai inserito un numero minore di 0, reinserisci a: ";
        cin >> a;
    }

    cout << "Inserisci B: ";
    cin >> b;
    while (!numeroMaggiore(b))
    {
        cout << "Hai inserito un numero minore di 0, reinserisci a: ";
        cin >> b;
    }

    int numerodiv = ContaDiv(a, b);

    if (numerodiv > 0)
    {
        cout << a << " e " << b << " hanno almeno " << numerodiv << " divisori comuni" << endl;
    }
    else
    {
        cout << a << " e " << b << " non hanno divisori comuni";
    }

    return 0;
}
