#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    float prestito, rata, interesse, durata, prezzomese, totale=0, presitobanca;
    int anni=0;

    cout << "Prestito Casa" << endl;

    cout << "Inserisci il prestito: ";
    cin >> prestito;

    while (prestito <= 0) {
        cout << endl;
        cout << "Attenzione: il prestito deve essere maggiore di 0" << endl;
        cout << "Inserisci il prestito: ";
        cin >> prestito;
    }

    prestito = prestito*0.90;
    cout << "Prestito considerato dalla banca: " << prestito << endl;
    presitobanca = prestito;

    cout << "Inserisci l'interesse: ";
    cin >> interesse;

    while (interesse <= 0) {
        cout << endl;
        cout << "Attenzione: l'interesse deve essere maggiore di 0" << endl;
        cout << "Inserisci l'interesse: ";
        cin >> interesse;
    }

    cout << "Inserisci prezzo al mese: ";
    cin >> prezzomese;

    while (prezzomese <= 0) {
        cout << endl;
        cout << "Attenzione: il prezzo mensile deve essere maggiore di 0" << endl;
        cout << "Inserisci prezzo al mese: ";
        cin >> prezzomese;
    }

    while(prestito > 0)
    {
        rata = (prezzomese*12) + (prestito / 100 * interesse);
        cout << "Rata " << anni+1 << ": " << rata << endl;
        prestito = prestito - (prezzomese*12);
        if (prestito > 0) {
            cout << "Prestito: " << prestito << endl;
        }
        totale += rata;
        anni++;
    }

    cout << "Totale speso: " << totale << endl;
    cout << "Totale speso in più: " << totale - presitobanca << endl;
    cout << "Anni: " << anni << endl;

#ifdef WIN32
    system("pause");
#else
#endif
    return 0;
}
