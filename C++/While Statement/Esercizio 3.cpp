#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int input=1, somma=0, i=0;
    cout << "Esercizio 3" << endl;
    
	while (input != 0) {
        cout << "Inserisci numero: ";
        cin >> input;
        somma = somma + input;
        i = i + 1;
    };
    
    cout << "Somma dei numeri che hai inserito: " << somma << endl;
    cout << "Hai inserito: " << i << " numeri" << endl;
    
    return 0;
	
}