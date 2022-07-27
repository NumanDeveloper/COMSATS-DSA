#include<stdio.h>
#define max 5

void push();
int top=-1;
char stack[max];
int main()
{
        printf("\n\t 1. Push ");
        push() ;
}
void push()
{
    char num,i;
    int a=0,b=0,c=0;
    if(top==max-1)
    {
        printf("\n Stack is Full!!!");
    }
    else
    {
        printf("\n Enter the number : ");
        for(i=0;i<max;i++)
        {
            scanf("%c",&num);
            switch(num)
            {
            case '[':
                {
                    top++;
                    stack[top];
                    break;
                }
            case '{':
                {
                    top++;
                    stack[top];
                    break;
                }
            case '(':
                {
                    top++;
                    stack[top];
                    break;
                }
            case ']':
                {
                    if(stack[top]==']')
                    {
                        top--;
                    }
                break;
                }
            case '}':
                {
                    if(stack[top]=='}')
                    {
                        top--;
                    }
                break;
                }
            case ')':
                {
                    if(stack[top]==')')
                    {
                        top--;
                    }
                break;
                }

            }
        }
        if (top==-1)
                {
                    printf("\nbalanced expr!!");
                }
                else
                {
                    printf("\nstring is not valid.!!");
                }
    }
}
