#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define MAX 50
char stack[MAX];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int Priority_Of_Operators(char value)
{
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
    *       2. else keep popping and priting until operator precedence becomes higher
    *       3. then push the operator into stack
    *   At last, pop all chars from stack and print
    */
    char Expression[MAX];
    char *pointer, x;
    printf("Enter the expression :: ");
    scanf("%s",Expression);
    printf("\nPostfix Expression  ");
    pointer = Expression;
    while(*pointer != '\0')
    {
        // if char is alpha-numeric, print it as postfix expression
        if(isalnum(*pointer))
            printf("%c",*pointer);
        // if char is (, push it into stack
        else if(*pointer== '(')
            push(*pointer);
        // if char is ), pop and print until ( encounters
        else if(*pointer== ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            // else char must be operator, so, check its priority
            while(Priority_Of_Operators(stack[top]) >= Priority_Of_Operators(*pointer))
                printf("%c", pop());
            // now, operator precedence is higher, so push it into stack
            push(*pointer);
        }
        pointer++; // increment for next iteration
    }
    // pop and print all the remaining chars of stack
    while(top != -1)
    {
        printf("%c", pop());
    }
}
