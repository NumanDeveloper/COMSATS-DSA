/*
Valid Mountain Array

Solution
Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]



Example 1:

Input: arr = [2,1]
Output: false
Example 2:

Input: arr = [3,5,5]
Output: false
Example 3:

Input: arr = [0,3,2,1]
Output: true
*/

#include <stdio.h>

int valid_mountain_array(int *arr, int arrSize);
int main()
{
    int arr[] = {0, 3, 2, 1};
    int arrSize = sizeof(arr) / sizeof(int);

    (valid_mountain_array(arr, arrSize)) ? printf("Mountain Array") : printf("Not a Mountain Array");

    return 0;
}

int valid_mountain_array(int *arr, int arrSize)
{
    int l = 0, r = arrSize - 1;

    // validating array size
    if (arrSize < 3)
        return 0;

    // walk up or traverse in ascending order from start
    while (l + 1 < arrSize && arr[l] < arr[l + 1])
        l++; // increment to move forward

    // now we've reached the peak and peak can't be first or last
    if (l == 0 || l == r)
        return 0;

    // walk down or traverse in descending order from peak
    while (l + 1 < arrSize && arr[l] > arr[l + 1])
        l++; // increment to move forward

    return l == r;
}