/**
copied from programiz.com
Quicksort is a sorting algorithm based on the divide and conquer approach where

 * An array is divided into subarrays by selecting a pivot element (element selected from the array).

 * While dividing the array, the pivot element should be positioned in such a way that   elements less than pivot are kept on the left side and elements greater than pivot are on   the right side of the pivot.
 * The left and right subarrays are also divided using the same approach. This process   continues until each subarray contains a single element.
 * At this point, elements are already sorted. Finally, elements are combined to form a   sorted array.
 */

/**
 * Steps:
 * 1. Select the Pivot Element
 * 2. Rearrange the Array
 * 3. Divide Subarrays
 */

#include <iostream>
using namespace std;

// function to swap elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// function to print the array
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " | ";
    cout << endl;
}

// function to rearrange array (find the partition point)
int partition(int array[], int low, int high)
{
    // select the rightmost element as pivot
    int pivot = array[high];
    // pointer for left side, we'll place smaller elements on left side
    int left = (low-1); // initial value is -1

    // traverse each element of the array and compare them with the pivot
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            // if element smaller than pivot is found, increment left and swap it
            // with the left element pointed by left
            swap(&array[++left], &array[j]);
        }
    }

    // swap pivot with the left element at left pointer
    swap(&array[left+1], &array[high]);
    // return the partition point
    return (left+1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int partition_index = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, partition_index - 1);

        // recursive call on the right of pivot
        quickSort(array, partition_index + 1, high);
    }
}

int main()
{
    int arr[] = {8, 7, 6, 1, 0, 9, 2};
    int n = sizeof(arr) / sizeof(int);

    print_array(arr, n);
    quickSort(arr, 0, n - 1);
    print_array(arr, n);
}