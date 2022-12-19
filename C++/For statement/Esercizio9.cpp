#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int input;

    cout << "Esercizio 9" << endl;
    cout << "Inserisci numero da controllare: ";
    cin >> input;

    for (int i = 0; i < input; i++) {
        if (input % (++i) == 0) {
            cout << i << " ";
        }
    }

    cout << endl;
    
    #ifdef WIN32
    system("pause");
	#else
	#endif
    return 0;
}