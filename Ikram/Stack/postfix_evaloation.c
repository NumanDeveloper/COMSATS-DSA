#include <stdio.h>
#define max 15

void push();
int pop();
void sum();
int top = -1;
char stack[max];

int main()
{
    int i;
    push(); // read a postfix expression
    for (i = 0; i < max; i++)
    {
        printf("%c", stack[i]);
    }
    sum();
}
void push()
{
    char num;
    if (top == max - 1)
    {
        printf("\n Stack is full");
    }
    else
    {
        top++;
        printf("\n Enter a postfix expression : ");
        scanf("%s", &stack);
    }
}
int pop()
{
    char a, b, o;
    int op;
    int c[2];
    if (top == -1)
    {
        printf("\n Stack is empty");
    }
    else
    {
        if (stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/')
        {
            o = stack[top];
            op = atoi(o);
            top--;
            return (op);
        }
        else
        {
            a = stack[top];
            b = stack[top - 1];
            c[0] = atoi(a);
            c[1] = atoi(b);
            top--;
        }
    }

    return (c);
}
void sum()
{
    int sum = 0, i;
    for (i = 0; i < max; i++)
    {
        sum += pop();
    }
    printf("\n %d ", sum);
}
