#include <stdio.h>
#include <conio.h>
#define CAPACITY 50
// global var size
int index, element, opt, size = 0;
void menu();
void display(int arr[], int size);
int is_array_full(int arr[], int size);
int index_insertion(int arr[], int size);
// int position_insertion(int arr[], int size, int position, int element);
int start_insertion(int arr[], int size);
int end_insertion(int arr[], int size);
void calculation(int arr[], int opt);

int main()
{
    while (1)
    {
        menu();
        int arr[CAPACITY] = {3, 8, 4, 5};
        size = 4;
        // index_insertion(arr, size, 2, 20);
        // position_insertion(arr, size, 1, 45);
        // start_insertion(arr, size, 30);
        // end_insertion(arr, size, 15);
        printf("\nYour choice: ");
        scanf("%d", &opt);
        calculation(arr, opt);
    }
    return 0;
}
void menu()
{
    printf("\n1.Display\n2.Insert at start\n3.Insert at end\n4.Insert at specific index\n5.Exit");
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
    printf("Enter index: ");
    scanf("%d", &index);
    printf("Enter element: ");
    scanf("%d", &element);
    is_array_full(arr, size);
    // go to desired index
    for (int i = size - 1; i >= index; i--)
    {
        // forwarding elements beyond index
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    size++;
    display(arr, size);
    return 1;
}

int start_insertion(int arr[], int size)
{
    is_array_full(arr, size);
    printf("Enter element: ");
    scanf("%d", &element);
    for (int i = 0; i < size; i++)
    {
        // forwarding elements beyond index
        arr[i + 1] = arr[i];
    }
    arr[0] = element;
    size++;
    display(arr, size);
    return 1;
}

int end_insertion(int arr[], int size)
{
    printf("Enter element: ");
    scanf("%d", &element);
    is_array_full(arr, size);
    arr[size] = element;
    size += 1;
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
        start_insertion(arr, size);
        break;
    case 3:
        end_insertion(arr, size);
        break;
    case 4:
        index_insertion(arr, size);
        break;
    case 5:
        printf("Exiting...");
        break;
    default:
        printf("Invalid choice!");
        break;
    }
}