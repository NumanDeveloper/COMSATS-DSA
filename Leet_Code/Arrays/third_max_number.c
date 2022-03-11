/*
Third Maximum Number

Solution
Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.



Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
*/

#include <stdio.h>

int third_max(int *nums, int numsSize);
int main()
{
    int nums[] = {2, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(int);

    printf("%d is the third max!", third_max(nums, numsSize));
    return 0;
}
void selection_sort(int arr[], int size)
{
    int temp, index_of_max;
    // this loop will select elements one by one
    for (int i = 0; i < (size - 1); i++)
    {
        index_of_max = i;
        // this loop will start comparing from i+1, element next to i
        for (int j = i + 1; j < size; j++)
        {
            // sorting in descending order
            if (arr[index_of_max] < arr[j])
            {
                // swapping
                temp = arr[j];
                arr[j] = arr[index_of_max];
                arr[index_of_max] = temp;
            }
        }
    }
}
int third_max(int *nums, int numsSize)
{
    // the logic is to sort the array in descending order and return the third element
    if (numsSize < 3)
        // if array size is less than 3, return the max
        return (nums[0] > nums[1] ? nums[0] : nums[1]);
    selection_sort(nums, numsSize);
    // handling duplicates
    if (nums[2] == nums[1])
        // if duplicats exist, return next max 
        return nums[3];
    return nums[2];
}