#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    float prezzo = 0, banconota = 0, resto = 0, cliente = 0;
    srand(time(NULL));

    cout << "Cassa" << endl;

    for (int i = 0; i < 10; i++)
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
    }

#ifdef WIN32
    system("pause");
#else
#endif
}
