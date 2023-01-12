#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int a, b, c;
    bool mcd=false;

    cout << "Inserisci due numeri: ";
    cin >> a >> b;

    while (a < 0 || b < 0) {
        cout << "I numeri devono essere positivi" << endl;
        cout << "Inserisci due numeri: ";
        cin >> a >> b;
    }

    c = a;

    if (a < b) {
        for (int i = a; i <= b; i++) {
            cout << i << " ";
        }
        
    }

    if (a > b) {
        while(a != b) {
            if(a < b) {
                int temp = a;
                a = b;
                b = temp;
            }
            a = a - b;
        }
        mcd = true;
    }

    if (a == 1 && mcd == true) {
        cout << "MCD: " << a <<endl;
        return 0;
    } else if (mcd == true) {
        cout << "MCD tra " << c << " e " << b << " e' " << a << endl;
    }

    return 0;

}