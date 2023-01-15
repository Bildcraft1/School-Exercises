#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
<<<<<<< HEAD
        int a, b, r = 0;

        cout << "Inserisci A: ";
        cin >> a;

        while(a <= 0) {
                cout << "Attenzione: A deve essere maggiore di 0" << endl;
                cout << "Inserisci A: ";
                cin >> a;
        }

        cout << "Inserisci B: ";
        cin >> b;

        while (b <= 0) {
                cout << "Attenzione: B deve essere maggiore di 0" << endl;
                cout << "Inserisci B: ";
                cin >> b;
        }

        if (a == b) {
                cout << "MCD tra: " << a << " e " << b << " = " << b << endl;
        } else {
                cout << "MCD tra: " << a << " e " << b << " = ";
                r = a % b;
                while (r != 0) {
                        a = b;
                        b = r;
                        r = a % b;
                }
                cout << b << endl;
        }

        return 0;
=======
	int a, b, r = 0;

	cout << "Inserisci A: ";
	cin >> a;

	while(a <= 0) {
		cout << "Attenzione: A deve essere maggiore di 0" << endl;
		cout << "Inserisci A: ";
		cin >> a;
	}

	cout << "Inserisci B: ";
	cin >> b;

	while (b <= 0) {
		cout << "Attenzione: B deve essere maggiore di 0" << endl;
		cout << "Inserisci B: ";
		cin >> b;
	}

	if (a == b) {
		cout << "MCD tra: " << a << " e " << b << " = " << b << endl;
	} else {
		cout << "MCD tra: " << a << " e " << b << " = ";
		r = a % b;
		while (r != 0) {
			a = b;
			b = r;
			r = a % b;
		}
		cout << b << endl;
	}

	return 0;
>>>>>>> ca814b2 (Exercise 6)
}
