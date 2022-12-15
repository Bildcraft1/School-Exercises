#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int input, div, i=0;

    cout << "Esercizio 4" << endl;
    
    cout << "Inserisci numero: ";
    cin >> input;
    div = input;
    
    while (input % 2 == 0 && input >= 0) {
        input = input - 2;
        i = i + 1;
    };

    cout << "Il numero " << div << " e' divisibile " << i << " volte" << endl;

    return 0;
	
}