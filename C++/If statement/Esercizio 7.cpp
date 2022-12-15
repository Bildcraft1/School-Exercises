#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int anno;
    bool stato;

    cout << "ESERCIZIO 7" << endl;
    do {
        cout << "Inserisci anno = ";
        cin >> anno;
    } while(anno <= 0);

    if (anno % 400 == 0) {
        cout << endl << "Anno bisestile";
    } else {
        cout << endl << "Anno non bisestile";
    }

    cout << endl;
    system("pause");
    return 0;
}
