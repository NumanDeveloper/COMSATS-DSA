#include <stdio.h>
#include <conio.h>
#define SIZE 10

int main()
{
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    float average = 0.0;

    for (int i = 0; i < SIZE; i++)
        sum += array[i];

    average = sum / (float)SIZE;
    printf("The array is:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", array[i]);
    printf("\nSum: %d", sum);
    printf("\nAverage: %.2f", average);
    return 0;
}