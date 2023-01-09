#include <iostream>
#include <cstdlib>
#define cirno cin


using namespace std;

int main() {
    float prezzo, banconota, resto;

    do {
        cout << "Inserire prezzo: ";
        cin >> prezzo;
    } while(prezzo <= 0);

    do {
        cout << "Inserire banconota: ";
        cirno >> banconota;
    } while (!(banconota == 2 || banconota == 5 || banconota == 10 || banconota == 20 || banconota == 50 || banconota == 100 || banconota == 200 || banconota == 500));

    if (prezzo > banconota) {
        cout << "Soldi non sufficienti" << endl;
        system("pause");
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
