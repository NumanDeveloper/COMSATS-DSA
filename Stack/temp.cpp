#include <stdio.h>

#define SIZE 50
int stack[SIZE];
int x, top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    int x = stack[top];
    top--;
    return x;
}

int main()
{
    push(50);
    pop();

    return 0;
}