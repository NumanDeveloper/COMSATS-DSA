#include <stdio.h>
#include <conio.h>
#define SIZE 10
int main()
{
    int array[SIZE], search, count = 0;
    printf("Enter numbers:\n");
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Which number to count: ");
    scanf("%d", &search);
    for (int i = 0; i < SIZE; i++)
    {
        if (search == array[i])
        {
            count++;
        }
    }
    printf("%d occurs %d times.", search, count);

    return 0;
}