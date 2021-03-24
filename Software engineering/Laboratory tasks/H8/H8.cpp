// Georgs Toliašvili, gt20010
// H8.Dots bin�rs fails, kura glab�jas datumi, un kura ieraksta strukt�ra ir sekojo�a :
// gads(int), m�nesis(int), diena(int).Izdruk�t inform�ciju divos citos teksta failos,
// kur tie sak�rtoti attiec�gi hronolo�iski dilsto�i vai augo�i.Inform�cijas
// ielas��anai un sak�rto�anas nodro�in��anai izmantot strukt�ru STL map vai STL list.
// Papildus izveidot pal�gprogrammas bin�r� faila izveido�anai un t� satura izdruk��anai.
// 11.03.2021

//  Input                    | Desired Output | C++ Output
//  Ascending:               |                | Same
//  2007.3.16                | 2014.12.17     
//  2014.12.17               | 2010.4.28
//  2010.4.28                | 2007.3.16
//  Descending:              |                | Same
//  2007.3.16                | 2007.3.16     
//  2014.12.17               | 2010.4.28
//  2010.4.28                | 2014.12.17

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <map>

using namespace std;

struct date
{
    int year;
    int month;
    int day;
};

void createBinaryFile(fstream& fout, int arrSize)
{
    srand(time(NULL)); // time(NULL) returns time (seconds since Jan 1, 1970), which means that every time you launch
    // the program it will have a different seed that will be passed in the pseudo-random number generator

    int year;
    int month;
    int day;

    for (int x = 0; x < arrSize; x++)
    {
        bool leapYear = false;
        year = rand() % 21 + 2001;

        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0)
                {
                    leapYear = true;
                }
            }
            else
            {
                leapYear = true;
            }
        }

        month = rand() % 12 + 1;

        if (month == 2)
        {
            if (leapYear)
            {
                day = rand() % 29 + 1;
            }
            else
            {
                day = rand() % 28 + 1;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            day = rand() % 30 + 1;
        }
        else
        {
            day = rand() % 31 + 1;
        }

        fout.write((char*)&year, sizeof(int));
        fout.write((char*)&month, sizeof(int));
        fout.write((char*)&day, sizeof(int));
    }

    fout.close();
}

void printBinaryFileAndFillList(fstream& fin, map<int, date>& dates)
{
    int year;
    int month;
    int day;

    int index = 0;

    date newDate;

    while (fin)
    {
        fin.read((char*)&year, sizeof(int));
        fin.read((char*)&month, sizeof(int));
        fin.read((char*)&day, sizeof(int));

        if (!fin.eof()) // If this doesn't get checked, the program would repeat the last date 2 times
        {
            cout << year << "." << month << "." << day << endl;

            newDate.year = year;
            newDate.month = month;
            newDate.day = day;

            dates.insert(pair<int, date>(index, newDate));

            index++;
        }
    }

    cout << endl;

    fin.close();
}

void createTextFile(fstream& fout, map<int, date>& dates)
{
    for (auto& a : dates)
    {
        fout << a.second.year << "." << a.second.month << "." << a.second.day << endl;
    }

    fout.close();
}

bool compareDates(date first, date second)
{
    return (first.year < second.year) || (first.year == second.year && first.month < second.month)
        || (first.year == second.year && first.month == second.month && first.day < second.day);
}

void printList(map<int, date>& dates)
{
    for (auto& a : dates)
    {
        cout << a.second.year << "." << a.second.month << "." << a.second.day << endl;
    }

    cout << endl;
}

void sortList(map<int, date>& dates, bool ascending) // Using Selection sort
{
    if (ascending)
    {
        cout << "Ascending list" << endl;
    }
    else
    {
        cout << "Descending list" << endl;
    }

    cout << endl;

    cout << "Before sorting:" << endl;

    printList(dates);

    for (int i = 0; i < dates.size(); i++)
    {
        date currDate = dates[i];
        int currIndex = i;

        // Search for the minimum element in the rest of the array.
        date minDate = dates[i]; // Default it to the current element being min.
        int minIndex = i;

        for (int j = i + 1; j < dates.size(); j++)
        {
            date num = dates[j];
            int index = j;

            if (!ascending)
            {
                // If this element is smaller than the minimum so far, update the min variable.
                if (compareDates(num, minDate))
                {
                    minDate = num;
                    minIndex = index;
                }
            }
            else
            {
                // minDate - here is the largest element in the list
                if (compareDates(minDate, num))
                {
                    minDate = num;
                    minIndex = index;
                }
            }
        }

        // We found the smallest/largest element. Perform the swap.
        date temp = currDate;
        dates[currIndex] = minDate;
        dates[minIndex] = temp;
    }

    cout << "After sorting:" << endl;

    printList(dates);
}

int main()
{
    int numberOfDatesCreated;

    cout << "Enter the number of dates to generate: ";
    cin >> numberOfDatesCreated;

    map<int, date> dates;

    fstream streamOut("dates.bin", ios::out);
    fstream streamIn("dates.bin", ios::in);

    createBinaryFile(streamOut, numberOfDatesCreated);
    printBinaryFileAndFillList(streamIn, dates);

    fstream textFileAsc("ascending.txt", ios::out);

    sortList(dates, true);
    createTextFile(textFileAsc, dates);

    fstream textFileDes("descending.txt", ios::out);

    sortList(dates, false);
    createTextFile(textFileDes, dates);
}