/*
Sort Array By Parity

Solution
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.



Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Example 2:

Input: nums = [0]
Output: [0]
*/

#include <stdio.h>

void sort_array_by_parity(int *nums, int numsSize);
int main()
{
    int nums[] = {3, 1, 2, 4};
    int numsSize = sizeof(nums) / sizeof(int);
    sort_array_by_parity(nums, numsSize);

    printf("Modified Array:\n");
    for (int i = 0; i < numsSize; i++)
        printf("%d ", nums[i]);

    return 0;
}

void sort_array_by_parity(int *nums, int numsSize)
{
    // the idea is to store the result of old array into new array and then copy new array into old array 
    int arr[numsSize]; // new array
    int j = 0; // new array pointer

    // finding and storing evens in new array 
    for (int i = 0; i < numsSize; i++)
        if (nums[i] % 2 == 0)
        {
            arr[j] = nums[i];
            j += 1;
        }

    // finding and storing odds in new array
    for (int i = 0; i < numsSize; i++)
        if (nums[i] % 2 != 0)
        {
            arr[j] = nums[i];
            j += 1;
        }

    // copying new array into old array 
    for (int i = 0; i < numsSize; i++)
        nums[i] = arr[i];
}