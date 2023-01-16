#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <fstream>

using namespace std;

ofstream fout("output.txt");

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

        cout << "Prezzo: " << prezzo << endl;
        resto = banconota - (int)prezzo;

        cout << "Resto: " << resto << endl;
        cout << endl;

        cliente++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        fout << cliente << " " << prezzo << " " << banconota << " " << resto << endl;
    }

#ifdef WIN32
    system("pause");
#else
#endif
}
