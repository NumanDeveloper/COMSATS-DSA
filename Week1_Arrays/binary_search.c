#include <stdio.h>

void binary_search(int arr[], int size);
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    binary_search(arr, size);

    return 0;
}

void binary_search(int arr[], int size)
{
    printf("Elements of the array are:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    int index, number, low, mid, high;
    low = 0;
    high = size - 1;
    printf("\nEnter number: ");
    scanf("%d", &number);
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == number)
        {
            index = mid;
            break;
        }
        else if (arr[mid] > number)
            high = mid - 1;
        else
            low = mid + 1;
    }
    printf("\nElement %d found at index %d.", number, index);
}