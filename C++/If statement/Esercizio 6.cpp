#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int a, b, c, cont;
	
	cout << "Esercizio 6" << endl;
	cout << "Inserire A = ";
	cin >> a;
	cout << "Inserire B = ";
	cin >> b;
	cout << "Inserire C = ";
	cin >> c;
	
	cont = a - b;
	if (b - c == cont) {
		cout << "La sequenza è in progressione";
	} else {
		cout << "La sequenza non è in progressione";
	}
	
    system("pause")
    return 0;
}