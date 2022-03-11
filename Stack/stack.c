// This is simple implementation of the stack and not dynamic
#include <stdio.h>
#define SIZE 50
int stack[SIZE];
int x, top = -1; // stack is empty now
void push(int x);
void pop();
void Top();
void display();
int main()
{
    push(50);
    push(43);
    push(23);
    pop();
    Top();
    return 0;
}
void display()
{
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}
void push(int x)
{
    // check if the stack is full
    if (top >= SIZE - 1)
        printf("Error: Stack Overflow");
    else
    {
        stack[++top] = x;
        display();
    }
}

void pop()
{
    // check if the stack is empty
    if (top == -1)
        printf("Error: Stack Underflow");
    else
    {
        printf("\nElement %d popped from the stack.\n", stack[top]);
        --top;
        display();
    }
}

void Top()
{
    printf("The top element is %d.\n", stack[top]);
    display();
}