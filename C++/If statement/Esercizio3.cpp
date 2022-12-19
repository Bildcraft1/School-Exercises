#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int eta;

    cout << "ESERCIZIO 5" << endl;

    do {
        cout << "Inserisci la tua eta' = ";
        cin >> eta;
    } while(eta <= 0);

    cout << endl;

    if (eta >= 18) {
        cout << "Puoi avere la patente sia in italia che negli altri stati";
    } else if(eta >= 16) {
        cout << "Non puoi avere la patente ma in altri stati si";
    };

    cout << endl;
	#ifdef WIN32
    system("pause");
	#else
	#endif
    return 0;
}
