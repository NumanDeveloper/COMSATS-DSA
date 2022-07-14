#include <stdio.h>
#include <stdlib.h>
#define max 10
struct stack
{
    char array[max];
    int top;
} abc;
void push(char value);
char pop();
void display();
int main()
{
    abc.top = -1;
    int num;
    char a, b;
    for (;;)
    {
        printf("\n1. ______ Push ________\n2. ______ POP _______\n3. ______ Display _______\n4. ______ Exit _______\n");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
        {
            printf("Enter the value:\t");
            fflush(stdin);
            scanf("%c", &a);
            push(a);
            break;
        }
        case 2:
        {
            b = pop();
            printf("Value poped is = %c \n", b);
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        default:
        {
            printf("\nplease choose correct case\n");
            exit(0);
        }
        }
    }
}
void push(char value)
{
    if (abc.top == max - 1)
    {
        printf("____________Stack Overflow___________________\n");
    }
    else
    {
        abc.top++;
        abc.array[abc.top] = value;
    }
}
char pop()
{
    char value;
    if (abc.top == -1)
    {
        printf("____________Stack Underflow___________________\n");
        // return;
    }
    else
    {
        value = abc.array[abc.top];
        abc.top--;
    }
    return value;
}
void display()
{
    int i;
    printf("\nArray     ");

    for (i = 0; i <= abc.top; i++)
    {
        if (abc.top == max)
        {
            printf("Overflow");
        }
        else
        {
            printf("%c\t", abc.array[i]);
        }
    }
    printf("\nTop is = %d ", abc.top);
}
