#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <fstream>

using namespace std;

float calcolaResto(float prezzo, float banconota)
{
    if (banconota >= 500)
    {
        prezzo = prezzo * 0.94;
    }
    else if (prezzo >= 100)
    {
        prezzo = prezzo * 0.96;
    }
    else if (prezzo >= 50)
    {
        prezzo = prezzo * 0.97;
    }

    return banconota - prezzo;
}

void stampaRestoTaglio(int tipo, int counter) {
	        cout << tipo << ": " << counter << endl;
}

void tagliResto(float resto) {
    // Cant use arrays 
    int cinquecento = 0, duecento = 0, cento = 0, cinquanta = 0, venti = 0, dieci = 0, cinque = 0, due = 0, uno = 0;

    while((int)resto > 0) {
        if (resto >= 500) {
            resto -= 500;
            cinquecento++;
        } else if (resto >= 200) {
            resto -= 200;
            duecento++;
        } else if (resto >= 100) {
            resto -= 100;
            cento++;
        } else if (resto >= 50) {
            resto -= 50;
            cinquanta++;
        } else if (resto >= 20) {
            resto -= 20;
            venti++;
        } else if (resto >= 10) {
            resto -= 10;
            dieci++;
        } else if (resto >= 5) {
            resto -= 5;
            cinque++;
        } else if (resto >= 2) {
            resto -= 2;
            due++;
        } else if (resto >= 1) {
            resto -= 1;
            uno++;
        }
    }

    stampaRestoTaglio(500, cinquecento);
    stampaRestoTaglio(200, duecento);
    stampaRestoTaglio(100, cento);
    stampaRestoTaglio(50, cinquanta);
    stampaRestoTaglio(20, venti);
    stampaRestoTaglio(10, dieci);
    stampaRestoTaglio(5, cinque);
    stampaRestoTaglio(2, due);
    stampaRestoTaglio(1, uno);
}


int main()
{
    float prezzo = 0, banconota = 0, resto = 0, cliente = 0;
    srand(time(NULL));

    cout << "Cassa" << endl;

    while (true)
    {
        cout << "Cliente " << cliente << endl;

        prezzo = rand() % 1000 + 1;
        cout << "Prezzo: " << prezzo << endl;

        while (banconota < prezzo)
        {
            banconota = rand() % (int)prezzo + 10;
        };
        cout << "Banconota: " << banconota << endl;

        resto = calcolaResto(prezzo, banconota);

        cout << "Resto: " << resto << endl;
        cout << endl;
        
        cout << "Tagli Resto: " << endl;
        tagliResto(resto);

        cliente++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

#ifdef WIN32
    system("pause");
#else
#endif
}
