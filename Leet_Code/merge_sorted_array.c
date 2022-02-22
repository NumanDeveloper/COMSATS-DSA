/*
Merge Sorted Array

Solution
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.



Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
*/

#include <stdio.h>

void selection_sort(int *arr, int size);
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n);
int main()
{
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};
    int nums1Size = sizeof(nums1) / sizeof(int);
    int nums2Size = sizeof(nums2) / sizeof(int);
    int m = 3; // always remember to update m value when size of nums1 changes
    int n = nums2Size;
    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    return 0;
}
void selection_sort(int *arr, int size)
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
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    // first place nums2 elements at end of nums1 element, then sort the whole array
    int j = 0;
    for (int i = m; i < nums1Size; i++)
    {
        nums1[i] = nums2[j];
        j += 1;
    }
    selection_sort(nums1, nums1Size);
}
