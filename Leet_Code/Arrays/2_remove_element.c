/*
Remove Element

Solution
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.



Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

#include <stdio.h>

int remove_element(int *nums, int numsSize, int val);
int main()
{
    int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int numsSize = sizeof(nums) / sizeof(int);
    int count = remove_element(nums, numsSize, 2);

    printf("Modified Array:\n");
    for (int i = 0; i < count; i++)
        printf("%d ", nums[i]);
    return 0;
}

int remove_element(int *nums, int numsSize, int val)
{
    // the idea is to create a new array and copy all elements from old array into it except that needs to be deleted. count the number of elements in new array and then copy new arry into old array
    // check for edge case
    if (nums == NULL || numsSize == 0)
        return numsSize;

    int j = 0;         // pointer to new array
    int arr[numsSize]; // new array
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == val)
            // if matches, skip and don't copy
            continue;
        // if don't match, copy to new array
        arr[j] = nums[i];
        j++; // increment for next element position
    }

    // copying new array to old
    for (int i = 0; i < j; i++)
        nums[i] = arr[i];

    return j; // return size of resultant array
}