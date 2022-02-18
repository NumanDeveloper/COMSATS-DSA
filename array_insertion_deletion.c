#include <stdio.h>
#include <conio.h>
#define CAPACITY 50
// global vars
int element, opt, size = 5;
void menu();
void display(int arr[], int size);
int is_array_full(int arr[], int size);
int index_insertion(int arr[], int size);
int index_deletion(int arr[], int size);
void calculation(int arr[], int opt);

int main()
{
    int arr[CAPACITY] = {1, 3, 5, 7, 9};
    while (1)
    {
        menu();
        printf("\nYour choice: ");
        scanf("%d", &opt);
        if (opt == 4)
        {
            printf("Exiting...");
            break;
        }
        calculation(arr, opt);
    }
    return 0;
}
void menu()
{
    printf("\n1.Display\n2.Insert at specific index\n3.Delete at specific index\n4.Exit");
}

void display(int arr[], int size)
{
    printf("\nElements of the array are:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int is_array_full(int arr[], int size)
{
    if (size >= CAPACITY)
        return -1;
}
int index_insertion(int arr[], int size)
{
    is_array_full(arr, size);
    size += 1;
    int index;
    printf("Enter index: ");
    scanf("%d", &index);
    printf("Enter element: ");
    scanf("%d", &element);
    // go to desired index, will start from right side
    for (int i = size - 1; i >= index; i--)
    {
        // forwarding elements beyond index
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    display(arr, size);
    return 1;
}

int index_deletion(int arr[], int size)
{
    int index1;
    if (index1 >= size)
        return -1;
    size -= 1;
    printf("Enter index: ");
    scanf("%d", &index1);
    for (int i = index1; i < size - 1; i++)
    {
        // backwording elements
        arr[i] = arr[i + 1];
    }
    display(arr, size);
    return 1;
}
void calculation(int arr[], int opt)
{
    switch (opt)
    {
    case 1:
        display(arr, size);
        break;
    case 2:
        index_insertion(arr, size);
        break;
    case 3:
        index_deletion(arr, size);
        break;
    default:
        printf("Invalid choice!");
        break;
    }
}