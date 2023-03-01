#include <iostream>
#include <cstdlib>
#include "utils/systemutils.h"
#include "utils/vectorutils.h"

using namespace std;

int menu()
{
    int scelta;
    do
    {
        clearScreen();
        cout << "1. Inserisci studente" << endl;
        cout << "2. Inserisci voto" << endl;
        cout << "3. Ordina studenti" << endl;
        cout << "4. Leggi vettore" << endl;
        cout << "5. Leggi studenti" << endl;
        cout << "6. Media voti" << endl;
        cout << "7. Miglior studente" << endl;
        cout << "8. Peggior studente" << endl;
        cout << "9. Cancella studente" << endl;
        cout << "10. Aggiungi studente" << endl;
        cout << "0. Esci" << endl;
        cout << "Scelta: ";
        cin >> scelta;
    } while (scelta < 0 || scelta > 10);

    return scelta;
}

void carica(string V[], int DIM)
{
    cin.ignore();
    for (int i = 0; i < DIM; i++)
    {
        cout << "Inserisci nome studente: ";
        getline(cin, V[i]);
    }
}

void carica(float voti[], string nomi[], int DIM)
{
    int x;
    for (int i = 0; i < DIM; i++)
    {
        x = rand() % 10 + 1;
        voti[i] = x;
    }
}

void sortStudentsNames(string V[], int DIM)
{
    int i, j;
    string temp;
    for (i = 0; i < DIM - 1; i++)
    {
        for (j = i + 1; j < DIM; j++)
        {
            if (V[i] > V[j])
            {
                temp = V[i];
                V[i] = V[j];
                V[j] = temp;
            }
        }
    }
}

// Sort the students grades and names in descending order and then print them in ascending order (from the best to the worst).
void exchangeSort(string V[], float voti[], int DIM)
{
    int i, j;
    float temp;
    string tempString;
    for (i = 0; i < DIM - 1; i++)
    {
        for (j = i + 1; j < DIM; j++)
        {
            if (voti[i] < voti[j])
            {
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

void cancellaStudente(string V[], int &DIM)
{
    string nome; //read the name
    bool trovato = false; //found variable
    cin.ignore();
    cout << "Inserisci nome studente da cancellare: ";
    getline(cin, nome);
    for (int i = 0; i < DIM && !trovato; i++)
    {
        if (V[i] == nome)
        {
            V[i] = ""; //if the name is found, the string is set to ""
            trovato = true;

            for (int j = i; j < DIM - 1; j++)
            {
                V[j] = V[j + 1];
            }
        }
    }

    if (!trovato)
    {
        cout << "Studente non trovato!" << endl;
    }
    else
    {
        cout << "Studente cancellato!" << endl;
        DIM--;
    }
}

void aggiungiStudente(string V[], float voti[], int &DIM)
{
    string nome;
    bool trovato = false;
    cin.ignore();
    cout << "Inserisci nome studente da aggiungere: ";
    getline(cin, nome);

    for (int i = 0; i < DIM && !trovato; i++)
    {
        if (V[i] == nome)
        {
            trovato = true;
        }
    }

    if (trovato)
    {
        cout << "Studente già presente!" << endl;
    }
    else
    {
        V[DIM] = nome;
        DIM++;
        cout << "Studente aggiunto!" << endl;
        cout << "Inserisci voto dello studente: ";
        cin >> voti[DIM - 1];

        while (voti[DIM - 1] < 0 || voti[DIM - 1] > 10)
        {
            cout << "Voto non valido! Inserisci voto dello studente: ";
            cin >> voti[DIM - 1];
        }
    }
}

// Print the students grades and names.
void leggi(string V[], float voti[], int DIM)
{
    for (int i = 0; i < DIM; i++)
    {
        cout << "Nome in posizione: " << i + 1 << " " << V[i] << endl;
        cout << "Voto dello studente: " << voti[i] << endl;
        cout << endl;
    }
}

float mediaVoti(const float voti[], int DIM)
{
    float mediaTotale = 0;
    for (int i = 0; i < DIM; i++)
    {
        mediaTotale += voti[i];
    }
    return mediaTotale / DIM;
}

string migliorStudente(string studenti[], float voti[], int DIM)
{
    string migliorStudente;
    float maxVoto = 0;
    for (int i = 0; i < DIM; i++)
    {
        if (voti[i] > maxVoto)
        {
            migliorStudente = studenti[i];
            maxVoto = voti[i];
        }
    }
    return migliorStudente;
}

string peggiorStudente(string studenti[], float voti[], int DIM)
{
    string peggiorStudente;
    float maxVoto = 10;
    for (int i = 0; i < DIM; i++)
    {
        if (voti[i] < maxVoto)
        {
            peggiorStudente = studenti[i];
            maxVoto = voti[i];
        }
    }
    return peggiorStudente;
}

int main()
{
    srand(time(nullptr));
    int size;

    cout << "Benvenuto nel registro elettronico!" << endl;
    cout << "Inserisci grandezza vettore: ";
    cin >> size;

    while (size < 0 || size > 30)
    {
        cout << "Inserisci grandezza vettore: ";
        cin >> size;
    }

    const int MAX = 30;
    int DIM = size;
    string studenti[MAX], temp[MAX];
    float voti[MAX];
    int scelta;

    do
    {
        scelta = menu();

        switch (scelta)
        {
        case 1:
            carica(studenti, DIM);
            break;
        case 2:
            carica(voti, studenti, DIM);
            break;
        case 3:
            exchangeSort(studenti, voti, DIM);
            break;
        case 4:
            leggi(studenti, voti, DIM);
            break;
        case 5:
            sortStudentsNames(studenti, DIM);
            leggi(studenti, DIM);
            break;
        case 6:
            cout << "La media dei voti e': " << mediaVoti(voti, DIM) << endl;
            break;
        case 7:
            cout << "Lo studente migliore e': " << migliorStudente(studenti, voti, DIM) << endl;
            break;
        case 8:
            cout << "Lo studente peggiore e': " << peggiorStudente(studenti, voti, DIM) << endl;
            break;
        case 9:
            cancellaStudente(studenti, DIM);
            break;
        case 10:
            aggiungiStudente(studenti, voti, DIM);
            break;
        }
        pause();
    } while (scelta != 0);

    cout << "Arrivederci!";

    return 0;
}
