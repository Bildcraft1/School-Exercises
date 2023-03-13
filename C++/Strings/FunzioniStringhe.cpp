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

bool isInt(string s, int SIZE) {
    bool flag = true;

    for (int i = 0; i < SIZE && flag; i++) {
        if (!(s[i] >= '0' && s[i] <= '9') && s[i] != '-' && s[i] != '+') {
            flag = false;
        }
    }

    return flag;
}

bool isDouble(string s, int SIZE) {
    bool flag = true;

    for (int i = 0; i < SIZE && flag; i++) {
        if (!(s[i] >= '0' && s[i] <= '9') && s[i] != '-' && s[i] != '+' && s[i] != '.') {
            flag = false;
        }
    }

    return flag;
}

int convertToInt(string s, int size) {
    bool negativo = false;
    if (s[0] == '-') {
        negativo = true;
    }

    int numero = 0;
    int potenza = 1;

    for (int i = size-1; i >= 0; i--) {
        if (s[i] != '-' && s[i] != '+') {
            numero += (s[i] - '0') * potenza;
            potenza *= 10;
        }
    }

    if (negativo) {
        numero *= -1;
    }

    return numero;
}

double convertToDouble(string s, int SIZE) {
    double numero = 0;
    
    // TBD
    numero = stod(s);

    return numero;
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
    unsigned int n = 0;
    cout << "Inserisci una stringa: ";
    getline(cin, s1);

    cout << contaVocali(s1);
    s2 = inserisciStringa("Pippo Paperino", "Pluto ", 6);
    cout << s2;

    cout << endl;

    cout << estraiStringa("Pippo Pluto Paperino", 6, 5);

    isInt(s1, s1.length());

    if (isInt(s1, s1.length())) {
        cout << convertToInt(s1, s1.length()) << endl;
    } else {
        cout << "La stringa non contiene un numero intero" << endl;
    }

    if (isDouble(s1, s1.length())) {
        cout << "La stringa è un double" << endl;
        cout << convertToDouble(s1, s1.length()) << endl;
    } else {
        cout << "Non è un double" << endl;
    }

    return 0;
}