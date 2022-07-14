#include <stdio.h>

/* Deletion in arrays */

void display(int arr[], int n)
{
    // traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d | ", arr[i]);
    }
    printf("\n");
}

int indexDeletion(int arr[], int size, int index)
{
    // Deletion
    if (index >= size)
    {
        return -1; // no Deletion
    }

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1]; // moving element one index back till desired index
    }
}

int main()
{
    system("cls");

    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5;

    printf("Array before deletion\n");
    display(arr, size);

    indexDeletion(arr, size, 1); //calling Deletion function
    size--;

    printf("Array after deletion\nDeleting...\n");
    display(arr, size); //printing first six elements of inserted array

    return 0;
}