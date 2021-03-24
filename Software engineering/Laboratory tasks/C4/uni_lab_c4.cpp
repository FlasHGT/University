// Georgs Toliašvili, gt20010
// C4. Dota skaitļu virkne a(1), a(2),  , a(n), kur visi elementi ir pa pāriem atšķirīgi.
// Samainīt vietām šajā virknē lielāko un pēdējo elementu.
// 23.09.2020

#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main()
{
    random_device rd; // creates a seed
    mt19937 mt(rd()); // generates random numbers from the given seed
    uniform_int_distribution<int> dist(-50, 50); // value type and range in which the number generator operates in

    int arrayLength, maxValue;
    int keepRunning = 1; // If the value was not set to 1, the program would crash after the "continue;" statement, because
    // keepRunning wouldn't have a value.
    int maxValueIndex = 0; // Starts with 0, because the first value is the largest until the program starts looping through the array

    do {
        cout << "Enter a number, which will represent the length of the array" << endl;

        cin >> arrayLength;

        if (cin.good() && arrayLength > 0) // cin.good() checks if the input value has the same data type as the variable
        {
            vector<int> numbers; // dynamic array, which allows me to fill it out at runtime

            cout << "Index  Value" << endl;

            for (int x = 0; x < arrayLength; x++)
            {
                numbers.push_back(dist(mt)); // push_back() adds a value to the array after the last element
                // dist(mt) generates an int between the set range
                cout << x << "      " << numbers[x] << endl;
            }

            maxValue = numbers[0];
            maxValueIndex = 0;

            for (int y = 1; y < arrayLength; y++) // Starts at one, because maxValue has been set to the first element in the array
            {
                if (maxValue < numbers[y])
                {
                    maxValue = numbers[y];
                    maxValueIndex = y;
                }
            }

            if (maxValueIndex != numbers.size() - 1)
            {
                numbers[maxValueIndex] = numbers[numbers.size() - 1];
                numbers[numbers.size() - 1] = maxValue;

                cout << "Max value:\n" << maxValueIndex << "      " << maxValue << endl;
                cout << "Last value after replacing:\n" << numbers.size() - 1 << "      " << numbers[numbers.size() - 1] << endl;
                cout << "Replaced value:\n" << maxValueIndex << "      " << numbers[maxValueIndex] << endl;
            }
            else
            {
                cout << "Last value is the largest:\n" << maxValueIndex << "      " << numbers[maxValueIndex] << endl;
            }
        }
        else
        {
            if (cin.good() && arrayLength <= 0)
            {
                cout << "Negative numbers and 0 can't represent array length\n" << endl;
            }
            else
            {
                cout << "Not a number\n" << endl;
            }

            cin.clear(); // clears the error that has been caused by the user inputting an invalid value
            // (not clearing it would cause cin not to take in any future input)
            cin.ignore(256, '\n'); // removes the input content that caused the error and prevents the loop from infinitely looping
            continue;
        }

        cout << "\nDo you want to continue (1) or exit (0)?" << endl;

        cin >> keepRunning;
        cout << endl;
    } while (keepRunning == 1);
}
