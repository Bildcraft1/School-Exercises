#include <iostream>
#include <cstring>

using namespace std;

bool compareChar(char c1[], char c2[]) {
    int i = 0;
    while (c1[i] != '\0' && c2[i] != '\0') {
        if (c1[i] != c2[i]) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    char str1[50], str2[50];
    cout << "Enter first string: ";
    cin.getline(str1, 50);
    cout << "Enter second string: ";
    cin.getline(str2, 50);

    cout << "Comparing strings: " << strcmp(str1, str2) << endl;

    cout << "Comparing strings: " << compareChar(str1, str2) << endl;

    return 0;
}