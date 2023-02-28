#include <iostream>
#include <array>
#include <random>
#include "utils/systemutils.h"

std::random_device rd;
std::mt19937 rng(rd());

int menu()
{
    int choice;
    std::cout << "1. Gioca" << std::endl;
    std::cout << "2. Esci" << std::endl;
    std::cout << "Scelta: ";
    std::cout.flush();
    std::cin >> choice;
    return choice;
}

template <size_t SIZE>
void codiceCasuale(std::array<char, SIZE> &code)
{
    std::uniform_int_distribution<int> random_number(0, 8);

    for (int i = 0; i < SIZE; i++)
    {
        int random = random_number(rng);
        switch (random)
        {
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

template <size_t SIZE>
bool checkCode(std::array<char, SIZE> &code, std::array<char, SIZE> &answer)
{
    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (code[i] == answer[i])
        {
            count++;
        }
    }

    if (count == SIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <size_t SIZE>
void checkPos(std::array<char, SIZE> &code, std::array<char, SIZE> &answer)
{
    int posGiusta = 0, posErrata = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (code[i] == answer[i])
        {
            posGiusta++;
        }
        else
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (code[i] == answer[j])
                {
                    posErrata++;
                }
            }
        }
    }

    std::cout << "Colori in posizione giusta: " << posGiusta << std::endl;
    std::cout << "Colori giusti ma in posizione sbagliata: " << posErrata << std::endl;
}

template <typename Iterator>
void printCode(Iterator begin, Iterator end)
{
    while (begin != end)
    {
        std::cout << *begin << ' ';
        begin++;
    }
    std::cout << std::endl;
}

template <size_t SIZE>
void inserisciCodice(std::array<char, SIZE> &answer)
{
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "Inserisci il " << i + 1 << "° colore: ";
        std::cout.flush();
        std::cin >> answer[i];

        if (answer[i] >= 'a' && answer[i] <= 'z')
        {
            answer[i] -= 32;
        }
    }

    std::cout << std::endl;

    std::cout << "Codice inserito: ";
    std::cout.flush();
    printCode(answer.begin(), answer.end());
}

int main()
{
    std::array<char, 4> code, answer;
    int maxTries = 10, tries = 0, input = 0;
    bool win = false;
    codiceCasuale(code);

    std::cout << "Benvenuto in MasterMind!" << std::endl;
    std::cout << std::endl;

    do
    {

        input = menu();

        while (tries < maxTries && !win && input == 1)
        {
            clearScreen();

            inserisciCodice(answer);

            if (checkCode(code, answer))
            {
                win = true;
            }
            else
            {
                tries++;
            }

            checkPos(code, answer);

            if (!win)
            {
                std::cout << "Tentativi rimanenti: " << maxTries - tries << std::endl;
                pause();
            }
        }

        if (win && input == 1)
        {
            std::cout << "Hai vinto!" << std::endl;
            pause();
        }
        else if (tries == maxTries && input == 1)
        {
            std::cout << "Hai perso!" << std::endl;
            std::cout << "La sequenza era: ";
            printCode(code.begin(), code.end());
            pause();

            // Reset variabili
            win = false;
            tries = 0;
            codiceCasuale(code);
        }

        std::cout << std::endl;

    } while (input != 2);

    return 0;
}
