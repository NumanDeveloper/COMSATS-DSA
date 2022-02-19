#include <stdio.h>
#include <conio.h>
#define SIZE 10

void linear_search(int arr[], int size);
int main()
{
    int arr[SIZE] = {23, 54, 432, 55, 2, 634, 3, 8, 56, 4};
    linear_search(arr, SIZE);
    return 0;
}

void linear_search(int arr[], int size)
{
    int n, index, iterations = 0;
    printf("\nElements of the array are:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\nEnter number to search: ");
    scanf("%d", &n);
    for (int i = 0; i < size; i++)
    {
        iterations += 1;
        if (n == arr[i])
        {
            index = i;
            break;
        }
    }
    printf("Element found at index %d.", index);
    printf("\nTotal numbers searched: %d", iterations);
    return;
}