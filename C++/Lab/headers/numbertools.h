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
                cout << i << " ";
            }
        }
    }
    return divisors;
}
