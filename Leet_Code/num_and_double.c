/*
Check If N and Its Double Exist
Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).

More formally check if there exists two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]


Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
Example 2:

Input: arr = [7,1,14,11]
Output: true
Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.
Example 3:

Input: arr = [3,1,7,11]
Output: false
Explanation: In this case does not exist N and M, such that N = 2 * M.
*/

#include <stdio.h>

int checkIfExist(int *arr, int arrSize);
int main()
{
    int arr[] = {0, 0};
    int arrSize = sizeof(arr) / sizeof(int);
    int present = checkIfExist(arr, arrSize);
    present == 1 ? printf("Double is present") : printf("Double is not present");
    return 0;
}

int checkIfExist(int *arr, int arrSize)
{
    int present = 0;
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
        {
            if (i == j)
                continue;
            else if (arr[i] == 2 * arr[j])
            {
                present = 1;
            }
        }
    }
    return present;
}

/*
taken from LeetCode solutions
int checkIfExist(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i]) {
                return true;
            }
        }
    }
    return false;
}
*/