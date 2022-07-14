#include<stdio.h>

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
		printf("\n\t\tStack Underflow\n");
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

	int i=0, j=0, wrong=0;
	char str[100], postfix[100]={}, temp2;

	printf("Enter any Infix Expression: ");
	gets(str);

	while(str[i] != '\0')
	{
		if(str[i] == '(' || str[i] == '^')
		{
			push(str[i]);
		}

		else if(str[i] == '*' || str[i] == '/')
		{
			do
			{
				if(stack1.top != -1)
				{
					temp2 = pop();

					if(temp2 == '^' || temp2 == '*' || temp2 == '/')
					{
						postfix[j] = temp2;
						j++;
					}

					else
					{
						push(temp2);
						push(str[i]);
						break;
					}
				}

				else
				{
					push(str[i]);
					break;
				}

			}while(temp2 == '^' || temp2 == '*' || temp2 == '/');
		}

		else if(str[i] == '+' || str[i] == '-')
		{
			do
			{
				if(stack1.top != -1)
				{
					temp2 = pop();

					if(temp2 == '^' || temp2 == '*' || temp2 == '/' || temp2 == '+' || temp2 == '-')
					{
						postfix[j] = temp2;
						j++;
					}

					else
					{
						push(temp2);
						push(str[i]);
						break;
					}
				}

				else
				{
					push(str[i]);
					break;
				}

			}while(temp2 == '^' || temp2 == '*' || temp2 == '/' || temp2 == '+' || temp2 == '-');
		}

		else if(str[i] == ')')
		{
			wrong=1;

			do
			{
				temp2 = pop();

				if(temp2 == '(')
				{
					wrong=0;
					break;
				}

				else
				{
					postfix[j] = temp2;
					j++;
				}

			}while(stack1.top != -1);
		}

		else
		{
			postfix[j] = str[i];
			j++;
		}

		i++;
	}

	while(stack1.top != -1)
	{
		temp2 = pop();
		postfix[j] = temp2;
		j++;
	}

	if(wrong == 0)
	{
		printf("\nYour postfix expression is: ");
		puts(postfix);
	}
	else
		printf("\nError in your expression!");

	return 0;
}
