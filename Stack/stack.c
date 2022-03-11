// This is simple implementation of the stack and not dynamic
#include <stdio.h>
#define SIZE 50
int stack[SIZE];
int x, top = -1; // stack is empty now

void push(int x);
void pop();
void stack_top();
void stack_bottom();
void display();

int main()
{
    system("cls");
    printf("Stack created successfully.\n");
    push(50);
    push(43);
    push(23);
    pop();
    stack_top();
    stack_bottom();
    return 0;
}

void display()
{
    printf("Stack: ");
    for (int i = 0; i < top + 1; i++)
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
        // first increment top, then push
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
        --top; // decrement top
        display();
    }
}

void stack_top()
{
    printf("The top element is %d.\n", stack[top]);
    display();
}

void stack_bottom()
{
    printf("The bottom element is %d.\n", stack[0]);
    display();
}