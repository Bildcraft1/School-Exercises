#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    float prezzo = 0, banconota = 0, resto = 0, cliente = 0;

    cout << "Cassa" << endl;

    while (true)
    {
        cout << "Cliente " << cliente << endl;

        do
        {
            cout << "Inserire prezzo: ";
            cin >> prezzo;
        } while (prezzo <= 0);

        while (!(banconota == 2 || banconota == 5 || banconota == 10 || banconota == 20 || banconota == 50 || banconota == 100 || banconota == 200 || banconota == 500))
        {
            cout << "Inserire banconota: ";
            cin >> banconota;
        };

        if (prezzo > banconota)
        {
            cout << "Soldi non sufficienti" << endl;
#ifdef WIN32
            system("pause");
#else
#endif
            return 0;
        }

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
        resto = banconota - prezzo;

        cout << "Resto: " << resto << endl;
        cout << endl;

        cliente++;
    }

#ifdef WIN32
    system("pause");
#else
#endif
}
