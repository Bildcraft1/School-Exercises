#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int grandezza, input, max = 0, min = 0, media = 0;

    cout << "Esercizio 8" << endl;

    for (int n = 0; n < 5; n++)
    {
        cout << "Inserisci numero a posizione " << (n + 1) << ": ";
        cin >> input;

        if (input < min || min == 0)
        {
            min = input;
        };
    }

    cout << "Min: " << min << endl;

    cout << endl;
    
    #ifdef WIN32
    system("pause");
	#else
	#endif
    return 0;
}