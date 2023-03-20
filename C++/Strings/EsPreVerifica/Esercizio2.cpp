#include <iostream>
#include <string>

using namespace std;

int length(const string &string) {
    int i = 0;

    while (string[i] != '\0') {
        i++;
    }

    return i;
}

int main() {
    string s1;

    cout << "Esercizio 2" << endl;
    cout << "Leggi una stringa e determina quanto è lunga." << endl;
    cout << "Inserisci una stringa: ";

    getline(cin, s1);

    cout << "Lunghezza stringa: " << length(s1) << endl;
}