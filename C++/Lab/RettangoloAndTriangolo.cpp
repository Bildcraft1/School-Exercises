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

// Rectangle Part
int rectangleArea(int d1, int d2) {
    int area = d1 * d2;
    return area;
}

int rectanglePerimeter(int d1, int d2) {
    int perimeter = (d1 * 2) + (d2 * 2);
    return perimeter;
}

// Triangle part
int triangleArea(int d1, int d2) {
    int area = (d1 * d2) / 2;
    return area;
}

int trianglePerimeter(int d1, int d2) {
    int perimeter = d1 + d2 + sqrt((d1 * d1) + (d2 * d2));
    return perimeter;
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
        cout << "Area: " << rectangleArea(d1, d2) << endl;
        cout << "Perimetro: " << rectanglePerimeter(d1, d2) << endl;
    } else if (c == 'T' || c == 't') {
        cout << "Area: " << triangleArea(d1, d2) << endl;
        cout << "Perimetro: " << trianglePerimeter(d1, d2) << endl;
    }

    return 0;
}