#include <iostream>
#include "Functions.h"

using namespace std;

// == x represents the number of elements in the list after executing all commands
bool l_testA() 
{
    int amountOfElements = l_main({ "1", "12", "sa" }, { "s", "2", "32" });
    return amountOfElements == 0;
}

bool l_testB()
{
    int amountOfElements = l_main({ "1", "2", "1" }, { "5", "0", "a" });
    return amountOfElements > 0; // 1 or 2
}

bool l_testC()
{
    int amountOfElements = l_main({ "2", "2", "2" }, { "5", "2", "a" });
    return amountOfElements != 0; // 1 or 2 or 3
}

bool ll_testA()
{
    int amountOfElements = ll_main({ "1", "12", "sa" }, { "s", "2", "32" });
    return amountOfElements == 0;
}

bool ll_testB()
{
    int amountOfElements = ll_main({ "1", "2", "1" }, { "5", "0", "a" });
    return amountOfElements > 0; // 1 or 2
}

bool ll_testC()
{
    int amountOfElements = ll_main({ "2", "2", "2" }, { "%", "2", "a" });
    return amountOfElements != 0; // 1 or 2 or 3
}

int main()
{
    cout << l_testA() << endl;
    cout << l_testB() << endl;
    cout << l_testC() << endl;
    cout << ll_testA() << endl;
    cout << ll_testB() << endl;
    cout << ll_testC() << endl;
}
