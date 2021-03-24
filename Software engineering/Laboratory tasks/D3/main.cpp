//D3. "Izveidot klasi ""Datums"", kurā tiek glabāti trīs skaitļi - gads, mēnesis, datums.
//Klasei izveidot šādas metodes: (1) konstruktors, ar kuru tiek padotas sākotnējās vērtības,
//(2) destruktors, kurš paziņo par objekta likvidēšanu, (3) metode ""Mainīt"" ar trīs parametriem,
//kas uzstāda jaunās vērtības, (4) metode ""Drukāt"", kas izdrukā datumu, (5) metode ""Aprēķins"",
//kas aprēķina un izdrukā nākošo datumu."

#include <iostream>
#include "program.h"
#include <ctime>

using namespace std;

int main() 
{
    int action; // 0 - Change current date, 1 - Print current date, 2 - Calculate next day, 3 - Exit the program

    struct tm newtime; // Structure which contains date components
    time_t now = time(0); // Represents a time, but 0 prevents the variable from being declared with a time value
    localtime_s(&newtime, &now); // Converts a time_t time value to a tm structure

    Date date(newtime.tm_mday, newtime.tm_mon + 1, newtime.tm_year + 1900); // tm_year gets counted from 1900
    // tm_mon starts from 0, so 1 gets added.
    date.print(date);

    do {
        cout << "\nMenu:\n" << "    Change current date (0)\n"
        << "    Print current date (1)\n"
        << "    Calculate next date (2)\n" 
        << "    Exit (3)" << endl;

        cin >> action;
        cout << endl;

        if (cin.good() && action <= 2 && action >= 0)
        {
            switch (action)
            {
                case 0:
                    int day, month, year;

                    cout << "Enter day:" << endl;
                    cin >> day;
                    cout << "Enter month:" << endl;
                    cin >> month;
                    cout << "Enter year:" << endl;
                    cin >> year;

                    date.change(day, month, year);

                    break;
                case 1:
                    date.print();
                    break;
                case 2:
                    date.calculate();
                    break;
            }
        }
        else
        {
            cout << "Incorrect input" << endl;

            cin.clear(); // clears the error that has been caused by the user inputting an invalid value
            // (not clearing it would cause cin not to take in any future input)
            cin.ignore(256, '\n'); // removes the input content that caused the error and prevents the loop from infinitely looping
        }
    }while (action != 3);
}
