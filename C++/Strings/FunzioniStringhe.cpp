#include <iostream>
#include <string>

using namespace std;

void toLowercase(string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    }
}

int lunghezzaStringa(string s) {
    int lunghezza = 0;

    while (s[lunghezza++] != '\0');

    return lunghezza;
}

int contaVocali(string s) {
    int vocali = 0;

    toLowercase(s);

    for (int i = 0; i < lunghezzaStringa(s); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            vocali++;
        }
    }
    return vocali;
}

string inserisciStringa(string source, string s2, int pos) {
    string sf = "";

    // Carico nella stringa sf la stringa iniziale fino alla posizione inserita
    for (int i = 0; i < pos; i++) {
        sf += source[i];
    }

    // Aggiungo la stringa passata
    sf += s2;

    // Aggiungo il resto della stringa
    for (int i = pos; i < lunghezzaStringa(source); i++) {
        sf += source[i];
    }

    return sf;
}

string estraiStringa(string source, int pos, int lunghezza) {
    string sf = "";

    for (int i = pos; i != (lunghezza+pos); i++) {
        sf += source[i];
    }

    return sf;
}

int main() {
    string s1, s2;
    cout << "Inserisci una stringa: ";
    getline(cin, s1);

    cout << contaVocali(s1);
    s2 = inserisciStringa("Pippo Paperino", "Pluto ", 6);
    cout << s2;

    cout << endl;

    cout << estraiStringa("Pippo Pluto Paperino", 6, 5);

    return 0;
}