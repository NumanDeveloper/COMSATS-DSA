/*
Duplicate Zeros

Solution
Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

Example 1:
Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

Example 2:
Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]
*/

#include <stdio.h>

void display(int *arr, int size);
void duplicateZeros(int *arr, int arrSize);
int main()
{
    int arr[] = {1, 0, 2, 3, 0, 4, 5, 0};
    int arrSize = sizeof(arr) / sizeof(int);
    duplicateZeros(arr, arrSize);
    display(arr, arrSize);
    return 0;
}

void display(int *arr, int size)
{
    printf("\nElements of the array are:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void duplicateZeros(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = arrSize - 1; j > i; j--)
                arr[j] = arr[j - 1];
            arr[i] = 0;
            // increment i's value to reach next element
            i++;
        }
    }
}