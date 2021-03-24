// Georgs Toliašvili, gt20010
// G5.Uzrakst�t funkciju, kas pieliek sarakstam jaunu elementu saraksta s�kum�, ja elements ar t�du v�rt�bu neeksist�.
// 24.02.2021

//  Input                    | Desired Output | C++ Output
//  addElementAsLast(0)      | Element Added  | listEnd = 0
//  addElementAsLast(5)      | Element Added  | listEnd = 5
//  addElementAsLast(-2)     | Element Added  | listEnd = -2
//  addElementAsFirst()      | Element Added  | listFront = x

#include <iostream>
#include <list>

using namespace std;

void addElementAsFirst(list<int>& thisList)
{
    bool elementFound = false;
    int newNumber = rand() % 100; // Value between 0 and 99

    for (auto& a : thisList)
    {
        if (newNumber == a)
        {
            elementFound = true;
            break;
        }
    }

    cout << "Potential element: " << newNumber << endl;

    if (!elementFound)
    {
        thisList.push_front(newNumber);
    }
}

void addElementAsLast(list<int>& thisList, int element)
{
    thisList.push_back(element);
}

void printList(list<int>& thisList)
{
    for (auto& a : thisList)
    {
        cout << a << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));// time(NULL) returns time (seconds since Jan 1, 1970), which means that every time you launch
    // the program it will have a different seed that will be passed in the pseudo-random number generator

    int elementToAdd;
    int command;

    list<int> myList;

    cout << "0 - Exit\n" << "1 - Add Element\n" << "2 - Execute Function\n" << "3 - Show Array" << endl;
    cin >> command; // 0 - to exit the app; 1 - Add element to array; 2 - Execute the function; 3 - Display array

    while (command != 0)
    {
        cout << endl;
        switch (command)
        {
        case 1:
            cout << "Enter element: ";
            cin >> elementToAdd;

            cout << "Start list: ";
            printList(myList);

            addElementAsLast(myList, elementToAdd);
            cout << elementToAdd << " added to array" << endl;

            cout << "End list: ";
            printList(myList);
            break;
        case 2:
            cout << "Start list: ";
            printList(myList);

            addElementAsFirst(myList);

            cout << "End list: ";
            printList(myList);
            break;
        case 3:
            cout << "List: ";
            printList(myList);
            break;
        }
        cout << endl;

        cout << "0 - Exit\n" << "1 - Add Element\n" << "2 - Execute Function\n" << "3 - Show Array" << endl;
        cin >> command; // 0 - to exit the app; 1 - Add element to array; 2 - Execute the function; 3 - Display array
    }

    myList.clear();
}