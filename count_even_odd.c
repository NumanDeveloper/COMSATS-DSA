#include <stdio.h>
#include <conio.h>
#define SIZE 10
int main()
{
    int i, n, even, odd;
    even = odd = 0;
    printf("Enter numbers: \n");
    while (i < SIZE)
    {
        scanf("%d", &n);
        (n % 2 == 0) ? even++ : odd++;
        i++;
    }
    printf("\nEven occurs %d times.", even);
    printf("\nOdd occurs %d times.", odd);

    return 0;
}