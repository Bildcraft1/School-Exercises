#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    float temp, max = -273.15;
    cout << "ESERCIZIO 5" << endl;
    do {
        cout << "Inserisci temperatura in Celsius = ";
        cin >> temp;
    } while(temp < max);

    cout << endl;
    cout << "Temperatura in Kelvin " << temp + 273.15 << endl;
    cout << "Temperatura in Farenight " << (9/5) * (temp + 32) << endl;

    cout << endl;
    system("pause");
    return 0;
}
