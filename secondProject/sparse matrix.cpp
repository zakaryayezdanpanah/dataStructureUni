#include <iostream>

using namespace std;

int main()
{
    // set the size of n for entry matrix
    int n;
    cin >> n;

    int entryArray[n][n];
    int validCounter = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> entryArray[i][j];

            if (entryArray[i][j] != 0)
            {
                validCounter++;
            }
        }
    }

    int sparseMatrix[validCounter + 1][3];

    sparseMatrix[0][0] = n;
    sparseMatrix[0][1] = n;
    sparseMatrix[0][2] = validCounter;

    int sparseCounter = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (entryArray[i][j] != 0)
            {
                sparseMatrix[sparseCounter][0] = i;
                sparseMatrix[sparseCounter][1] = j;
                sparseMatrix[sparseCounter][2] = entryArray[i][j];
                sparseCounter++;
            }
        }
    }

    for (int i = 0; i <= validCounter; i++)
    {
        cout << " " << sparseMatrix[i][0] << " " << sparseMatrix[i][1] << " " << sparseMatrix[i][2] << endl;
    }
    return 0;
}