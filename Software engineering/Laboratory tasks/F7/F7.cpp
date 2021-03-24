// Georgs Toliašvili, gt20010
// F7. Dots teksta fails, kurâ atrodas sintaktiski pareizs C++ programmas teksts. 
// Saskaitît, cik pieðíirðanas operatoru (=, +=, *=, -=, /=, %=) satur dotâ programma.
// Drîkst uzskatît, ka programmas tekstâ nav komentâru un ka attiecîgie simboli
// neparâdîsies teksta literâïos. Brîdinâjums. Nedrîkst pieskaitît salîdzinâðanas operatorus (==, != utt.).
// 20.02.2021

//  Input | Desired Output | C++ Output
//  >=    | Not Counted    | +0
//  <=    | Not Counted    | +0
//  !=    | Not Counted    | +0
//  ==    | Not Counted    | +0
//  =     | Counted        | +1
//  5=    | Counted        | +1
//  +=    | Counted        | +1

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    const int arrSize = 3;
    string lineOutput = "";
    char thingsToFind[arrSize] = { '>', '<', '!' }; // Bad symbols, which are not counted
    int count = 0;

    fstream f("lab19in.txt", ios::in);

    getline(f, lineOutput);

    while (f) {
        for (int x = 0; x < lineOutput.length(); x++)
        {
            if (lineOutput[x] == '=') // In order to find symbol combinations, we have to look for the = sign, because
            // it is in every combination
            {
                bool foundBadThing = false;

                if (lineOutput[x + 1] == '=' || lineOutput[x - 1] == '=') // We check if this == symbols structure appears
                {
                    continue;
                }

                for (int y = 0; y < arrSize; y++)
                {
                    if (lineOutput[x - 1] == thingsToFind[y]) // We check if there are any of the bad symbols in front of
                    // the equal sign
                    {
                        foundBadThing = true;
                        break;
                    }
                }

                if (!foundBadThing) // If there aren't any of the bad symbols in front of the = sign, then we don't
                // actually care what is in front of it, because it can be anything and in this case anything
                // is legal C++ syntax, because the task allows us to assume, that the C++ code is correctly written
                {
                    count++;
                }
            }
        }

        getline(f, lineOutput);
    }

    f.close();
    cout << count << endl;
}