#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int input, f1 = 0, f2 = 1;

    cout << "Esercizio 7" << endl;
    cout << "Inserisci volte da ripetere: ";
    cin >> input;
    
    for (int n = 0; n < input; n++)
    {
        cout << f1 << " ";
        f1 = f1 + f2;
        f2 = f1 - f2;
    }

    cout << endl;
    
    #ifdef WIN32
    system("pause");
	#else
	#endif
    return 0;
}