#include <iostream>
#include <cstdlib>

using namespace std;

void scambia(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 0, b = 0;
    cout << "Inserisci il primo numero: ";
    cin >> a;
    cout << "Inserisci il secondo numero: ";
    cin >> b;

    cout << "Prima dello swap: " << a << " " << b << endl;
    scambia(a, b);
    cout << "Dopo lo swap: " << a << " " << b << endl;

    return 0;
}