#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

int validateInput(string command, int min, int max);

// List

void l_addElementAsFirst(list<int>& thisList);
void l_addElementAsLast(list<int>& thisList, int element);
void l_printList(list<int>& thisList);
int l_main(vector<string> commands, vector<string> elementsToAdd);

// Linked List

struct element { int value; element* next; };
void ll_addElementAsFirst(element*& firstEl);
void ll_addElementAsLast(element*& firstEl, element*& lastEl, int valueToAdd);
void ll_printList(element* firstEl);
int ll_main(vector<string> commands, vector<string> elementsToAdd);