# include <stdio.h>
# include <string.h>
# define MAX 20
void ifixtopfix(char ifix[20], char pfix[20]);
void reverse(char array[30]);
char pop();
void push(char symbol);
int isOperator(char symbol);
int prcd(char symbol);
int top = -1;
char stack[MAX];

int main()
{
    char ifix[20], pfix[20], temp;
    printf("Enter infix operation: ");
    gets(ifix);
    ifixtopfix(ifix, pfix);
    reverse(pfix);
    puts((pfix));
}
//--------------------------------------------------------
void ifixtopfix(char ifix[20], char pfix[20])
{
    int i, j = 0;
    char symbol;
    stack[++top] = '#';
    reverse(ifix);
    for (i = 0; i < strlen(ifix); i++)
    {
            symbol = ifix[i];
            if (isOperator(symbol) == 0)
            {
                pfix[j] = symbol;
                j++;
            }
            else
            {
                if (symbol == ')')
                {
                    push(symbol);
                }
                else if (symbol == '(')
                {
                    while (stack[top] != ')')
                    {
                        pfix[j] = pop();
                        j++;
                    }
                    pop();
                }
                else
                {
                    if (prcd(stack[top]) <= prcd(symbol))
                    {
                        push(symbol);
                    }
                    else
                    {
                        while (prcd(stack[top]) >= prcd(symbol))
                        {
                            pfix[j] = pop();
                            j++;
                        }
                        push(symbol);
                    }
                }
            }
       }
    while(stack[top] != '#')
    {
        pfix[j] = pop();
        j++;
    }
    pfix[j] = '\0';
}
////--------------------------------------------------------
void reverse(char array[30])
{
    int i, j;
    char temp[100];
    for(i=strlen(array)-1,j=0;i+1!=0;--i,++j)
        {
            temp[j] = array[i];
        }
    temp[j] = '\0';
    strcpy(array, temp);
}
 //--------------------------------
char pop()
{
    char a;
    a = stack[top];
    top--;
    return a;
}
 //----------------------------------
void push(char symbol)
{
    top++;
    stack[top] = symbol;
}
 //------------------------------------------
int prcd(char symbol)
{
    switch (symbol)
    {
        case '+':
        case '-':
            return 2;
            break;
        case '*':
        case '/':
            return 4;
            break;
        case '$':
        case '^':
            return 6;
            break;
        case '#':
        case '(':
        case ')':
            return 1;
            break;
    }
}
//-------------------------------------------------
int isOperator(char symbol)
{
    switch (symbol)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '$':
        case '&':
        case '(':
        case ')':
          return 1;
          break;
        default:
          return 0;
      }
}
