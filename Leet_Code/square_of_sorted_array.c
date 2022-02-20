/*
Squares of a Sorted Array
Solution
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

#include <stdio.h>
#include <math.h>

void selection_sort(int arr[], int size);
int main()
{
    int arr[] = {-4, -1, 0, 3, 10};
    int size = sizeof(arr) / sizeof(int);
    int temp = 0;
    printf("Squared Array:\n");
    for (int i = 0; i < size; i++)
    {
        arr[i] = pow(arr[i], 2);
        printf("%d\t", arr[i]);
    }
    selection_sort(arr, size);
    return 0;
}
void selection_sort(int arr[], int size)
{
    int min, temp, index_of_min;
    // this loop will select elements one by one
    for (int i = 0; i < (size - 1); i++)
    {
        index_of_min = i;
        // this loop will start comparing from i+1, element next to i
        for (int j = i + 1; j < size; j++)
        {
            // sorting in ascending order
            if (arr[index_of_min] > arr[j])
            {
                // swapping
                temp = arr[j];
                arr[j] = arr[index_of_min];
                arr[index_of_min] = temp;
            }
        }
    }
    printf("\nRunning Selection Sort...\n");
    for (int i = 0; i < size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}