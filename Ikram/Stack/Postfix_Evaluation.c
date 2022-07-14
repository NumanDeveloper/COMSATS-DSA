#include<stdio.h>
#include<math.h>

struct Stack
{
	char stack[100];
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
		stack1.stack[stack1.top] = value;
	}
}

char pop()
{
	char temp;

	if(stack1.top == -1)
	{
		printf("\n\t\tStack Underfow!\n");
	}

	else
	{
		temp = stack1.stack[stack1.top];
		stack1.top--;
	}

	return temp;
}

int main()
{
	stack1.top = -1;

	int i=0, num1=0, num2=0, result=0, error=0;
	char str[100];

	printf("Enter any postfix expression: ");
	gets(str);

	while(str[i] != '\0')
	{
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
		{
			if(stack1.top < 1)
			{
				error=1;
				printf("\nERROR!\n");
				break;
			}

			else
			{
				num2 = pop() - 48;
				num1 = pop() - 48;

				switch(str[i])
				{
					case '+':
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
			push(str[i]);
		}

		i++;
	}

	if(stack1.top == 0 && error == 0)
	{
		result = pop() - 48;
		printf("\nYour result = %d", result);
	}
	else
		printf("\nError in your expression!");

	return 0;
}
