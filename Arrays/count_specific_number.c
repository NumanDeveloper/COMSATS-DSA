#include <stdio.h>
#include <conio.h>
#define SIZE 5
int main()
{
    int array[SIZE], search, count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter number %d: ", i+1);
        scanf("%d", &array[i]);
    }
    printf("Which number to count: ");
    scanf("%d", &search);
    for (int i = 0; i < SIZE; i++)
        if (search == array[i])
            count++;
    printf("%d occurs %d times.", search, count);

    return 0;
}