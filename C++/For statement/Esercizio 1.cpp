#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int grandezza, input, max = 0, min = 10, media = 0;

    cout << "Esercizio 1" << endl;
    do {
        cout << "Inserire gradezza ciclo: ";
        cin >> grandezza;
    } while(grandezza <= 0);


    for (int n = 0; n < grandezza; n++)
    {
        cout << "Inserisci numero a posizione " << (n + 1) << " : ";
        cin >> input;

        if (input > max)
        {
            max = input;
        };

        if (input < min)
        {
            min = input;
        };

        media += input;
    }

    cout << "Media: " << (media / grandezza) << endl;
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;

    cout << endl;
    return 0;
}