#include <iostream>
#include <string>

using namespace std;

void toLowercase(string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    }
}

int contaVocali(string s) {
    int vocali = 0;

    toLowercase(s);

    for (int i = 0; i < s.length(); i++) {
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
    for (int i = pos; i < source.length(); i++) {
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

double convertToDouble(const string& str)
{
    if (str.length() == 0)
        throw invalid_argument("Cannot convert empty string to double.");
    char sign = 1;
    double abs = 0;
    size_t i = 0;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '+' || str[i] == '-')
        ++i;
    while (i < str.length())
    {
        if (str[i] == '.')
        {
            ++i;
            break;
        }
        if (str[i] < '0' || str[i] > '9')
            invalid_argument("Invalid character found.");
        abs = 10 * abs + (str[i] - '0');
        ++i;
    }
    double value = 0.1;
    while (i < str.length())
    {
        if (str[i] < '0' || str[i] > '9')
            invalid_argument("Invalid character found.");
        abs += value * (str[i] - '0');
        value /= 10;
        ++i;
    }
    return abs * sign;
}

string estraiStringa(string source, int pos, int lunghezza) {
    string sf = "";

    for (int i = pos; i != (lunghezza+pos); i++) {
        sf += source[i];
    }

    return sf;
}

int contaRicorrenze(const string& source, const string& query) {
    int counter = 0;
    string s = query + "$" + source;
    int z[s.length()];
    int l = 0, r = 0;
    for (int i = 1; i < s.length(); i++) {
        if (i > r) {
            l = r = i;
            while (r < s.length() && s[r-l] == s[r]) {
                r++;
            }
            z[i] = r-l;
            r--;
        } else {
            int k = i-l;
            if (z[k] < r-i+1) {
                z[i] = z[k];
            } else {
                l = i;
                while (r < s.length() && s[r-l] == s[r]) {
                    r++;
                }
                z[i] = r-l;
                r--;
            }
        }
    }

    for (int i = 0; i < s.length(); i++) {
        if (z[i] == query.length()) {
            counter++;
        }
    }

    return counter;
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

    isInt(s1, s1.length());

    if (isInt(s1, s1.length())) {
        cout << convertToInt(s1, s1.length()) << endl;
    } else {
        cout << "La stringa non contiene un numero intero" << endl;
    }

    if (isDouble(s1, s1.length())) {
        cout << "La stringa è un double" << endl;
        cout << convertToDouble(s1) << endl;
    } else {
        cout << "Non è un double" << endl;
    }


    cout << contaRicorrenze("Pippo Pluto Paperino Pippo Marco Pippo", "Pippo");

    return 0;
}