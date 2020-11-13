// Georgs Toliašvili, gt20010
// B1. Dots naturāls skaitis n. Atrast visus tādus naturālu skaitļu pārīšus a un b, kuri nepārsniedz n,
// lai a būtu  vienāds ar visu b dalītāju summu (izņemot b), un b būtu vienāds ar visu a dalītāju summu
// (izņemot a). Risinājumā izmantot funkciju, kas atpazīst pirmskaitļus.
// 17.09.2020

#include <iostream>

using namespace std;

bool returnValueSum(int mainValue, int pairValue, int pairValueSum)
{
    for (int x = 1; x < pairValue; x++)// We don't check if x == pairValue, because the task says, 
        // that a/b has to be equal to the divider bSum/aSum without the b/a value
    {
        if (pairValue % x == 0)
        {
            pairValueSum += x;
        }
    }

    if (mainValue == pairValueSum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isPrime(int n)
{
    for (int i = 2; i <= n / 2; i++) // i starts as 2, because 0 and 1 are not prime numbers.
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 0, b, bSum = 0, aSum = 0, keepRunning = 0;

    do {
        cout << "Enter a natural number:" << endl;

        cin >> n;

        if (n < 0)
        {
            cout << "Not a natural number\n" << endl;
        }
        else if (n == 0)
        {
            cout << "0 doesn't have any number pairs\n" << endl;
        }
        else {
            cout << "Pairs:\n" << endl;
        }

        for (int a = 0; a < n; a++)
        {
            if (isPrime(a))
            {
                continue;
            }

            for (int b = 0; b < n; b++)
            {
                if (isPrime(b))
                {
                    continue;
                }
                else if (a + b > n)
                {
                    break;
                }

                if (returnValueSum(a, b, bSum) && returnValueSum(b, a, aSum))
                {
                    cout << a << " " << b << "\nWorks\n" << endl;
                }
            }
        }

        cout << "\nDo you want to continue (1) or exit (0)?" << endl;

        cin >> keepRunning;
        cout << endl;

    } while (keepRunning == 1);
}