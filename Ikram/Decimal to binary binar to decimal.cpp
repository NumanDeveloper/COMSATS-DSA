#include <stdio.h>
#include <math.h>

int a[10];
int num;

void decimal_to_binary();
void binary_to_decimal();

int main()
{
	int selection;
	for (;;)
	{
		printf("1)---Decimal to Binary---\n2)---Binary to Decimal---\n");
		scanf("%d", &selection);
		switch (selection)
		{
		case 1:
			decimal_to_binary();
			break;
		case 2:
			binary_to_decimal();
			break;
		}
	}
}

void decimal_to_binary()
{
	int i = 0, c = 0;
	printf("---Enter Decimal Number---\n");
	scanf("%d", &num);
	for (i = 0; num >= 2; i++)
	{
		a[i] = num % 2;
		num = num / 2;
		c++;
	}
	a[i] = num % 2;
	c++;
	for (i = c - 1; i >= 0; i--)
		printf("%d", a[i]);
	printf("\n");
}

void binary_to_decimal()
{
	int i = 0, c = 0;
	printf("---Enter Binary Number---\n");
	scanf("%d", &num);
	for (i = 0; num > 0; i++)
	{
		a[i] = num % 10;
		num = num / 10;
		c++;
	}
	num = 0;
	for (i = 0; i < c; i++)
		num += a[i] * pow(2, i);
	printf("\n%d", num);
	printf("\n");
}
