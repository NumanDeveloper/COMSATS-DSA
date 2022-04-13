#include <iostream>
using namespace std;

int main()
{
    int A[3][3] =
        {
            {1, 2, 3},
            {3, 5, 7},
            {4, 6, 8}
        };
    int sum = 0;
    cout << "Array elements are:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << A[i][j] << " | ";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += A[i][j];
        }
        cout << "The sum of row " << i + 1 <<" is "<< sum << endl;
        sum = 0;
    }

    return 0;
}