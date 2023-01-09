#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    float prestito, rata, interesse, durata, prezzomese, totale=0;

    cout << "Prestito Casa" << endl;

    cout << "Inserisci il prestito: ";
    cin >> prestito;
    prestito = prestito*0.90;

    cout << "Inserisci l'interesse: ";
    cin >> interesse;

    cout << "Inserisci la durata: ";
    cin >> durata;

    cout << "Inserisci prezzo al mese: ";
    cin >> prezzomese;

    for(int i=0; i<durata; i++)
    {
        rata = (prezzomese*12) + (prestito / 100 * interesse);
        cout << "Rata " << i+1 << ": " << rata << endl;
        prestito -= prezzomese*12;
        cout << "Prestito: " << prestito << endl;
        totale += rata;
    }

    cout << "Totale: " << totale << endl;

#ifdef WIN32
    system("pause");
#else
#endif
    return 0;
}
