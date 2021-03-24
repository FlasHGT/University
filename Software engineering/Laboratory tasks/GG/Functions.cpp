#include "Functions.h"
#include <limits>


int validateInput(string command, int min, int max)
{
    try
    {
        int newCom = stoi(command);

        if (!(newCom <= max && newCom >= min))
        {
            throw 0;
        }
        else
        {
            return newCom;
        }
    }
    catch (int err_num) {
        cout << "This " << command << " is not between " << min << " and " << max << endl;
    }
    catch (...)
    {
        cout << "This " << command << " is not a number" << endl;
    }

    return -1;
}

void l_addElementAsFirst(list<int>& thisList)
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

    //cout << "Potential element: " << newNumber << endl;

    if (!elementFound)
    {
        thisList.push_front(newNumber);
    }
}

void l_addElementAsLast(list<int>& thisList, int element)
{
    thisList.push_back(element);
}

void l_printList(list<int>& thisList)
{
    for (auto& a : thisList)
    {
        cout << a << " ";
    }
    cout << endl;
}

int l_main(vector<string> commands, vector<string> elementsToAdd)
{
    int index = 0;
    
    list<int> myList;

    srand(time(NULL));// time(NULL) returns time (seconds since Jan 1, 1970), which means that every time you launch
    // the program it will have a different seed that will be passed in the pseudo-random number generator

    while (index != commands.size()) 
    {
        int command = validateInput(commands[index], 0 , 3);
        int elementToAdd;

        if (command == 1)
        {
            elementToAdd = validateInput(elementsToAdd[index], 0, 99);
        }

        while (command > 0)
        {
            switch (command)
            {
                case 1:
                    if (elementToAdd == -1)
                    {
                        break;
                    }

                    /*cout << "Start list: ";
                    l_printList(myList);*/

                    l_addElementAsLast(myList, elementToAdd);
                    //cout << elementToAdd << " added to array" << endl;

                    /*cout << "End list: ";
                    l_printList(myList);*/
                    break;
                case 2:
                    /*cout << "Start list: ";
                    l_printList(myList);*/

                    l_addElementAsFirst(myList);

                    /*cout << "End list: ";
                    l_printList(myList);*/
                    break;
                case 3:
                    /*cout << "List: ";
                    l_printList(myList);*/
                    break;
            }

            command = 0;
        }

        index++;
    }

    int listSize = myList.size();
    myList.clear();

    return listSize;
}

void ll_addElementAsFirst(element*& firstEl)
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

    //cout << "Potential element: " << newNumber << endl;

    if (!elementFound)
    {
        element* newEl = new element;

        newEl->value = newNumber;
        newEl->next = firstEl;

        firstEl = newEl;
    }
}

void ll_addElementAsLast(element*& firstEl, element*& lastEl, int valueToAdd)
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

void ll_printList(element* firstEl)
{
    while (firstEl != NULL)
    {
        cout << firstEl->value << " ";
        firstEl = firstEl->next;
    }
    cout << endl;
}

int ll_main(vector<string> commands, vector<string> elementsToAdd)
{
    int index = 0;

    element* currentEl = new element;
    element* firstEl = NULL;
    element* lastEl = NULL;

    srand(time(NULL));// time(NULL) returns time (seconds since Jan 1, 1970), which means that every time you launch
    // the program it will have a different seed that will be passed in the pseudo-random number generator

    while (index != commands.size())
    {
        int command = validateInput(commands[index], 0, 3);
        int elementToAdd;

        if (command == 1)
        {
            elementToAdd = validateInput(elementsToAdd[index], 0, 99);
        }

        while (command > 0)
        {
            //cout << endl;
            switch (command)
            {
                case 1:
                    if (elementToAdd == -1)
                    {
                        break;
                    }

                    /*cout << "Start list: ";
                    ll_printList(firstEl);*/

                    ll_addElementAsLast(firstEl, lastEl, elementToAdd); // The function asks for the first element of the list,
                    // because, if the list is empty we want to make sure that the first and last elements are set to the
                    // newly created element
                    //cout << elementToAdd << " added to array" << endl;

                    /*cout << "End list: ";
                    ll_printList(firstEl);*/

                    break;
                case 2:
                    /*cout << "Start list: ";
                    ll_printList(firstEl);*/

                    ll_addElementAsFirst(firstEl);

                    if (lastEl == NULL) // This is an edge case, if the user first decides to populate the list with the
                    // function, then the firstEl gets set, but the lastEl doesn't, so I check after the function has
                    // executed if it's NULL, if it is then we make sure that these elements are equal, this only happens
                    // if the list has only one element.
                    {
                        lastEl = firstEl;
                    }

                    /*cout << "End list: ";
                    ll_printList(firstEl);*/
                    break;
                case 3:
                    /*cout << "List: ";
                    ll_printList(firstEl);*/
                    break;
            }
            //cout << endl;

            command = 0;
        }

        index++;
    }

    int listSize = 0;

    currentEl = firstEl;
    while (currentEl != NULL)
    {
        firstEl = firstEl->next;
        delete currentEl;
        currentEl = firstEl;
        listSize++;
    };

    return listSize;
}