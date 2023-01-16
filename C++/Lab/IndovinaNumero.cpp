#include <iostream>
#include <cstdlib>

#ifdef WIN32
#include <Windows.h>

if (IsDebuggerPresent())
    ExitProcess(-1);
#endif
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

        if (tentativi > 10)
        {
            cout << "Sei scarso, get good" << endl;
            break;
        }

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
    if (tentativi == 1) {
        cout << "un debugger lo so usare anche io nabbone" << endl;
    }

}