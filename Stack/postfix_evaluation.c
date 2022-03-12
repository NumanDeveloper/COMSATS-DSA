/*
Source: geeksforgeeks.com
Stack | Set 4 (Evaluation of Postfix Expression)
Difficulty Level : Easy
Last Updated : 14 Jan, 2022

The Postfix notation is used to represent algebraic expressions. The expressions written in postfix form are evaluated faster compared to infix notation as parenthesis are not required in postfix. We have discussed infix to postfix conversion. In this post, evaluation of postfix expressions is discussed.

Following is an algorithm for evaluation postfix expressions.
1) Create a stack to store operands (or values).
2) Scan the given expression and do the following for every scanned element.
…..a) If the element is a number, push it into the stack
…..b) If the element is an operator, pop operands for the operator from the stack. Evaluate the operator and push the result back to the stack
3) When the expression is ended, the number in the stack is the final answer


Example:
Let the given expression be “2 3 1 * + 9 -“. We scan all elements one by one.
1) Scan ‘2’, it’s a number, so push it to stack. Stack contains ‘2’
2) Scan ‘3’, again a number, push it to stack, stack now contains ‘2 3’ (from bottom to top)
3) Scan ‘1’, again a number, push it to stack, stack now contains ‘2 3 1’
4) Scan ‘*’, it’s an operator, pop two operands from stack, apply the * operator on operands, we get 3*1 which results in 3. We push the result ‘3’ to stack. The stack now becomes ‘2 3’.
5) Scan ‘+’, it’s an operator, pop two operands from stack, apply the + operator on operands, we get 3 + 2 which results in 5. We push the result ‘5’ to stack. The stack now becomes ‘5’.
6) Scan ‘9’, it’s a number, we push it to the stack. The stack now becomes ‘5 9’.
7) Scan ‘-‘, it’s an operator, pop two operands from stack, apply the – operator on operands, we get 5 – 9 which results in -4. We push the result ‘-4’ to the stack. The stack now becomes ‘-4’.
8) There are no more elements to scan, we return the top element from the stack (which is the only element left in a stack).
*/

#include <stdio.h>
#include <math.h>
#define MAX_SIZE 20

char stack[MAX_SIZE];
int top = -1;
void push(int n)
{
    stack[++top] = n;
}
char pop()
{
    return stack[top--];
}
int main()
{
    char postfix[MAX_SIZE];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    int i = 0, op1 = 0, op2 = 0, result = 0, error = 0;
    // scan/traverse the whole postfix expression
    while (postfix[i] != '\0')
    {
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
        {
            // when operator encounters, min 2 digits must be in stack
            if (top < 1)
            {
                error = 1;
                printf("ERROR!");
                break;
            }
            else
            {
                // conversion from char to int
                // ASCII value of 0 is 48
                op2 = pop() - 48;
                op1 = pop() - 48;

                switch (postfix[i])
                {
                case '+':
                    result = (op1 + op2);
                    break;
                case '-':
                    result = (op1 - op2);
                    break;
                case '*':
                    result = (op1 * op2);
                    break;
                case '/':
                    result = (op1 / op2);
                    break;
                case '^':
                    result = pow(op1, op2);
                    break;
                default:
                    printf("INVALID OPERATOR!");
                }
                // now push the result into stack
                push(result);
            }
        }
        else
        {
            // if postfix[i] is not an operator, it must be an integer, so push it into stack
            push(postfix[i]);
        }
        i++; // increment for next iteration
    }        // while loop ends here

    if (top == 0 && error == 0)
        // the stack must have one element as answer, so pop that as result 
        printf("Result: %d", pop());
    else
        printf("ERROR in your expression!");

    return 0;
}