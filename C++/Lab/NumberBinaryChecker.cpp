#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int input;
    cout << "Inserire numero binario: ";
    cin >> input;

    if ( input % 10 == 0 || input % 10 == 1 ) {
        cout << "Il numero è binario" << endl;
    } else {
        cout << "Il numero non è binario" << endl;    
    }

    return 0;
}