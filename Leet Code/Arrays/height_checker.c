/*
Height Checker
A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.

You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).

Return the number of indices where heights[i] != expected[i].



Example 1:

Input: heights = [1,1,4,2,1,3]
Output: 3
Explanation:
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
Indices 2, 4, and 5 do not match.
Example 2:

Input: heights = [5,1,2,3,4]
Output: 5
Explanation:
heights:  [5,1,2,3,4]
expected: [1,2,3,4,5]
All indices do not match.
Example 3:

Input: heights = [1,2,3,4,5]
Output: 0
Explanation:
heights:  [1,2,3,4,5]
expected: [1,2,3,4,5]
All indices match.
*/

#include <stdio.h>

void selection_sort(int arr[], int size);
int height_checker(int *heights, int heightsSize);
int main()
{
    int heights[] = {1,2,3,4,5};
    int heightsSize = sizeof(heights) / sizeof(int);

    printf("%d students are not in order.", height_checker(heights, heightsSize));

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
            if (arr[j] < arr[index_of_min])
            {
                // swapping
                temp = arr[j];
                arr[j] = arr[index_of_min];
                arr[index_of_min] = temp;
            }
        }
    }
}
int height_checker(int *heights, int heightsSize)
{
    // the idea is to create a new sorted array and compare it with old one
    // return the # of indices that don't match
    int count = 0;
    int arr[heightsSize]; // new array
    // copy old array into new array
    for (int i = 0; i < heightsSize; i++)
        arr[i] = heights[i];
    // sort the new array
    selection_sort(arr, heightsSize);

    for (int i = 0; i < heightsSize; i++)
        // count indices that don't match
        if (arr[i] != heights[i])
            count++;

    return count;
}