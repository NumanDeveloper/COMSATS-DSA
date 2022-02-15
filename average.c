#include <stdio.h>
#include <conio.h>
#define SIZE 5
int main()
{
    int i, n, sum;
    i = sum = 0;
    float average;
    printf("Enter numbers:\n");
    while (i < SIZE)
    {
        scanf("%d", &n);
        sum += n;
        i++;
    }
    average = sum / (float)SIZE;
    printf("\nSum: %d", sum);
    printf("\nAverage: %.2f", average);
    return 0;
}