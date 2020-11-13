#include <iostream>

using namespace std;

int main()
{
    const int arrSize = 3;
    int arr[arrSize][arrSize]; // 100 - empty, 2 - first player, 3 - second player
    int r, c;
    int currentTurn = 1;

    for (int x = 0; x < arrSize; x++)
    {
        for (int y = 0; y < arrSize; y++)
        {
            arr[x][y] = 100;
        }
    }

    cout << "First players turn: " << endl;

    cin >> r >> c;
    cout << endl;

    while (currentTurn != arrSize * arrSize) {
        
        if (arr[r][c] == 100)
        {
            if (currentTurn % 2 == 0)
            {
                arr[r][c] = 3;
            }
            else
            {
                arr[r][c] = 2;
            }

            if (currentTurn >= 5)
            {
                int diagonalSumOne = 0;
                int diagonalSumTwo = 0;

                for (int x = 0; x < arrSize; x++)
                {
                    int rowSum = 0;
                    int colSum = 0;

                    for (int y = 0; y < arrSize; y++)
                    {
                        rowSum += arr[x][y];
                        colSum += arr[y][x];

                        if (x == y)
                        {
                            diagonalSumOne += arr[x][y];
                        }

                        if (y == arrSize - 1 - x)
                        {
                            diagonalSumTwo += arr[x][y];
                        }
                    }

                    if (rowSum == 9 || colSum == 9)
                    {
                        cout << "Game over! Second player won" << endl;
                        return 0;
                    }
                    else if (rowSum == 6 || colSum == 6)
                    {
                        cout << "Game over! First player won" << endl;
                        return 0;
                    }
                }

                if (diagonalSumOne == 9 || diagonalSumTwo == 9)
                {
                    cout << "Game over! Second player won" << endl;
                    return 0;
                }
                else if (diagonalSumOne == 6 || diagonalSumTwo == 6)
                {
                    cout << "Game over! First player won" << endl;
                    return 0;
                }
            }

            currentTurn++;
        }
        else
        {
            cout << "Field already used or out of board values" << endl;
        }

        if (currentTurn % 2 == 0) {
            cout << "Second players turn: " << endl;

            cin >> r >> c;
        }
        else {
            cout << "First players turn: " << endl;

            cin >> r >> c;
        }

        cout << endl;
    }

    cout << "Nobody won, because the board is full" << endl;
}