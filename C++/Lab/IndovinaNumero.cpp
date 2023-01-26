#include <iostream>
#include <cstdlib>

using namespace std;
int main()
{
    int numero = 0, tentativo = 0, tentativi = 0;
    bool perso=false
    srand(time(NULL));

    numero = rand() % 100 + 1;

    while (tentativo != numero)
    {
        cout << "Inserisci un numero: ";
        cin >> tentativo;
        tentativi++;

        if (tentativi > 10 && perso == false)
        {
            cout << "Sei scarso, get good" << endl;
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
        else
        {
            cout << "Hai indovinato in " << tentativi << " tentativi" << endl;
        }
    }
    if (tentativi == 1) {
        cout << "un debugger lo so usare anche io nabbone" << endl;
    }

}
