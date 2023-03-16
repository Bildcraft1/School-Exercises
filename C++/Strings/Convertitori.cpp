#include <iostream>
#include <string>

using namespace std;

int menu() {
    int scelta = 0;
    cout << "1. Converti stringa in intero" << endl;
    cout << "2. Converti stringa in double" << endl;
    cout << "0. Esci" << endl;
    cout << "Scelta: ";
    cin >> scelta;
    return scelta;
}

bool checkInt(const string &s) {
    int size = s.length();
    for (int i = 0; i < size; i++) {
        if ((s[i] < '0' || s[i] > '9') && s[i] != '-' && s[i] != '+') {
            return false;
        }
    }
    return true;
}

bool checkDouble(const string &s) {
    int size = s.length();
    int punto = 0;
    for (int i = 0; i < size; i++) {
        if (s[i] == '.') {
            punto++;
        }

        if ((s[i] == '+' || s[i] == '-') && i == 0) {
            i++;
        }

        if ((s[i] < '0' || s[i] > '9')  && (s[i] != '.' || punto > 1)) {
            return false;
        }
    }
    return true;
}

int convertToInt(const string &s) {
    int segno = 1;
    int size = s.length();
    if (s[0] == '-') {
        segno = -1;
    }

    int numero = 0;
    int potenza = 1;

    for (int i = size-1; i >= 0; i--) {
        if (s[i] != '-' && s[i] != '+') {
            numero += (s[i] - '0') * potenza;
            potenza *= 10;
        }
    }

    return numero * segno;
}

double convertToDouble(const std::string& str)
{
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
        abs = 10 * abs + (str[i] - '0');
        ++i;
    }
    double value = 0.1;
    while (i < str.length())
    {
        abs += value * (str[i] - '0');
        value /= 10;
        ++i;
    }
    return abs * sign;
}

int main() {
    int a = 0;
    double b = 0;
    string c;

    do {
        switch (menu()) {
            case 1:
                cout << "Inserisci un numero intero: ";
                cin >> c;
                if (!checkInt(c)) {
                    cout << "Non e' un numero intero" << endl;
                    break;
                }
                a = convertToInt(c);
                cout << "Il numero inserito e': " << a << endl;
                break;
            case 2:
                cout << "Inserisci un numero double: ";
                cin >> c;
                if (!checkDouble(c)) {
                    cout << "Non e' un numero double" << endl;
                    break;
                }
                b = convertToDouble(c);
                cout << "Il numero inserito e': " << b << endl;
                break;
            case 0:
                cout << "Arrivederci!" << endl;
                break;
            default:
                cout << "Scelta non valida" << endl;
                break;
        }
    } while (menu() != 0);



    return 0;
}