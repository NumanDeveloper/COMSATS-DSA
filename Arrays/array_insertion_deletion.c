#include <stdio.h>
#include <conio.h>
#define CAPACITY 50

// functions prototypes
void display(int* arr, int size);
int is_array_full(int* arr, int size);
int index_insertion(int* arr, int size);
int index_deletion(int* arr, int size);

int main()
{
    int opt, size = 5;
    int arr[5] = {1, 3, 5, 7, 9};
    display(arr, size);
    // index_insertion(arr, size);
    index_deletion(arr, size);
    
    return 0;
}

void display(int* arr, int size)
{
    printf("\nElements of the array are:\n");
    for (int i = 0; i < size; i++)
        printf("%d | ", arr[i]);
    printf("\n");
}

int is_array_full(int* arr, int size)
{
    if (size >= CAPACITY)
        return -1;
}
int index_insertion(int* arr, int size)
{
    is_array_full(arr, size);
    size += 1; // increment size to make room for insertion
    int index, element;
    printf("Enter index: ");
    scanf("%d", &index);
    printf("Enter element: ");
    scanf("%d", &element);
    // go to desired index, will start from right side
    for (int i = size - 1; i >= index; i--)
    {
        // forwarding elements to the right of desired index
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    display(arr, size);

    return 1;
}

int index_deletion(int* arr, int size)
{
    int index;
    if (index >= size)
        return -1;
    size -= 1;
    printf("Enter index: ");
    scanf("%d", &index);
    for (int i = index; i <= size - 1; i++)
        // backwording elements
        arr[i] = arr[i + 1];
    display(arr, size);
    
    return 1;
}