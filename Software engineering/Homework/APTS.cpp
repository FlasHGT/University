#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

// If {} doesn't get added to variables then the IDE complains about them not having default initializers
struct inputStruct {
    int time{};
    char action{};
    char PK[12]{}; // + 1 size for \0
    char CD[50]{};

    inputStruct()
    {
        PK[11] = '\0';
        // Marks the end of the data
        // We don't do this to CD, because those characters are last in the line
    };
};

struct outputStruct {
    int time{};
    char firstPK[12]{};
    char lastPK[12]{};
};

template <typename T>
class node {
public:
    T info;
    node<T>* next{};

    node() {};
};

void copyCharArray(char dest[], char source[])
{
    for (int i = 0; source[i] != '\0'; i++)
    {
        dest[i] = source[i];
    }
}

bool compareCharArray(char a[], char b[])
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}

void saveInput(ifstream& fin, node<inputStruct>*& first, node<inputStruct>*& current)
{
    inputStruct newStruct;
    node<inputStruct>* n = NULL;

    while (!fin.eof())
    {
        fin >> newStruct.time;

        fin.clear(); // Ignores any errors
        fin.ignore(1); // Ignoring next character in file
        fin >> newStruct.action;

        fin.clear();
        fin.ignore(1);
        fin >> newStruct.PK;

        fin.clear();
        fin.ignore(1);
        fin >> newStruct.CD;

        n = new node<inputStruct>;
        n->info = newStruct;
        n->next = NULL;

        if (first == NULL)
        {
            first = current = n;
        }
        else
        {
            current->next = n;
            current = current->next;
        }
    }
}

void printToFile(ofstream& fout, node<outputStruct>*& first)
{
    node<outputStruct>* n;

    if (first == NULL)
        // The file will be empty, if there is nothing to output
    {
        fout << 0;
    }
    else
    {
        // This code works on the server, but not on my computer.
        if (first->next == NULL)
        {
            fout << first->info.time << ' ' << first->info.firstPK << ' ' << first->info.lastPK << '\n';
        }
        else 
        {
            while (first->next != NULL)
            {
                fout << first->info.time << ' ' << first->info.firstPK << ' ' << first->info.lastPK << '\n';

                n = first;
                first = first->next;
                delete n;
            }
        }

        delete first;

        // This should work, but it doesn't. Works on my computer, but not on the server.
        /*while (first != NULL)
        {
            fout << first->info.time << ' ' << first->info.firstPK << ' ' << first->info.lastPK << '\n';

            n = first;
            first = first->next;
            delete n;
        }*/
    }
}

void addToOutputList(node<outputStruct>*& first, node<outputStruct>* n)
{
    node<outputStruct>* current, *prev = NULL;

    if (first == NULL)
    {
        first = n;
    }
    else
    {
        current = first;

        while (true)
        {
            if (current == NULL)
            {
                prev->next = n;
                break;
            }

            if (current->info.time > n->info.time)
            {
                if (current == first)
                {
                    n->next = first;
                    first = n;
                    break;
                }

                prev->next = n;
                n->next = current;
                break;
            }

            prev = current;
            current = current->next;
        }
    }
}

node<outputStruct>* createNewOutputNode(node<inputStruct>*& first, node<inputStruct>*& current)
{
    outputStruct s;
    node<outputStruct>* n = new node<outputStruct>;

    if (first->info.action == 'B')
    {
        copyCharArray(s.firstPK, current->info.PK);
        copyCharArray(s.lastPK, first->info.PK);
    }
    else
    {
        copyCharArray(s.firstPK, first->info.PK);
        copyCharArray(s.lastPK, current->info.PK);
    }

    s.time = current->info.time;

    n->info = s;
    n->next = NULL;

    return n;
}

void createOutput(ofstream& fout, node<inputStruct>*& first, node<inputStruct>*& current)
{
    bool pairFound;

    node<inputStruct>* prev, *n;

    node<outputStruct>* oFirst = NULL;

    while (first != NULL)
    {
        pairFound = false;

        prev = first;
        current = first->next;

        while (current != NULL && !pairFound)
        {
            if (first->info.action != current->info.action && compareCharArray(first->info.CD, current->info.CD))
            {
                addToOutputList(oFirst, createNewOutputNode(first, current));

                n = first;

                if (first->next == current)
                {
                    first = current->next;
                }
                else
                {
                    first = first->next;
                }

                delete n;

                n = current;
                prev->next = current->next;
                delete n;

                pairFound = true;
                break;
            }

            prev = current;
            current = current->next;
        }

        if (!pairFound && current == NULL)
            // If there is no pair for the first element, it gets deleted
        {
            n = first;
            first = first->next;
            delete n;
        }
    }

    printToFile(fout, oFirst);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("exchange.in");
    ofstream fout("exchange.out");

    node<inputStruct>* first = NULL, * current = NULL;

    saveInput(fin, first, current);

    createOutput(fout, first, current);

    fin.close();
    fout.close();
}