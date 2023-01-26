#include <iostream>
#include <cstdlib>

using namespace std;
int main()
{
    int numero = 0, tentativo = 0, tentativi = 0;
    bool perso=false, debug=false;
    srand(time(NULL));

    numero = rand() % 100 + 1;

    while (tentativo != numero && perso == false && debug == false)
    {
        cout << "Inserisci un numero: ";
        cin >> tentativo;
        tentativi++;

        if (tentativi > 10 && perso == false)
        {
            cout << "Troppi tentativi, il numero era: " << numero << endl;
            perso = true;
        }

        if (tentativo > numero && perso == false)
        {
            cout << "Troppo alto" << endl;
        }
        else if (tentativo < numero && perso == false)
        {
            cout << "Troppo basso" << endl;
        }
        else if (tentativo == numero && perso == false)
        {
            cout << "Hai indovinato in " << tentativi << " tentativi" << endl;
        }
    }

    if (tentativi == 1) {
        cout << "Non barare con un debugger (Oppure sei bravo di tuo)" << endl;
    }

}
