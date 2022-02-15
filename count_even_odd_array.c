#include <stdio.h>
#include <conio.h>
#define SIZE 10
int main()
{
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int even, odd;
    even = odd = 0;

    for (int i = 0; i < SIZE; i++)
    {
        (array[i] % 2 == 0) ? even++ : odd++;
    }
    printf("\nEven: %d", even);
    printf("\nOdd: %d", odd);
    
    return 0;
}