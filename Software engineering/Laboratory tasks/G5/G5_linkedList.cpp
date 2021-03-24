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

struct element
{
    int value;
    element* next;
};

void addElementAsFirst(element*& firstEl)
{
    bool elementFound = false;
    int newNumber = rand() % 100; // Value between 0 and 99

    element* newFirstEl = firstEl; // Creating a new element that is equal to firstEl, so we can loop through the
    // list and not affect the actual firstEl next value

    while (newFirstEl != NULL)
    {
        if (newFirstEl->value == newNumber)
        {
            elementFound = true;
            break;
        }

        newFirstEl = newFirstEl->next;
    }

    cout << "Potential element: " << newNumber << endl;

    if (!elementFound)
    {
        element* newEl = new element;

        newEl->value = newNumber;
        newEl->next = firstEl;

        firstEl = newEl;
    }
}

void addElementAsLast(element*& firstEl, element*& lastEl, int valueToAdd)
{
    element* newEl = new element;
    newEl->value = valueToAdd;
    newEl->next = NULL;

    if (firstEl == NULL)
    {
        firstEl = lastEl = newEl;
    }
    else
    {
        lastEl->next = newEl;
        lastEl = lastEl->next;
    }
}

void printList(element* firstEl)
{
    while (firstEl != NULL)
    {
        cout << firstEl->value << " ";
        firstEl = firstEl->next;
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));// time(NULL) returns time (seconds since Jan 1, 1970), which means that every time you launch
    // the program it will have a different seed that will be passed in the pseudo-random number generator

    int command;

    element* currentEl = new element;
    element* firstEl = NULL;
    element* lastEl = NULL;

    cout << "0 - Exit\n" << "1 - Add Element\n" << "2 - Execute Function\n" << "3 - Show Array" << endl;
    cin >> command; // 0 - to exit the app; 1 - Add element to array; 2 - Execute the function; 3 - Display array

    while (command != 0)
    {
        cout << endl;
        switch (command)
        {
        case 1:
            int elementToAdd;

            cout << "Enter element: ";
            cin >> elementToAdd;

            cout << "Start list: ";
            printList(firstEl);

            addElementAsLast(firstEl, lastEl, elementToAdd); // The function asks for the first element of the list,
            // because, if the list is empty we want to make sure that the first and last elements are set to the
            // newly created element
            cout << elementToAdd << " added to array" << endl;

            cout << "End list: ";
            printList(firstEl);

            break;
        case 2:
            cout << "Start list: ";
            printList(firstEl);

            addElementAsFirst(firstEl);

            if (lastEl == NULL) // This is an edge case, if the user first decides to populate the list with the
            // function, then the firstEl gets set, but the lastEl doesn't, so I check after the function has
            // executed if it's NULL, if it is then we make sure that these elements are equal, this only happens
            // if the list has only one element.
            {
                lastEl = firstEl;
            }

            cout << "End list: ";
            printList(firstEl);
            break;
        case 3:
            cout << "List: ";
            printList(firstEl);
            break;
        }
        cout << endl;

        cout << "0 - Exit\n" << "1 - Add Element\n" << "2 - Execute Function\n" << "3 - Show Array" << endl;
        cin >> command; // 0 - to exit the app; 1 - Add element to array; 2 - Execute the function; 3 - Display array
    }

    currentEl = firstEl;
    while (currentEl != NULL)
    {
        firstEl = firstEl->next;
        delete currentEl;
        currentEl = firstEl;
    };
}