#include<stdio.h>
#define max 100
struct stack
{
    int array[max];
    int top;
}s1;

void push(char val);
char pop();
int main()
{
    int i=0;
    char ch,val;
    char user[max]={0};
    printf("Enter the expression in infix format: ");
    gets(user);
    printf("\n Exp in infix Format : ");
    for(i=0;i<max;i++)
    {
        printf("%c",user[i]);
    }
    while ((ch=user[i])!='\0')
    {
        switch(ch)
        {
            case '+':
                {
                    push(ch);
                    break;
                }
            case '-':
                {
                    push(ch);
                    break;
                }
            case '*':
                {
                    push(ch);
                    break;
                }
            case '/':
                {
                    push(ch);
                    break;
                }
            case '%':
                {
                    push(ch);
                    break;
                }
            case '^':
                {
                    push(ch);
                    break;
                }
            case '(':
                {
                    push(ch);
                    break;
                }
            case ')':
                {
                    while(s1.array[s1.top]!='('){
                        pop();}
                    break;
                }
            case '[':
                {
                    push(ch);
                    break;
                }
            case ']':
                {
                    while(s1.array[s1.top]!='['){
                        pop();}
                    break;
                }
            case '{':
                {
                    push(ch);
                    break;
                }
            case '}':
                {
                    while(s1.array[s1.top]!='{'){
                        pop();}
                    break;
                }
            }
        i++;
    }
/*    printf("\n Given Expression : ");
    for(i=0;i<=s1.top;i++)
    {
        printf("%c",s1.array[i]);
    }*/
    printf("\nThe given expression in Prefix format is : ");
    for(i=s1.top;i>-1;i--)
    {
        printf("%c",s1.array[i]);
    }

 /*   i=0;
    while((val=user[i])!='\0')
    {
        if(val=='+' || val=='-' || val=='*'||val=='/'||val=='%'||val=='^'/*||val=='('||val==')')
        {
             if(val=='*' || val=='/')
            {
                pri=pop();
                user[i]=pri;
                push(pri);
                i++;
            }
            else if(val=='+' || val=='-')
            {
                pri=pop();
                user[i]=pri;
                push(pri);
                i++;
            }
            else
                pop();
        }
            pop();
        }
        else
        {
            printf("%c",user[i]);

        }
        i++;
    }
    printf("\n\n");*/
}

void push(char val)
{
    if(s1.top==max-1)
        printf("The stack is full\n");
    else
    {
        s1.top++;
        s1.array[s1.top]=val;
    }
}
char pop()
{
    char val;
    if(s1.top==-1)
        printf("The stack is empty");
    else
    {
        val = s1.array[s1.top];
        s1.top--;
    }
    return val;
}
