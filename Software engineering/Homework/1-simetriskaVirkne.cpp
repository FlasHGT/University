#include <iostream>

using namespace std;

int main() 
{
    char arr[100];

    cin.getline(arr, sizeof(arr));

    for (int x = 0; x < 100; x++) 
    {
        if (arr[x] == '.')
        {
            for (int y = 0; y < x; y++)
            {
                if (arr[y] != arr[x - 1 - y])
                {
                    cout << "Not symmetrical" << endl;
                    return 0;
                }
            }

            cout << "Symmetrical" << endl;
        }
    }
}