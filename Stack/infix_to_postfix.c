#include <stdio.h>
#include <ctype.h>

#define SIZE 20
char stack[SIZE];
int top_index = -1;

void push(char x);
char pop();
int priority(char op);

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
    char x, infix[20];
    printf("Enter Infix Expression: ");
    scanf("%s", &infix);
    char *ptr = infix;

    printf("\nPostfix Expression: ");
    while (*ptr != '\0')
    {
        // if char is alpha-numeric, print it as postfix expression
        if (isalnum(*ptr))
            printf("%c", *ptr);
        // if char is (, push it into stack
        else if (*ptr == '(')
            push('(');
        // if char is ), pop and print until ( encounters
        else if (*ptr == ')')
        {
            while (x = pop() != '(')
                printf("%c", x);
        }
        // else char must be operator, so, check its priority
        else
        {
            // pop and print until operator precedence becomes higher than stack top priority
            while (priority(stack[top_index]) >= priority(*ptr))
                printf("%c", pop());
            // now, operator precedence is higher, so push it into stack
            push(*ptr);
        }
        ptr++; // increment for next iteration
    }
    // pop and print all the remaining chars of stack
    while (top_index != -1)
        printf("%c", pop());

    return 0;
}

void push(char x)
{
    stack[++top_index] = x;
}
char pop()
{
    return stack[top_index--];
}
int priority(char op)
{
    if (op == '/' || op == '*')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
}