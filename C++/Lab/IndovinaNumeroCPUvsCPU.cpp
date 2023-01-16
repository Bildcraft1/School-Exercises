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
        tentativo = rand() % 100 + 1;
        cout << "CPU 1: " << tentativo << endl;
        tentativi++;

        if (tentativo > numero)
        {
            cout << "CPU 2: Troppo alto" << endl;
        }
        else if (tentativo < numero)
        {
            cout << "CPU 2: Troppo basso" << endl;
        }
        else
        {
            cout << "CPU 1 ha indovinato in " << tentativi << " tentativi" << endl;
        }
    }
}