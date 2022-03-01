/*
Replace Elements with Greatest Element on Right Side
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.



Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
Explanation:
- index 0 --> the greatest element to the right of index 0 is index 1 (18).
- index 1 --> the greatest element to the right of index 1 is index 4 (6).
- index 2 --> the greatest element to the right of index 2 is index 4 (6).
- index 3 --> the greatest element to the right of index 3 is index 4 (6).
- index 4 --> the greatest element to the right of index 4 is index 5 (1).
- index 5 --> there are no elements to the right of index 5, so we put -1.
Example 2:

Input: arr = [400]
Output: [-1]
Explanation: There are no elements to the right of index 0.
*/

#include <stdio.h>

void replace_elements(int *arr, int arrSize);
int main()
{
    int arr[] = {17, 18, 5, 4, 6, 1};
    int arrSize = sizeof(arr) / sizeof(int);
    replace_elements(arr, arrSize);

    printf("\nResultant array is:\n");
    for (int i = 0; i < arrSize; i++)
        printf("%d ", arr[i]);

    return 0;
}

void replace_elements(int *arr, int arrSize)
{
    /*
    A tricky method is to replace all elements using one traversal of the array. The idea is to start from the rightmost element, move to the left side one by one, and keep track of the maximum element. Replace every element with the maximum element.
    */
    int temp, max_from_right;
    max_from_right = arr[arrSize - 1]; // rightmost is our current max
    arr[arrSize - 1] = -1;             // this is always -1 since no element ahead is present
    for (int i = arrSize - 2; i >= 0; --i)
    {
        temp = arr[i]; // this will be needed later to update value
        arr[i] = max_from_right;
        // swap any value greater than max from right
        if (temp > max_from_right)
            max_from_right = temp;
        printf("%d ", max_from_right);
    }
}


/*
Taken from leetcode solutions
// O(n) solution. Start from the end
int* replaceElements(int* arr, int arrSize, int* returnSize){
    int currentMax = -1;
    
    for(int i = arrSize-1; i >= 0; i--) {
        int tmp = arr[i];
        arr[i] = currentMax;
        if(tmp > currentMax) {
            currentMax = tmp;
        }
    }
    *returnSize = arrSize;
    return arr;
}
*/