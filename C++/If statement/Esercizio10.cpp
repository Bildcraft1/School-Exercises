#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    int anno;
    cout << "ESERCIZIO 10" << endl;
    
    do {
        cout << "Inserisci anno di nascita = ";
        cin >> anno;
    } while(anno <= 0);

    
    if (anno == 1969){
        cout << "Sei nato nello stesso anno della prima volta che l'uomo e' andato sulla luna" << endl;
    } else if (anno < 1969) {
        cout << "Sei nato prima del primo uomo sulla luna" << endl;
        cout << "Sei nato " << abs(anno - 1969) << " anni prima" << endl;
    } else {
        cout << "Sei nato dopo del primo uomo sulla luna" << endl;
        cout << "Sei nato " << anno - 1969 << " anni dopo" << endl;
    }
    
    cout << endl;
    
    #ifdef WIN32
    system("pause");
	#else
	#endif
    
    return 0;
}
