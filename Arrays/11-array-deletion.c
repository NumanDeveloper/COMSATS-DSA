#include <stdio.h>

/* Deletion in arrays */

void display(int arr[], int n)
{
    // traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indDeletion(int arr[], int size, int index)
{
    int capacity;
    // Deletion
    if (size >= capacity)
    {
        return -1; // no Deletion
    }
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1]; // moving element one index back
    }
}
int main()
{
    system("cls");

    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, capacity = 100, index;
    index = 4; //index at which Deletion is required

    printf("Array before deletion\n");
    display(arr, size);

    indDeletion(arr, size, index); //calling Deletion function
    size -= 1;

    printf("Array after deletion\n");
    display(arr, size); //printing first six elements of inserted array

    return 0;
}