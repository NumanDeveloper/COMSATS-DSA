#include <stdio.h>
#include <stdlib.h>
#define max 10

void header();
void push();
int pop();
void display();
void Exit();
int top = -1, i;
int stack[max];
int main()
{
    int c;
    header();
    for (;;) // infinite loop
    {
        printf("\n\t Menu");
        printf("\n\t 1. Push ");
        printf("\n\t 2. Pop ");
        printf("\n\t 3. Display ");
        printf("\n\t 4. Exit");
        printf("\n Enter the Choice: ");
        scanf("%d", &c);
        switch (c)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                printf("\n %d is at top in stack ", stack[top]);
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                Exit();
                break;
            }
        }
    }
}
void push()
{
    int num;
    if (top == max - 1)
    {
        printf("\n Stack is Full!!!");
    }
    else
    {
        top++;
        printf("\n Enter the number : ");
        scanf("%d", &num);
        stack[top] = num;
    }
}
int pop()
{
    int temp;
    if (top == -1)
    {
        printf("\n Stack is Empty!!");
    }
    else
    {
        temp = stack[top];
        top--;
    }
    return temp;
}
void display()
{
    for (i = 0; i <= top; i++)
    {
        printf("\n Stack[%d] = %d ", i, stack[i]);
    }
}
void Exit()
{ // Start of Method
    exit(0);
}
void header()
{
    printf("\tMuhammad Qasim. SP16-BCS-102\n\n");
}
