#include <stdio.h>
#include <conio.h>
#define SIZE 5
int main()
{
    int i, n, even, odd;
    even = odd = 0;
    while (i < SIZE)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &n);
        (n % 2 == 0) ? even++ : odd++;
        i++;
    }
    printf("\nEven occurs %d times.", even);
    printf("\nOdd occurs %d times.", odd);

    return 0;
}