// Georgs Toliašvili, gt20010
// A7. Dots naturāls skaitlis n. Izdrukāt visus dotā skaitļa dalītījus.
// 15.09.2020

#include <iostream>

using namespace std;

int keepRunning, n;

int main()
{
    do
    {
        cout << "Ievadiet naturālu skaitli:" << endl;

        cin >> n;

        if (n < 0) { // negatīvi skaitļi
            cout << "Netika ievadīts naturāls skaitlis" << endl;
        }
        else {
            if (n == 0)
            {
                cout << "0 nav dalītāju" << endl;
            }
            else
            {
                cout << "Visi " << n << " dalītāji:" << endl;

                for (int x = 1; x <= n; x++) // Sāk no viens, jo ar 0 nevar dalīt
                {
                    if (n % x == 0) {
                        cout << x << endl;
                    }
                }
            }
        }

        cout << "\nVai turpināt (1) vai beigt (0)?" << endl;

        cin >> keepRunning;

    } while (keepRunning == 1);
}