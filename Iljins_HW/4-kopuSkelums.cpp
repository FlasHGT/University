#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

int main()
{
    int firstArr[50];
    int secondArr[50];
    vector<int> repeatingValues;

    srand(time(NULL));

    for (int i = 0; i < 50; i++) {
        firstArr[i] = rand() % 200 - 100;
        secondArr[i] = rand() % 200 - 100;

        cout << setw(2) << firstArr[i] << " " << secondArr[i] << endl;
    }

    cout << endl;

    for (int x = 0; x < 50; x++) 
    {
        for (int y = 0; y < 50; y++)
        {
            if (firstArr[x] == secondArr[y])
            {
                bool repeats = false;

                for (int z = 0; z < repeatingValues.size(); z++)
                {
                    if (firstArr[x] == repeatingValues[z])
                    {
                        repeats = true;
                        break;
                    }
                }

                if(!repeats)
                {
                    cout << firstArr[x] << endl;
                }

                repeatingValues.push_back(firstArr[x]);
            }
        }
    }
}