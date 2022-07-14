#include <stdio.h>

/* lINEAR BINARY SEARCH IN ARRAYS */

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i; //if found, return index
        }
    }
    return -1; //if not found
}

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    // keep searching until low <= high
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == element)
        {
            return mid; //return mid index
        }
        if (arr[mid] < element)
        {
            low = mid + 1; //setting low index one furthur from mid
        }
        else
        {
            high = mid - 1; //setting high index one behind from mid
        }
    }
    // end searching
    return -1; // bhia element not found
}

int main()
{
    system("cls");

    // unsorted array for linear search
    // int arr[] = {1, 4, 45, 8, 5, 97, 15, 144, 17, 24, 85};
    // int size = sizeof(arr) / sizeof(int); //will return size of array

    // sorted array for linear search
    int arr[] = {1, 4, 45, 78, 85, 97, 115, 144, 177, 245, 285};
    int size = sizeof(arr) / sizeof(int); //will return size of array
    int element = 78;
    int searchIndex = binarySearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);

    return 0;
}