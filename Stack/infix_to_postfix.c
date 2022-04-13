#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return (top == -1) ? -1 : stack[top--];
}

int priority(char value)
{
    // This condition is vvip. I've wasted much time by not inserting it
    if(value == '(')
        return 0;
    if(value == '+' || value == '-')
        return 1;
    if(value == '*' || value == '/')
        return 2;
}

int main()
{
    /*
    Logic:
    *   Read infix expression
    *   Store that in a char pointer
    *   Traverse infix expression
    *   if alpha-numeric encounter, print it as postfix
    *   if ( encounter, push it into stack
    *   if ) encounter, pop and print char from stack until ( encounters
    *   if operator encounters, check its priority
    *       1. if operator precedence is higher than stack top, push it into stack
    *       2. else keep popping and priting until operator precedence becomes higher than stack top
    *       3. then push the operator into stack
    *   At last, pop all chars from stack and print
    */
    char infix[SIZE];
    char *p, x;
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    printf("\nPostfix Expression: ");
    p = infix;
    while(*p != '\0')
    {
        // if char is alpha-numeric, print it as postfix expression
        if(isalnum(*p))
            printf("%c",*p);
        // if char is (, push it into stack
        else if(*p == '(')
            push(*p);
        // if char is ), pop and print until ( encounters
        else if(*p == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            // else char must be operator, so, check its priority
            while(priority(stack[top]) >= priority(*p))
                printf("%c", pop());
            // now, operator precedence is higher, so push it into stack
            push(*p);
        }
        p++; // increment for next iteration
    }
    // pop and print all the remaining chars of stack
    while(top != -1)
        printf("%c", pop());

    return 0;
}
