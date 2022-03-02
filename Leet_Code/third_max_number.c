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
#include <limits.h>

int third_max(int *nums, int numsSize);
int main()
{
    int nums[] = {2, 2, 3, -1};
    int numsSize = sizeof(nums) / sizeof(int);

    printf("%d is the third max!", third_max(nums, numsSize));
    return 0;
}

int third_max(int *nums, int numsSize)
{
    // the logic is to declare three variables for three maximums and return the third max
    int first, second, third;
    // initiallizing to INT_MIN to avoid out of bound error
    first = second = third = INT_MIN;
    if (numsSize == 2)
        // if array size is 2, simply return max
        return (nums[0] > nums[1]) ? nums[0] : nums[1];

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == first || nums[i] == second || nums[i] == third)
            // wherever duplicate occurs, skip it and continue to next iteration
            continue;

        if (nums[i] > first)
        {
            // if first is updated, all need to be updated
            // start updating from bottom so that we don't lose reference
            third = second;
            second = first;
            first = nums[i];
        }
        else if (nums[i] > second)
        {
            // if second is updated, third needs to be updated
            // start updating from bottom so that we don't lose reference
            third = second;
            second = nums[i];
        }
        else if (nums[i] > third)
            third = nums[i];
    }
    if (third == INT_MIN)
        // acc. to question, if third max is not found or doesn't exist, return first max
        return first;

    // if we get successfully till the end, return the third max
    return third;
}