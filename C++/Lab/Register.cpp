#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    float prezzo, banconota, resto;

    do {
        cout << "Inserire prezzo: ";
        cin >> prezzo;
    } while(prezzo <= 0);

    do {
        cout << "Inserire banconota: ";
        cin >> banconota;
    } while(banconota <= 0);

    if (prezzo > banconota) {
        cout << "Soldi non sufficienti" << endl;
        return 0;
    }

    if (prezzo >= 50.0 ) {
        prezzo = prezzo / 100 * 97;
        cout << "Prezzo: " << prezzo << endl;
    } else if (prezzo >= 100) {
        prezzo = prezzo/ 100 * 96;
        cout << "Prezzo: " << prezzo << endl;
    } else if (banconota >= 500) {
        prezzo = prezzo / 100 * 94;
        cout << "Prezzo: " << prezzo << endl;
    }

    resto = banconota - prezzo;

    cout << "Resto: " << resto << endl;

    #ifdef WIN32
    system("pause");
	#else
	#endif
}