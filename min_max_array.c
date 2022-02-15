#include <stdio.h>
#include <conio.h>

int main()
{
    // const int SIZE = 10;
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int min, max;
    min = max = arr[0];

    // Ways of finding size of an array
    // int size = sizeof arr / sizeof arr[0];
    // As the pointer to the string points to the first item in the string.Following is also valid
    // int size = sizeof arr / sizeof *arr;
    for (int i = 0; i < 10; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    printf("\nMininum: %d", min);
    printf("\nMaximun: %d", max);

    return 0;
}