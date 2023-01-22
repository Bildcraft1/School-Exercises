#include <iostream>
#include <cstdlib>

using namespace std;

bool numberIsPositive (int number)
{
    if (number > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool numberIsEven (int number)
{
    if (number % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool numberIsPrime (int number)
{
    if (number == 1)
    {
        return false;
    }
    else if (number == 2)
    {
        return true;
    }
    else
    {
        for (int i = 2; i <= number / 2; ++i)
        {
            if (number % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

int numberDivisors (int number, bool output)
{
    int divisors = 0;
    for (int i = 1; i <= number; ++i)
    {
        if (number % i == 0)
        {
            divisors++;

            if (output == true)
            {
                cout << i << endl;
            }
        }
    }
    return divisors;
}


int main()
{
    int input;
    cout << "Inserire numero: ";
    cin >> input;

    while (numberIsPositive(input) == false)
    {
        cout << "Il numero inserito non è positivo. Riprovare: ";
        cin >> input;
    }

    if (numberIsEven(input) == true)
    {
        cout << "Il numero inserito è pari." << endl;
    }
    else
    {
        cout << "Il numero inserito è dispari." << endl;
    }

    if (numberIsPrime(input) == true)
    {
        cout << "Il numero inserito è primo." << endl;
    }
    else
    {
        cout << "Il numero inserito non è primo." << endl;
    }

    cout << "Il numero inserito ha " << numberDivisors(input, false) << " divisori." << endl;

    cout << "I divisori del numero inserito sono: " << endl;
    numberDivisors(input, true);

    system("pause");
    return 0;

}