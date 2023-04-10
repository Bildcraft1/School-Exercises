#include <iostream>
#include <string>

using namespace std;

string cryptMessage(const string& s) {
    string crypted;

    for (int i = 0; s.size() > i; i++) {
        char carattere = s[i];
        if ((carattere >= 'a' && carattere <= 'z') || (carattere >= 'A' && carattere <= 'W')) {
            crypted += carattere+3;
        } else {
            crypted += carattere-23;
        }
    }

    return crypted;
}

string decryptMessage(const string &s) {
    string decrypted;

    for (int i = 0; s.size() > i; i++) {
        char carattere = s[i];
        if ((carattere >= 'd' && carattere <= 'z') || (carattere >= 'D' && carattere <= 'W')) {
            decrypted += carattere-3;
        } else {
            decrypted += carattere+23;
        }
    }

    return decrypted;
}

int main() {
    string s;
    cout << "Inserisci la stringa da criptare: ";
    getline(cin, s);
    string cryptedMessage = cryptMessage(s);
    cout << endl << cryptedMessage;
    cout << endl << decryptMessage(cryptedMessage);
    return 0;
}
