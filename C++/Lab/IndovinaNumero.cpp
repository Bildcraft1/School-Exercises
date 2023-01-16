#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int numero = 0, tentativo = 0, tentativi = 0;
    srand(time(NULL));

    numero = rand() % 100 + 1;

    while (tentativo != numero)
    {
        cout << "Inserisci un numero: ";
        cin >> tentativo;
        tentativi++;

        if (tentativo > numero)
        {
            cout << "Troppo alto" << endl;
        }
        else if (tentativo < numero)
        {
            cout << "Troppo basso" << endl;
        }
        else
        {
            cout << "Hai indovinato in " << tentativi << " tentativi" << endl;
        }
    }
}