#include <iostream>
#include <string>

using namespace std;

void uppercase(string &string) {
    for(int i = 0; i < string.length(); i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] -= 32;
        }
    }
}

void upper_lower(string &string) {
    for(int i = 0; i < string.length(); i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] -= 32;
        } else if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] += 32;
        }
    }
}

int main() {
    string s1, s2;

    cout << "Esercizio 1" << endl;
    cout << "A.Leggi una stringa e trasformane le lettere minuscole in maiuscole." << endl;
    cout << "Inserisci una stringa: ";

    getline(cin, s1);

    cout << endl;
    uppercase(s1);
    cout << s1 << endl;

    cout << "B. Leggi una stringa e trasformane le lettere minuscole in maiuscole e viceversa." << endl;
    cout << "Inserisci una stringa: ";
    getline(cin, s2);

    cout << endl;
    upper_lower(s2);
    cout << s2 << endl;
}