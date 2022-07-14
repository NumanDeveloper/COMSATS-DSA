#include<stdio.h>
#include<math.h>
#define max 100

struct stack{

char array[100];
int top;

}stack1;

void push(char value)
{
	if(stack1.top == 99)
	{
		printf("\n\t\tStack Overflow!\n");
	}

	else
	{
		stack1.top++;
		stack1.array[stack1.top] = value;
	}
}
char pop()
{
    char temp;
    if(stack1.top==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        temp=stack1.array[stack1.top];
        stack1.top--;
    }
    return temp;
}
int main()
{
    stack1.top = -1;
    char array1[max];
    int num1=0,num2=0,i=0,result=0,error=0;
    printf("Enter any Expression\n");
    gets(array1);

    while(array1[i] != '\0')
    {
        if(array1[i]=='+'||array1[i]=='-'||array1[i]=='*'||array1[i]=='/'||array1[i]=='^')
        {
			// it means no digit is inserted into stack till now 
			if(stack1.top < 1)
			{
				error=1;
				printf("\nERROR!\n");
				break;
			}

			else
			{
				// convertion from char to int
				// ASCII value of 0 is 48
				num2 = pop() - 48;
				num1 = pop() - 48;

				switch(array1[i])
				{
					case '+':
						// convertion from int to char again
						result = (num1 + num2) + 48;
						break;

					case '-':
						result = (num1 - num2) + 48;
						break;

					case '*':
						result = (num1 * num2) + 48;
						break;

					case '/':
						result = (num1 / num2) + 48;
						break;

					case '^':
						result = pow(num1, num2) + 48;
						break;

					default:
						printf("\nIncorrect operator!");
						break;
				}
				push(result);
			}
        }
        else
        {
            push(array1[i]);
        }
        i++; // increment for next iteration
    } // while loop ended here
	
    if(stack1.top == 0 && error == 0)
	{
		result = pop() - 48;
		printf("\nYour result = %d", result);
	}

	else
		printf("\nError in your expression!");

	return 0;
}
