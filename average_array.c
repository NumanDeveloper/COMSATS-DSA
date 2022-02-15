#include <stdio.h>
#include <conio.h>
#define SIZE 10
int main()
{
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    float average;

    for (int i = 0; i < SIZE; i++)
    {
        sum += array[i];
    }
    average = sum / (float)SIZE;
    printf("\nSum: %d", sum);
    printf("\nAverage: %.2", average);
    return 0;
}