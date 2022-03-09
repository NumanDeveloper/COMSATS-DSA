/*
    Max Consecutive Ones
    Given a binary array nums, return the maximum number of consecutive 1's in the array.
    Your input
    [1,1,0,1,1,1]
    Your answer
    3
*/
#include <stdio.h>
#include <conio.h>
#define SIZE 10
int findMaxConsecutiveOnes(int nums[], int size);
int main()
{
    // hard-coded array
    int nums[SIZE] = {1, 1, 0, 1, 1, 1, 0, 0, 0, 1};
    int max = findMaxConsecutiveOnes(nums, SIZE);
    printf("\nMax no. of consecutive ones: %d", max);
    return 0;
}

int findMaxConsecutiveOnes(int nums[], int size)
{
    int count, max;
    count = max = 0;
    // traverse the whole array
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == 0)
            count = 0;
        else if (nums[i] == 1)
        {
            count += 1;
            if (max < count)
                max = count;
        }
    }
    return max;
}