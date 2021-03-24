//D3. "Izveidot klasi ""Datums"", kurā tiek glabāti trīs skaitļi - gads, mēnesis, datums.
//Klasei izveidot šādas metodes: (1) konstruktors, ar kuru tiek padotas sākotnējās vērtības,
//(2) destruktors, kurš paziņo par objekta likvidēšanu, (3) metode ""Mainīt"" ar trīs parametriem,
//kas uzstāda jaunās vērtības, (4) metode ""Drukāt"", kas izdrukā datumu, (5) metode ""Aprēķins"",
//kas aprēķina un izdrukā nākošo datumu."

#include "program.h"
#include <iostream>
#include <string>

using namespace std;

Date::Date(int newDay, int newMonth, int newYear)
{
    day = newDay;
    month = newMonth;
    year = newYear;
}

int Date::change(int newDay, int newMonth, int newYear)
{
    Date date(newDay, newMonth, newYear);

    if (validateInput(date) == 1) // 1 - Valid, 0 - Invalid
    {
        day = date.day;
        month = date.month;
        year = date.year;

        print();
        return 1;
    }
    else
    {
        return 0;
    }
}

void Date::print(Date date)
{
    cout << "DD/MM/YYYY" << endl;

    string outputDay = to_string(date.day);
    string outputMonth = to_string(date.month);

    if (date.day < 10)
    {
        outputDay.insert(0, "0");
    }

    if (date.month < 10)
    {
        outputMonth.insert(0, "0");
    }

    if (year < 0)
    {
        cout << outputDay << "." << outputMonth << "." << -year << " BC" << endl;
    }
    else
    {
        cout << outputDay << "." << outputMonth << "." << year << " AD" << endl;
    }
}

void Date::print()
{
    cout << "\nDD/MM/YYYY" << endl;

    string outputDay = to_string(day);
    string outputMonth = to_string(month);

    if (day < 10)
    {
        outputDay.insert(0, "0");
    }

    if (month < 10)
    {
        outputMonth.insert(0, "0");
    }

    if (year < 0)
    {
        cout << outputDay << "." << outputMonth << "." << -year << " BC" << endl;
    }
    else
    {
        cout << outputDay << "." << outputMonth << "." << year << " AD" << endl;
    }
}

void Date::calculate()
{
    int newDay = day;
    int newMonth = month;
    int newYear = year;

    if (newMonth == 12 && newDay == 31)
    {
        newDay = 1;
        newMonth = 1;
        newYear++;
    }
    else if (newMonth == 2 && (newDay == 28 || newDay == 29))
    {
        if ((newYear % 400 == 0 || newYear % 4 == 0 && newYear % 100 != 0))
        {
            if (newDay == 29)
            {
                newDay = 1;
                newMonth++;
            }
            else
            {
                newDay++;
            }
        }
        else
        {
            newDay = 1;
            newMonth++;
        }
    }
    else if ((newMonth == 4 || newMonth == 6 ||
              newMonth == 9 || newMonth == 11) && newDay == 30)
    {
        newDay = 1;
        newMonth++;
    }
    else if (newDay == 31)
    {
        newDay = 1;
        newMonth++;
    }
    else
    {
        newDay++;
    }

    Date date(newDay, newMonth, newYear);
    print(date);
}

Date::~Date()
{
    // Automatically gets deleted
}

int Date::validateInput(Date date)
{
    if ((date.day > 0 && date.day <= 31) && (date.month > 0 && date.month <= 12))
    {
        if (date.year % 400 == 0 || date.year % 4 == 0 && date.year % 100 != 0)
        {
            if (date.month == 2 && date.day > 29)
            {
                cout << "There can't be more than 29 days in february during a leap year" << endl;
                return 0;
            }
        }
        else
        {
            if (date.month == 2 && date.day > 28)
            {
                cout << "There can't be more than 28 days in february during a normal year" << endl;
                return 0;
            }
        }

        if ((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && date.day == 31)
        {
            cout << "There can't be more than 30 days in April/June/September/November" << endl;;
            return 0;
        }
    }
    else
    {
        cout << "Months and days can't be negative or 0, days can't exceed 31, but months can't exceed 12" << endl;;
        return 0;
    }

    return 1;
}
