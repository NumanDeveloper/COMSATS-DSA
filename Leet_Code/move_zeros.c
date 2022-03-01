/*
Move Zeroes

Solution
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.



Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
*/

#include <stdio.h>

void move_zeros(int *nums, int numsSize);
int main()
{
    int nums[] = {0};
    int numsSize = sizeof(nums) / sizeof(int);
    move_zeros(nums, numsSize);

    printf("Modified Array:\n");
    for (int i = 0; i < numsSize; i++)
        printf("%d ", nums[i]);
    return 0;
}

void move_zeros(int *nums, int numsSize)
{
    // check edge case
    if (nums == NULL)
        return;
        
    int write_pointer = 0;
    for (int read_pointer = 0; read_pointer < numsSize; read_pointer++)
        if (nums[read_pointer] != 0)
        {
            nums[write_pointer] = nums[read_pointer];
            write_pointer += 1;
        }
    // calculating total zeros to be filled at the end of the array
    int total_zeros = numsSize - write_pointer;
    for (int i = 0; i < total_zeros; i++)
    {
        nums[write_pointer] = 0;
        write_pointer += 1;
    }
}