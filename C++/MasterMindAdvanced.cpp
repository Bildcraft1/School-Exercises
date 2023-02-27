#include <iostream>
#include <array>
#include <random>

std::random_device rd;
std::mt19937 rng(rd());

template<size_t SIZE>
void codiceCasuale(std::array<char, SIZE> &code) {
    std::uniform_int_distribution<int> random_number(0, 8);

    for (int i = 0; i < SIZE; i++) {
        int random = random_number(rng);
        switch (random) {
            case 0:
                code[i] = 'R';
                break;
            case 1:
                code[i] = 'G';
                break;
            case 2:
                code[i] = 'B';
                break;
            case 3:
                code[i] = 'Y';
                break;
            case 4:
                code[i] = 'O';
                break;
            case 5:
                code[i] = 'P';
                break;
            case 6:
                code[i] = 'W';
                break;
            case 7:
                code[i] = 'V';
                break;
            case 8:
                code[i] = 'M';
                break;  
        }
    }
}

template<size_t SIZE>
void inserisciCodice(std::array<char, SIZE> &answer) {
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Inserisci il " << i + 1 << "° colore: ";
        std::cout.flush();
        std::cin >> answer[i];
    }
}

template<size_t SIZE>
bool checkCode(std::array<char, SIZE> &code, std::array<char, SIZE> &answer) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (code[i] == answer[i]) {
            count++;
        }
    }

    if (count == SIZE) {
        return true;
    } else {
        return false;
    }
}

template<size_t SIZE>
void bullsAndCows(std::array<char, SIZE> &code, std::array<char, SIZE> &answer) {
    int bulls = 0, cows = 0;
    for (int i = 0; i < SIZE; i++) {
        if (code[i] == answer[i]) {
            bulls++;
        } else {
            for (int j = 0; j < SIZE; j++) {
                if (code[i] == answer[j]) {
                    cows++;
                }
            }
        }
    }

    std::cout << "Colori in posizione giusta: " << bulls << std::endl;
    std::cout << "Colori giusti ma in posizione sbagliata: " << cows << std::endl;
}

template<typename Iterator>
void printCode(Iterator begin, Iterator end) {
    while (begin != end) {
        std::cout << *begin << ' ';
        begin++;
    }
    std::cout << std::endl;
}

int main() {
    std::array<char, 4> code, answer;
    int maxTries = 10, tries = 0;
    bool win = false;
    codiceCasuale(code);

    for (int i = 0; i < 4; i++) {
        std::cout << code[i] << ' ';
    }
    std::cout << std::endl;

    while (tries < maxTries && !win) {
        inserisciCodice(answer);

        if(checkCode(code, answer)) {
            win = true;
        } else {
            tries++;
        }

        bullsAndCows(code, answer);
    }

    if (win) {
        std::cout << "Hai vinto!" << std::endl;
    } else {
        std::cout << "Hai perso!" << std::endl;
        std::cout << "La sequenza era: ";
        printCode(code.begin(), code.end());
    }

    return 0;
}
