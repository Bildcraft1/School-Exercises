#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    // Generate random numbers until the generated number is equal to the last one generated
    int last = 0;
    int current = 1;
    int count = 0, aftercount = 0;

    srand(time(NULL));
    
    while (current != last) {
        last = current;
	current = rand()%10 + 1;
	count++;
    	cout << current << " ";
	if (current == last+1) {
                aftercount++;
        }
    }

    cout << endl;
    cout << "Numero di numeri generati: " << count << endl;
    cout << "Numero di numeri generati dopo che il numero corrente e' stato uguale al precedente: " << aftercount << endl;


    
    return 0;
}
