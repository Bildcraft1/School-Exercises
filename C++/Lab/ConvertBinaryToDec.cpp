#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int binario, decimale = 0, base = 1, rem;
    cout << "Inserire numero binario: ";
    cin >> binario;
    while (binario > 0)
    {
        rem = binario % 10;
        decimale = decimale + rem * base;
        binario = binario / 10;
        base = base * 2;
    }
    cout << "Il numero decimale è: " << decimale << endl;
    return 0;
}