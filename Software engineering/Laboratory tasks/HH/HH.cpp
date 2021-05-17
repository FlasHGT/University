// Georgs Toliašvili, gt20010
// HH. Uzrakstīt programmu, kas ļauj izveidot un labot bināru failu, kura glabājas datumi, 
// un kura ieraksta struktūra ir sekojoša : gads(int), mēnesis(int), diena(int), ieraksta statuss(0 vai 1).
// Programmai katrs jauns ieraksts jāieliek faila beigās.Ja failā tāds datums jau eksistē, tas nav 
// jāpieliek.Jāparedz iespēja(1) izmest faila komponenti(loģiski atzīmējot kā izmestu),
// (2) izdrukāt failā esošos datumus uz ekrāna, (3) izmest loģiski izmestas komponentes fiziski.
// 31.03.2021

#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

struct BinStruct
{
    int year;
    int month;
    int day;
    bool status;

public:
    BinStruct(int year, int month, int day, bool status)
    {
        this->year = year;
        this->month = month;
        this->day = day;
        this->status = status;
    }
};

bool operator==(const BinStruct& x, const BinStruct& y)
{
    return x.year == y.year && x.month == y.month && x.day == y.day;
}

void fillBinaryFile(ofstream& f, vector<BinStruct>& structs, int arrSize = NULL)
{
    if (arrSize != NULL)
    {
        srand(time(NULL)); // time(NULL) returns time (seconds since Jan 1, 1970),
        // which means that every time you launch the program it will have a 
        // different seed that will be passed in the pseudo-random number generator

        int year;
        int month;
        int day;
        bool status = 1;

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

            BinStruct currStruct(year, month, day, status);
            bool elFound = false;

            for (int x = 0; x < structs.size(); x++)
            {
                if (currStruct == structs[x])
                {
                    elFound = true;
                    break;
                }
            }

            if (!elFound)
            {
                f.write((char*)&currStruct, sizeof(BinStruct));
                structs.push_back(currStruct);
            }
        }
    }
    else
    {
        // If arrSize doesn't get provided then we are not trying to create new data,
        // we are populating the file with the existing data from the dynamic array
        for (int x = 0; x < structs.size(); x++)
        {
            f.write((char*)&structs[x], sizeof(BinStruct));
        }
    }


    f.close();
}

void printList(vector<BinStruct> structs)
{
    cout << "Index  Status  Date" << endl;
    for (int x = 0; x < structs.size(); x++)
    {
        cout << x << "      " << structs[x].status << "       " << structs[x].year
            << "." << structs[x].month << "." << structs[x].day << endl;
    }
    cout << endl;
}

void removeMarkedElements(vector<BinStruct>& structs)
{
    for (int x = 0; x < structs.size(); x++)
    {
        if (!structs[x].status)
        {
            structs.erase(structs.begin() + x);
            x--;
        }
    }
}

void validateInput(int& command, int min, int max)
{
    cin >> command;

    while (true)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That was not a number, please enter a number!" << endl;
        }
        else if (!(command <= max && command >= min))
        {
            cout << "Please enter a number between " << min << " and " << max  << "!" << endl;
        }
        else 
        {
            break;
        }

        cin >> command;
    }
}

int main()
{
    int command = 0, numberOfDatesToCreate = 0;
    string fileLoc = "dates.bin";

    ofstream fout(fileLoc, ios::binary);

    vector<BinStruct> structs;

    cout << "Enter the number of dates to generate(1-100): ";
    validateInput(numberOfDatesToCreate, 1, 100);
    cout << endl;

    fillBinaryFile(fout, structs, numberOfDatesToCreate);

    cout << "0 - Exit\n" << "1 - Mark an Element\n" << "2 - Display Elements\n" << "3 - Remove Marked Elements" << endl;
    validateInput(command, 0, 3); // 0 - to exit the app; 1 - Mark element to remove; 2 - Display elements; 3 - Remove marked elements

    while (command != 0)
    {
        cout << endl;
        switch (command)
        {
            case 1:
            {
                int elementToRemove, bytesToOffset;
                bool status = false;

                cout << "Enter element index: ";
                validateInput(elementToRemove, 0, structs.size() - 1);

                ofstream fout(fileLoc, ios::binary | ios::in);
                // ios::in gets provided, so a new file doesn't get created

                bytesToOffset = ((sizeof(int) * 3 + sizeof(bool) + 3) * elementToRemove) + 12;
                // sizeof(int) = 4B
                // 4B * 3, represents year/month/day
                // sizeof(bool) = 1B, + 3 represents the additional bytes that get added
                // to the end of a struct

                fout.seekp(bytesToOffset, ios::beg); // navigating through a binary file
                fout.write((char*)&status, sizeof(bool)); // the next byte/s get overwritten

                fout.close();

                structs[elementToRemove].status = status;
                break;
            }
            case 2:
            {
                printList(structs);
                break;
            }
            case 3:
            {
                removeMarkedElements(structs);

                remove(fileLoc.c_str()); // Deletes file

                ofstream fout(fileLoc, ios::binary); // Creates a new file

                fillBinaryFile(fout, structs);
                break;
            }
        }
        cout << endl;

        cout << "0 - Exit\n" << "1 - Mark an Element\n" << "2 - Display Elements\n" << "3 - Remove Marked Elements" << endl;
        validateInput(command, 0, 3); // 0 - to exit the app; 1 - Mark element to remove; 2 - Display elements; 3 - Remove marked elements
    }
}