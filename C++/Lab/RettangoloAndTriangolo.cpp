#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

bool numberIsPositive (int number)
{
    if (number > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkChar(char input) {
    if (input != 'R' && input != 'r' && input != 'T' && input != 't') {
        return false;
    } else {
        return true;
    }
}

void rectangle(int d1, int d2) {
    int area = d1 * d2;
    int perimeter = (d1 * 2) + (d2 * 2);

    cout << "Area: " << area << endl;
    cout << "Perimetro: " << perimeter << endl;    
}

void triangle(int d1, int d2) {
    int area = (d1 * d2) / 2;
    int perimeter = d1 + d2 + sqrt((d1 * d1) + (d2 * d2));

    cout << "Area: " << area << endl;
    cout << "Perimetro: " << perimeter << endl;    
}

int main() {
    char c;
    int d1, d2;

    cout << "Inserisci D1: ";
    cin >> d1;
    while (!numberIsPositive(d1)) {
        cout << "D1 inferiore di 1" << endl;
        cout << "Inserisci D1: ";
        cin >> d1;
    }

    cout << "Inserisci D2: ";
    cin >> d2;
    while (!numberIsPositive(d2)) {
        cout << "D1 inferiore di 1" << endl;
        cout << "Inserisci D1: ";
        cin >> d2;
    }

    cout << "Inserisci R per rettangolo o t per triangolo: ";
    cin >> c;

    while (checkChar(c) == false) {
        cout << "Errore, inserisci R o T" << endl;
        cout << "Inserisci R per rettangolo o t per triangolo: ";
        cin >> c;
    }

    if (c == 'R' || c == 'r') {
        rectangle(d1, d2);
    } else if (c == 'T' || c == 't') {
        triangle(d1, d2);
    }

    return 0;

}